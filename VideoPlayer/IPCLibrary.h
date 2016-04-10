// IPCLibrary.h

#pragma once

static void						SendVideoDataToRenderer(void* pvData, UINT uiDataSize);
static void						SendPlayEndSignal();
static unsigned __stdcall		VideoStreamPipeCheckThread(void* pParam);