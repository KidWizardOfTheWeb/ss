#ifndef _THP_THPAUDIODECODE_H
#define _THP_THPAUDIODECODE_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL CreateAudioDecodeThread(s32 prioriy, void*);
void AudioDecodeThreadStart();
void AudioDecodeThreadCancel();

void PushFreeAudioBuffer(void* buf);
void PushDecodedAudioBuffer(void* buf);

void* PopFreeAudioBuffer();
void* PopDecodedAudioBuffer(s32 flags);

#ifdef __cplusplus
}
#endif

#endif
