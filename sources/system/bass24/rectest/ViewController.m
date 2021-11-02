/*
	BASS recording example
	Copyright (c) 2002-2021 Un4seen Developments Ltd.
*/

#import "ViewController.h"
#include "bass.h"

@implementation ViewController

#define BUFSTEP 1000000	// memory allocation unit

int input;				// current input source
int freq, chans;		// sample format
BYTE *recbuf;			// recording buffer
DWORD reclen;			// recording length
HRECORD rchan;			// recording channel
HSTREAM pchan;			// playback channel

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

BOOL32 CALLBACK RecordingCallback(HRECORD handle, const void *buffer, DWORD length, void *user)
{
	// increase buffer size if needed
	if ((reclen % BUFSTEP) + length >= BUFSTEP) {
		void *p = realloc(recbuf, ((reclen + length) / BUFSTEP + 1) * BUFSTEP);
		if (!p) {
			rchan = 0;
			free(recbuf);
			recbuf = NULL;
			Error(@"Out of memory!");
			dispatch_async(dispatch_get_main_queue(), ^{
				ViewController *view=(ViewController*)[NSApplication sharedApplication].keyWindow.contentViewController;
				view.recordButton.title = @"Record";
				[view.formatSelector setEnabled:true];
			});
			return FALSE; // stop recording
		}
		recbuf = (BYTE*)p;
	}
	// buffer the data
	memcpy(recbuf + reclen, buffer, length);
	reclen += length;
	return TRUE; // continue recording
}

- (void)Start {
	if (pchan) { // free old recording
		BASS_StreamFree(pchan);
		pchan = 0;
		free(recbuf);
		recbuf = NULL;
		[self.playButton setEnabled:false];
		[self.saveButton setEnabled:false];
	}
	{ // get selected sample format
		int format = (int)self.formatSelector.indexOfSelectedItem;
		freq = format > 3 ? 22050 : format > 1 ? 44100 : 48000;
		chans = 1 + (format & 1);
	}
	// allocate initial buffer and make space for WAVE header
	recbuf = (BYTE*)malloc(BUFSTEP);
	reclen = 44;
	// fill the WAVE header
	memcpy(recbuf, "RIFF\0\0\0\0WAVEfmt \20\0\0\0", 20);
	memcpy(recbuf + 36, "data\0\0\0\0", 8);
	WAVEFORMATEX *wf = (WAVEFORMATEX*)(recbuf + 20);
	wf->wFormatTag = 1;
	wf->nChannels = chans;
	wf->wBitsPerSample = 16;
	wf->nSamplesPerSec = freq;
	wf->nBlockAlign = wf->nChannels * wf->wBitsPerSample / 8;
	wf->nAvgBytesPerSec = wf->nSamplesPerSec * wf->nBlockAlign;
	// start recording
	rchan = BASS_RecordStart(freq, chans, 0, RecordingCallback, 0);
	if (!rchan) {
		Error(@"Can't start recording");
		free(recbuf);
		recbuf = 0;
		return;
	}

	self.recordButton.title = @"Stop";
	[self.formatSelector setEnabled:false];
}

- (void)Stop {
	BASS_ChannelStop(rchan);
	rchan = 0;
	// complete the WAVE header
	*(DWORD*)(recbuf + 4) = reclen - 8;
	*(DWORD*)(recbuf + 40) = reclen - 44;
	// enable "save" button
	[self.saveButton setEnabled:true];
	// create a stream from the recording
	if (pchan = BASS_StreamCreateFile(TRUE, recbuf, 0, reclen, 0))
		[self.playButton setEnabled:true];
	self.recordButton.title = @"Record";
	[self.formatSelector setEnabled:true];
}

- (void)WriteToDisk {
	NSSavePanel *panel=[NSSavePanel savePanel];
	[panel setAllowedFileTypes:[NSArray arrayWithObjects:@"wav", nil]];
	if ([panel runModal] == NSModalResponseOK) {
		NSString *file=[panel filename];
		FILE *fp;
		if (!(fp = fopen([file UTF8String], "wb"))) {
			Error(@"Can't create the file");
			return;
		}
		fwrite(recbuf, reclen, 1, fp);
		fclose(fp);
	}
}
- (IBAction)startRecording:(id)sender {
	if (!rchan)
		[self Start];
	else
		[self Stop];
}

- (IBAction)startPlaying:(id)sender {
	BASS_ChannelPlay(pchan, TRUE); // play the recorded data
}

- (IBAction)saveRecording:(id)sender {
	[self WriteToDisk];
}

- (IBAction)changeDevice:(id)sender {
	// device selection changed
	int i = (int)[sender indexOfSelectedItem]; // get the selection
	if (rchan) rchan = 1; // special handle (real handles always have highest bit set) to prevent timer ending the recording
	// initialize the selected device
	if ([self InitDevice:i]) {
		if (rchan) { // continue recording on the new device...
			HRECORD newrchan = BASS_RecordStart(freq, chans, 0, RecordingCallback, 0);
			if (!newrchan) {
				Error(@"Can't start recording");
				return;
			}
			rchan = newrchan;
		}
	}
}

