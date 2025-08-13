#ifndef _THP_THPPLAYER_H
#define _THP_THPPLAYER_H

#include "common.h"
#include "rvl/DVD/dvd.h"
#include "rvl/GX/GXFrameBuf.h"

#include <THPPlayer/THPBuffer.h>
#include <THPPlayer/THPFile.h>
#include <THPPlayer/THPInfo.h>

#ifdef __cplusplus
extern "C" {
#endif

#define THP_AUDIO_BUFFER_COUNT 3
#define THP_READ_BUFFER_COUNT  10
#define THP_TEXTURE_SET_COUNT  3

typedef struct THPPlayer {
	DVDFileInfo fileInfo;
	THPHeader header;
	THPFrameCompInfo compInfo;
	THPVideoInfo videoInfo;
	THPAudioInfo audioInfo;
	void* thpWork;
	BOOL open;
	u8 state;
	u8 internalState;
	u8 playFlag;
	u8 audioExist;
	s32 dvdError;
	s32 videoError;
	BOOL onMemory;
	u8* movieData;
	s32 initOffset;
	s32 initReadSize;
	s32 initReadFrame;
	u32 curField;
	s64 retaceCount;
	s32 prevCount;
	s32 curCount;
	s32 videoDecodeCount;
	f32 curVolume;
	f32 targetVolume;
	f32 deltaVolume;
	s32 rampCount;
	s32 curAudioTrack;
	s32 curVideoNumber;
	s32 curAudioNumber;
	THPTextureSet* dispTextureSet;
	THPAudioBuffer* playAudioBuffer;
	THPReadBuffer readBuffer[10];
	THPTextureSet textureSet[THP_TEXTURE_SET_COUNT];
	THPAudioBuffer audioBuffer[THP_AUDIO_BUFFER_COUNT];
} THPPlayer; // Size: 0x1d0

extern THPPlayer ActivePlayer;

BOOL THPPlayerInit(s32);
void THPPlayerQuit();
BOOL THPPlayerOpen(const char* fileName, BOOL onMemory);
BOOL THPPlayerClose();
BOOL THPPlayerPlay();
void THPPlayerStop();
BOOL THPPlayerPause();
BOOL THPPlayerPrepare(s32 offset, u8 flag, s32 audioTrack);

BOOL THPPlayerSetBuffer(u8* data);

u32 THPPlayerCalcNeedMemory();

BOOL THPPlayerGetVideoInfo(THPVideoInfo* videoInfo);
BOOL THPPlayerGetAudioInfo(THPAudioInfo* audioInfo);
// f32 THPPlayerGetFrameRate();
BOOL THPPlayerSetVolume(s32 vol, s32 duration);

s32 THPPlayerDrawCurrentFrame(u16, u16, u32, u32, u32, u32);
u32 THPPlayerGetTotalFrame();
s32 THPPlayerGetState();
void THPPlayerDrawDone();

void THPPlayerPostDrawDone();

#ifdef __cplusplus
}
#endif

void PrepareReady(int msg);

#endif
