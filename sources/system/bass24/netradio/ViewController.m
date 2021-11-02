/*
 	BASS internet radio example
 	Copyright (c) 2002-2021 Un4seen Developments Ltd.
*/

#import "ViewController.h"
#import <Foundation/Foundation.h>
#include "bass.h"

// HLS definitions (copied from BASSHLS.H)
#define BASS_SYNC_HLS_SEGMENT	0x10300
#define BASS_TAG_HLS_EXTINF		0x14000

NSObject *lock;
DWORD req;    // request number/counter
HSTREAM chan;    // stream handle

const char *urls[10] = { // preset stream URLs
	"http://stream-dc1.radioparadise.com/rp_192m.ogg", "http://www.radioparadise.com/m3u/mp3-32.m3u",
	"http://somafm.com/secretagent.pls", "http://somafm.com/secretagent32.pls",
	"http://somafm.com/suburbsofgoa.pls", "http://somafm.com/suburbsofgoa32.pls",
	"http://bassdrive.com/bassdrive.m3u", "http://bassdrive.com/bassdrive3.m3u",
	"http://sc6.radiocaroline.net:8040/listen.pls", "http://sc2.radiocaroline.net:8010/listen.pls"
};

@implementation ViewController

// display error messages
void Error(NSString *es)
{
	es = [es stringByAppendingFormat:@"\n(error code: %d)",BASS_ErrorGetCode()];
	if (![NSThread isMainThread]) {
		dispatch_async(dispatch_get_main_queue(), ^{
			NSAlert *alert=[[NSAlert alloc] init];
			[alert setMessageText:es];
			[alert runModal];
		});
	} else {
		NSAlert *alert=[[NSAlert alloc] init];
		[alert setMessageText:es];
		[alert runModal];
	}
}

NSString *String(const char *s)
{
	NSString *r = [NSString stringWithUTF8String:s];
	if (!r) r = [NSString stringWithCString:s encoding:NSISOLatin1StringEncoding];
	if (!r) r = @"";
	return r;
}

// update stream title from metadata
- (void)doMeta
{
	const char *meta=BASS_ChannelGetTags(chan,BASS_TAG_META);
	if (meta) { // got Shoutcast metadata
		char *p=strstr(meta,"StreamTitle='");
		if (p) {
			p=strdup(p+13);
			strchr(p,';')[-1]=0;
			self.statusText1.stringValue=String(p);
			free(p);
		}
	} else {
		meta=BASS_ChannelGetTags(chan,BASS_TAG_OGG);
		if (meta) { // got Icecast/OGG tags
			const char *artist=NULL,*title=NULL,*p=meta;
			for (;*p;p+=strlen(p)+1) {
				if (!strncasecmp(p,"artist=",7)) // found the artist
					artist=p+7;
				if (!strncasecmp(p,"title=",6)) // found the title
					title=p+6;
			}
			if (title) {
				if (artist) {
					char text[100];
					snprintf(text,sizeof(text),"%s - %s",artist,title);
					self.statusText1.stringValue=String(text);
				} else
					self.statusText1.stringValue=String(title);
			}
		} else {
			meta=BASS_ChannelGetTags(chan,BASS_TAG_HLS_EXTINF);
			if (meta) { // got HLS segment info
				const char *p=strchr(meta,',');
				if (p) self.statusText1.stringValue=String(p+1);
			}
		}
	}
}

void CALLBACK MetaSync(HSYNC handle, DWORD channel, DWORD data, void *user)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		ViewController *view=(__bridge ViewController*)user;
		[view doMeta];
	});
}

- (void)monitorBuffering:(NSTimer*)timer
{
	// monitor buffering progress
	DWORD active=BASS_ChannelIsActive(chan);
	if (active==BASS_ACTIVE_STALLED) {
		self.statusText2.stringValue=[NSString stringWithFormat:@"buffering... %d%%",100-(int)BASS_StreamGetFilePosition(chan,BASS_FILEPOS_BUFFERING)];
	} else {
		[timer invalidate]; // finished buffering, stop monitoring
		if (active) {
			self.statusText2.stringValue=@"playing";
			{ // get the stream name and URL
				const char *icy=BASS_ChannelGetTags(chan,BASS_TAG_ICY);
				if (!icy) icy=BASS_ChannelGetTags(chan,BASS_TAG_HTTP); // no ICY tags, try HTTP
				if (icy) {
					for (;*icy;icy+=strlen(icy)+1) {
						if (!strncasecmp(icy,"icy-name:",9))
							self.statusText2.stringValue=String(icy+9);
						if (!strncasecmp(icy,"icy-url:",8))
							self.statusText3.stringValue=String(icy+8);
					}
				}
			}
			// get the stream title
			[self doMeta];
		}
	}
}