- (IBAction)changeInput:(id)sender {
	int i;
	input = (int)[sender indexOfSelectedItem]; // get the selection
	// enable the selected input
	for (i = 0; BASS_RecordSetInput(i, BASS_INPUT_OFF, -1); i++); // 1st disable all inputs, then...
	BASS_RecordSetInput(input, BASS_INPUT_ON, -1); // enable the selected
	[self UpdateInputInfo]; // update info
}

- (IBAction)changeVolume:(id)sender {
	double level = [sender doubleValue] / 100;
	if (!BASS_RecordSetInput(input, 0, level)) // failed to set input level
		BASS_RecordSetInput(-1, 0, level); // try master level instead
}

- (void)TimerProc:(NSTimer*)timer {
	// update the level display
	float level = 0;
	if (rchan || pchan) {
		BASS_ChannelGetLevelEx(rchan ? rchan : pchan, &level, 0.1, BASS_LEVEL_MONO); // get current level
		if (level > 0) {
			level = 1 + log10(level) * 20 / 30; // convert to dB (30dB range)
			if (level < 0) level = 0;
		}
	}
	self.levelIndicator.doubleValue = level;
	// update the recording/playback counter
	char text[30] = "";
	if (rchan) { // recording
		if (rchan != 1 && !BASS_ChannelIsActive(rchan)) { // the recording has stopped, eg. unplugged device
			[self Stop];
			Error(@"The recording stopped");
		} else
			sprintf(text, "%d", reclen - 44);
	} else if (pchan) {
		if (BASS_ChannelIsActive(pchan)) // playing
			sprintf(text, "%lld / %lld", BASS_ChannelGetPosition(pchan, BASS_POS_BYTE), BASS_ChannelGetLength(pchan, BASS_POS_BYTE));
		else
			sprintf(text, "%lld", BASS_ChannelGetLength(pchan, BASS_POS_BYTE));
	}
	self.positionText.stringValue=[NSString stringWithUTF8String:text];
}

- (void)UpdateInputInfo {
	float level;
	int it = BASS_RecordGetInput(input, &level); // get info on the input
	if (it == -1 || level < 0) { // failed to get level
		it = BASS_RecordGetInput(-1, &level); // try master input instead
		if (it == -1 || level < 0) { // that failed too
			level = 1; // just display 100%
			[self.volumeSlider setEnabled:false];
		} else
			[self.volumeSlider setEnabled:true];
	} else
		[self.volumeSlider setEnabled:true];
	self.volumeSlider.doubleValue = level * 100; // set the level slider
}

- (BOOL)InitDevice:(int)device {
	BASS_RecordFree(); // free current device (and recording channel) if there is one
	// initalize new device
	if (!BASS_RecordInit(device)) {
		Error(@"Can't initialize recording device");
		return FALSE;
	}
	{ // get list of inputs
		int c;
		const char *name;
		[self.inputSelector removeAllItems];
		for (c = 0; name = BASS_RecordGetInputName(c); c++) {
			[self.inputSelector addItemWithTitle:[NSString stringWithUTF8String:name]];
			if (!(BASS_RecordGetInput(c, NULL) & BASS_INPUT_OFF)) { // this one is currently "on"
				input = c;
				[self.inputSelector selectItemAtIndex:c];
			}
		}
		if (!c && (name = BASS_RecordGetInputName(-1))) {
			[self.inputSelector addItemWithTitle:[NSString stringWithUTF8String:name]];
			[self.inputSelector selectItemAtIndex:0];
		}
		[self UpdateInputInfo]; // display info
	}
	return TRUE;
}


- (void)viewDidLoad {
	[super viewDidLoad];

	// check the correct BASS was loaded
	if (HIWORD(BASS_GetVersion()) != BASSVERSION) {
		Error(@"An incorrect version of BASS was loaded");
		exit(0);
	}

	// initialize default output device
	if (!BASS_Init(-1, 48000, 0, NULL, NULL))
		Error(@"Can't initialize output device");

	{ // get list of recording devices
		int c, def = 0;
		BASS_DEVICEINFO di;
		for (c = 0; BASS_RecordGetDeviceInfo(c, &di); c++) {
			[self.deviceSelector addItemWithTitle:[NSString stringWithUTF8String:di.name]];
			if (di.flags & BASS_DEVICE_DEFAULT) { // got the default device
				[self.deviceSelector selectItemAtIndex:c];
				def = c;
			}
		}
		[self InitDevice:def]; // initialize default recording device
	}

	// timer to update the level and position displays
	[[NSRunLoop currentRunLoop] addTimer:[NSTimer timerWithTimeInterval:0.1 target:self selector:@selector(TimerProc:) userInfo:nil repeats:YES] forMode:NSRunLoopCommonModes];
}

@end
