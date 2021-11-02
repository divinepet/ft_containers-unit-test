/*
	BASS console WAV writer
	Copyright (c) 2002-2021 Un4seen Developments Ltd.
*/

#include <stdlib.h>
#include <stdio.h>
#include "bass.h"

#ifdef _WIN32 // Windows
#include <conio.h>
#else // OSX
#include <sys/types.h>
#include <sys/time.h>
#include <termios.h>
#include <string.h>
#include <glob.h>

int _kbhit()
{
	int r;
	fd_set rfds;
	struct timeval tv;
	struct termios term, oterm;
	tcgetattr(0, &oterm);
	memcpy(&term, &oterm, sizeof(term));
	cfmakeraw(&term);
	tcsetattr(0, TCSANOW, &term);
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	tv.tv_sec = tv.tv_usec = 0;
	r = select(1, &rfds, NULL, NULL, &tv);
	tcsetattr(0, TCSANOW, &oterm);
	return r;
}
#endif

#if __BIG_ENDIAN__
inline DWORD le_32(DWORD v)
{
	return (v >> 24) | ((v >> 8) & 0xff00) | ((v & 0xff00) << 8) | (v << 24);
}
inline WORD le_16(WORD v)
{
	return (v >> 8) | (v << 8);
}
#else
#define le_32(v) (v)
#define le_16(v) (v)
#endif

// display error messages
void Error(const char *text)
{
	printf("Error(%d): %s\n", BASS_ErrorGetCode(), text);
	BASS_Free();
	exit(0);
}

int main(int argc, char **argv)
{
	BASS_CHANNELINFO info;
	DWORD chan, p;
	QWORD len, pos;
	FILE *fp;
	WAVEFORMATEX wf;

	printf("BASS WAV writer example\n"
			"-----------------------\n");

	// check the correct BASS was loaded
	if (HIWORD(BASS_GetVersion()) != BASSVERSION) {
		printf("An incorrect version of BASS was loaded");
		return 0;
	}

	if (argc != 2) {
		printf("\tusage: writewav <file>\n");
		return 0;
	}

	// initalize "no sound" device
	if (!BASS_Init(0, 44100, 0, 0, NULL))
		Error("Can't initialize device");

	// load plugins for additional input format support
#ifdef _WIN32
	{
		WIN32_FIND_DATA fd;
		HANDLE fh;
		fh = FindFirstFile("bass*.dll", &fd);
		if (fh != INVALID_HANDLE_VALUE) {
			int c = 0;
			do {
				if (BASS_PluginLoad(fd.cFileName, 0)) {
					if (!c++) printf("plugins:");
					printf(" %s", fd.cFileName);
				}
			} while (FindNextFile(fh, &fd));
			if (c) printf("\n");
			FindClose(fh);
		}
	}
#else
	{
		glob_t g;
#ifdef __APPLE__
		if (!glob("libbass*.dylib", 0, 0, &g)) {
#else
		if (!glob("libbass*.so", 0, 0, &g)) {
#endif
			int a, c = 0;
			for (a = 0; a < g.gl_pathc; a++) {
				if (BASS_PluginLoad(g.gl_pathv[a], 0)) {
					if (!c++) printf("plugins:");
					printf(" %s", g.gl_pathv[a]);
				}
			}
			if (c) printf("\n");
		}
		globfree(&g);
	}
#endif

	if (strstr(argv[1], "://")) {
		// try streaming the URL
		chan = BASS_StreamCreateURL(argv[1], 0, BASS_STREAM_DECODE | BASS_STREAM_BLOCK, 0, 0);
	} else {
		// try streaming the file
		chan = BASS_StreamCreateFile(FALSE, argv[1], 0, 0, BASS_STREAM_DECODE);
		if (!chan && BASS_ErrorGetCode() == BASS_ERROR_FILEFORM) {
			// try MOD music formats
			chan = BASS_MusicLoad(FALSE, argv[1], 0, 0, BASS_MUSIC_DECODE | BASS_MUSIC_RAMPS | BASS_MUSIC_PRESCAN, 0);
		}
	}
	if (!chan) Error("Can't handle the file");

	len = BASS_ChannelGetLength(chan, BASS_POS_BYTE);

	printf("output: bass.wav\n");
	if (!(fp = fopen("bass.wav", "wb"))) Error("Can't create output file");
	// write WAV header
	BASS_ChannelGetInfo(chan, &info);
	wf.wFormatTag = 1;
	wf.nChannels = info.chans;
	wf.wBitsPerSample = (info.flags & BASS_SAMPLE_8BITS ? 8 : 16);
	wf.nBlockAlign = wf.nChannels * wf.wBitsPerSample / 8;
	wf.nSamplesPerSec = info.freq;
	wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;
#if __BIG_ENDIAN__ // swap byte order
	wf.wFormatTag = le_16(wf.wFormatTag);
	wf.nChannels = le_16(wf.nChannels);
	wf.wBitsPerSample = le_16(wf.wBitsPerSample);
	wf.nBlockAlign = le_16(wf.nBlockAlign);
	wf.nSamplesPerSec = le_32(wf.nSamplesPerSec);
	wf.nAvgBytesPerSec = le_32(wf.nAvgBytesPerSec);
#endif
	fwrite("RIFF\0\0\0\0WAVEfmt \20\0\0\0", 20, 1, fp);
	fwrite(&wf, 16, 1, fp);
	fwrite("data\0\0\0\0", 8, 1, fp);

	while (!_kbhit()) {
		short buf[10000];
		int c = BASS_ChannelGetData(chan, buf, sizeof(buf));
		if (c == -1) break;
#if __BIG_ENDIAN__
		if (!(info.flags & BASS_SAMPLE_8BITS)) // swap 16-bit byte order
			for (p = 0; p < c / 2; p++) buf[p] = le_16(buf[p]);
#endif
		fwrite(buf, 1, c, fp);
		pos = BASS_ChannelGetPosition(chan, BASS_POS_BYTE);
		printf(" (press any key to stop)\rdone: %lld / %lld", pos, len);
		fflush(stdout);
	}
	printf("                         \n");

	// complete WAV header
	fflush(fp);
	p = ftell(fp);
	fseek(fp, 4, SEEK_SET);
	putw(le_32(p - 8), fp);
	fflush(fp);
	fseek(fp, 40, SEEK_SET);
	putw(le_32(p - 44), fp);
	fflush(fp);
	fclose(fp);

	BASS_Free();
	return 0;
}