void CALLBACK StallSync(HSYNC handle, DWORD channel, DWORD data, void *user)
{
	if (!data) { // stalled
		dispatch_async(dispatch_get_main_queue(), ^{
			// start buffer monitoring
			ViewController *view=(__bridge ViewController*)user;
			NSTimer *buftimer=[NSTimer timerWithTimeInterval:0.05 target:view selector:@selector(monitorBuffering:) userInfo:nil repeats:YES];
			[[NSRunLoop mainRunLoop] addTimer:buftimer forMode:NSRunLoopCommonModes];
		});
	}
}

void CALLBACK EndSync(HSYNC handle, DWORD channel, DWORD data, void *user)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		ViewController *view=(__bridge ViewController*)user;
		view.statusText2.stringValue=@"not playing";
		view.statusText1.stringValue=@"";
		view.statusText3.stringValue=@"";
	});
}

void CALLBACK StatusProc(const void *buffer, DWORD length, void *user)
{
	if (buffer && !length && (DWORD)user==req) { // got HTTP/ICY tags, and this is still the current request
		NSString *status=String(buffer);
		dispatch_async(dispatch_get_main_queue(), ^{
			ViewController *view=(ViewController*)[NSApplication sharedApplication].keyWindow.contentViewController;
			view.statusText2.stringValue=status;
		});
	}
}

- (IBAction)openURL:(id)sender {
	if (self.proxyDirectSwitch.state)
		BASS_SetConfigPtr(BASS_CONFIG_NET_PROXY,NULL); // disable proxy
	else
		BASS_SetConfigPtr(BASS_CONFIG_NET_PROXY,[self.proxyURL.stringValue UTF8String]); // set proxy server
	NSString *url;
	int t = (int)[sender tag];
	if (t<10)
		url=[NSString stringWithUTF8String:urls[t]];
	else
		url=self.customURL.stringValue;
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
		DWORD c,r;
		@synchronized(lock) {
			r=++req; // increment the request counter for this request
		}
		if (chan) BASS_StreamFree(chan); // close old stream
		dispatch_async(dispatch_get_main_queue(), ^{
			self.statusText2.stringValue=@"connecting...";
			self.statusText1.stringValue=@"";
			self.statusText3.stringValue=@"";
		});
		c=BASS_StreamCreateURL([url UTF8String],0,BASS_STREAM_BLOCK|BASS_STREAM_STATUS|BASS_STREAM_AUTOFREE|BASS_SAMPLE_FLOAT,StatusProc,(void*)(intptr_t)r);
		@synchronized(lock) {
			if (r!=req) { // there is a newer request, discard this stream
				if (c) BASS_StreamFree(c);
				return;
			}
			chan=c; // this is now the current stream
		}
		if (!chan) {
			dispatch_async(dispatch_get_main_queue(), ^{
				self.statusText2.stringValue=@"not playing";
			});
			Error(@"Can't play the stream");
		} else {
			// set syncs for stream title updates
			BASS_ChannelSetSync(chan,BASS_SYNC_META,0,MetaSync,(__bridge void*)self); // Shoutcast
			BASS_ChannelSetSync(chan,BASS_SYNC_OGG_CHANGE,0,MetaSync,(__bridge void*)self); // Icecast/OGG
			BASS_ChannelSetSync(chan,BASS_SYNC_HLS_SEGMENT,0,MetaSync,(__bridge void*)self); // HLS
			// set sync for stalling/buffering
			BASS_ChannelSetSync(chan,BASS_SYNC_STALL,0,StallSync,(__bridge void*)self);
			// set sync for end of stream
			BASS_ChannelSetSync(chan,BASS_SYNC_END,0,EndSync,(__bridge void*)self);
			// play it!
			BASS_ChannelPlay(chan,FALSE);
			// start buffer monitoring
			NSTimer *buftimer=[NSTimer timerWithTimeInterval:0.05 target:self selector:@selector(monitorBuffering:) userInfo:nil repeats:YES];
			[[NSRunLoop mainRunLoop] addTimer:buftimer forMode:NSRunLoopCommonModes];
		}
	});
}

- (void)viewDidLoad {
	[super viewDidLoad];

	// check the correct BASS was loaded
	if (HIWORD(BASS_GetVersion())!=BASSVERSION) {
		Error(@"An incorrect version of BASS was loaded");
		exit(0);
		}
    
	// initialize default output device
	if (!BASS_Init(-1,44100,0,NULL,NULL)) {
		Error(@"Can't initialize device");
		exit(0);
	}
    
	BASS_SetConfig(BASS_CONFIG_NET_PLAYLIST,1); // enable playlist processing
    
	BASS_PluginLoad("libbassflac.dylib", 0); // load BASSFLAC (if present) for FLAC support
	BASS_PluginLoad("libbasshls.dylib",0); // load BASSHLS (if present) for HLS support
}

@end
