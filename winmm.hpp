#pragma once

#pragma comment(linker, "/EXPORT:unkWinmm1=___unkWinmm1")
#pragma comment(linker, "/EXPORT:mciExecute=___mciExecute")
#pragma comment(linker, "/EXPORT:CloseDriver=___CloseDriver")
#pragma comment(linker, "/EXPORT:DefDriverProc=___DefDriverProc")
#pragma comment(linker, "/EXPORT:DriverCallback=___DriverCallback")
#pragma comment(linker, "/EXPORT:DrvGetModuleHandle=___DrvGetModuleHandle")
#pragma comment(linker, "/EXPORT:GetDriverModuleHandle=___GetDriverModuleHandle")
#pragma comment(linker, "/EXPORT:NotifyCallbackData=___NotifyCallbackData")
#pragma comment(linker, "/EXPORT:OpenDriver=___OpenDriver")
#pragma comment(linker, "/EXPORT:PlaySound=___PlaySound")
#pragma comment(linker, "/EXPORT:PlaySoundA=___PlaySoundA")
#pragma comment(linker, "/EXPORT:PlaySoundW=___PlaySoundW")
#pragma comment(linker, "/EXPORT:SendDriverMessage=___SendDriverMessage")
#pragma comment(linker, "/EXPORT:WOW32DriverCallback=___WOW32DriverCallback")
#pragma comment(linker, "/EXPORT:WOW32ResolveMultiMediaHandle=___WOW32ResolveMultiMediaHandle")
#pragma comment(linker, "/EXPORT:WOWAppExit=___WOWAppExit")
#pragma comment(linker, "/EXPORT:aux32Message=___aux32Message")
#pragma comment(linker, "/EXPORT:auxGetDevCapsA=___auxGetDevCapsA")
#pragma comment(linker, "/EXPORT:auxGetDevCapsW=___auxGetDevCapsW")
#pragma comment(linker, "/EXPORT:auxGetNumDevs=___auxGetNumDevs")
#pragma comment(linker, "/EXPORT:auxGetVolume=___auxGetVolume")
#pragma comment(linker, "/EXPORT:auxOutMessage=___auxOutMessage")
#pragma comment(linker, "/EXPORT:auxSetVolume=___auxSetVolume")
#pragma comment(linker, "/EXPORT:joy32Message=___joy32Message")
#pragma comment(linker, "/EXPORT:joyConfigChanged=___joyConfigChanged")
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=___joyGetDevCapsA")
#pragma comment(linker, "/EXPORT:joyGetDevCapsW=___joyGetDevCapsW")
#pragma comment(linker, "/EXPORT:joyGetNumDevs=___joyGetNumDevs")
#pragma comment(linker, "/EXPORT:joyGetPos=___joyGetPos")
#pragma comment(linker, "/EXPORT:joyGetPosEx=___joyGetPosEx")
#pragma comment(linker, "/EXPORT:joyGetThreshold=___joyGetThreshold")
#pragma comment(linker, "/EXPORT:joyReleaseCapture=___joyReleaseCapture")
#pragma comment(linker, "/EXPORT:joySetCapture=___joySetCapture")
#pragma comment(linker, "/EXPORT:joySetThreshold=___joySetThreshold")
#pragma comment(linker, "/EXPORT:mci32Message=___mci32Message")
#pragma comment(linker, "/EXPORT:mciDriverNotify=___mciDriverNotify")
#pragma comment(linker, "/EXPORT:mciDriverYield=___mciDriverYield")
#pragma comment(linker, "/EXPORT:mciFreeCommandResource=___mciFreeCommandResource")
#pragma comment(linker, "/EXPORT:mciGetCreatorTask=___mciGetCreatorTask")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDA=___mciGetDeviceIDA")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=___mciGetDeviceIDFromElementIDA")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=___mciGetDeviceIDFromElementIDW")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDW=___mciGetDeviceIDW")
#pragma comment(linker, "/EXPORT:mciGetDriverData=___mciGetDriverData")
#pragma comment(linker, "/EXPORT:mciGetErrorStringA=___mciGetErrorStringA")
#pragma comment(linker, "/EXPORT:mciGetErrorStringW=___mciGetErrorStringW")
#pragma comment(linker, "/EXPORT:mciGetYieldProc=___mciGetYieldProc")
#pragma comment(linker, "/EXPORT:mciLoadCommandResource=___mciLoadCommandResource")
#pragma comment(linker, "/EXPORT:mciSendCommandA=___mciSendCommandA")
#pragma comment(linker, "/EXPORT:mciSendCommandW=___mciSendCommandW")
#pragma comment(linker, "/EXPORT:mciSendStringA=___mciSendStringA")
#pragma comment(linker, "/EXPORT:mciSendStringW=___mciSendStringW")
#pragma comment(linker, "/EXPORT:mciSetDriverData=___mciSetDriverData")
#pragma comment(linker, "/EXPORT:mciSetYieldProc=___mciSetYieldProc")
#pragma comment(linker, "/EXPORT:mid32Message=___mid32Message")
#pragma comment(linker, "/EXPORT:midiConnect=___midiConnect")
#pragma comment(linker, "/EXPORT:midiDisconnect=___midiDisconnect")
#pragma comment(linker, "/EXPORT:midiInAddBuffer=___midiInAddBuffer")
#pragma comment(linker, "/EXPORT:midiInClose=___midiInClose")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsA=___midiInGetDevCapsA")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsW=___midiInGetDevCapsW")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextA=___midiInGetErrorTextA")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextW=___midiInGetErrorTextW")
#pragma comment(linker, "/EXPORT:midiInGetID=___midiInGetID")
#pragma comment(linker, "/EXPORT:midiInGetNumDevs=___midiInGetNumDevs")
#pragma comment(linker, "/EXPORT:midiInMessage=___midiInMessage")
#pragma comment(linker, "/EXPORT:midiInOpen=___midiInOpen")
#pragma comment(linker, "/EXPORT:midiInPrepareHeader=___midiInPrepareHeader")
#pragma comment(linker, "/EXPORT:midiInReset=___midiInReset")
#pragma comment(linker, "/EXPORT:midiInStart=___midiInStart")
#pragma comment(linker, "/EXPORT:midiInStop=___midiInStop")
#pragma comment(linker, "/EXPORT:midiInUnprepareHeader=___midiInUnprepareHeader")
#pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=___midiOutCacheDrumPatches")
#pragma comment(linker, "/EXPORT:midiOutCachePatches=___midiOutCachePatches")
#pragma comment(linker, "/EXPORT:midiOutClose=___midiOutClose")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=___midiOutGetDevCapsA")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=___midiOutGetDevCapsW")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=___midiOutGetErrorTextA")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=___midiOutGetErrorTextW")
#pragma comment(linker, "/EXPORT:midiOutGetID=___midiOutGetID")
#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=___midiOutGetNumDevs")
#pragma comment(linker, "/EXPORT:midiOutGetVolume=___midiOutGetVolume")
#pragma comment(linker, "/EXPORT:midiOutLongMsg=___midiOutLongMsg")
#pragma comment(linker, "/EXPORT:midiOutMessage=___midiOutMessage")
#pragma comment(linker, "/EXPORT:midiOutOpen=___midiOutOpen")
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=___midiOutPrepareHeader")
#pragma comment(linker, "/EXPORT:midiOutReset=___midiOutReset")
#pragma comment(linker, "/EXPORT:midiOutSetVolume=___midiOutSetVolume")
#pragma comment(linker, "/EXPORT:midiOutShortMsg=___midiOutShortMsg")
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=___midiOutUnprepareHeader")
#pragma comment(linker, "/EXPORT:midiStreamClose=___midiStreamClose")
#pragma comment(linker, "/EXPORT:midiStreamOpen=___midiStreamOpen")
#pragma comment(linker, "/EXPORT:midiStreamOut=___midiStreamOut")
#pragma comment(linker, "/EXPORT:midiStreamPause=___midiStreamPause")
#pragma comment(linker, "/EXPORT:midiStreamPosition=___midiStreamPosition")
#pragma comment(linker, "/EXPORT:midiStreamProperty=___midiStreamProperty")
#pragma comment(linker, "/EXPORT:midiStreamRestart=___midiStreamRestart")
#pragma comment(linker, "/EXPORT:midiStreamStop=___midiStreamStop")
#pragma comment(linker, "/EXPORT:mixerClose=___mixerClose")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=___mixerGetControlDetailsA")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=___mixerGetControlDetailsW")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsA=___mixerGetDevCapsA")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsW=___mixerGetDevCapsW")
#pragma comment(linker, "/EXPORT:mixerGetID=___mixerGetID")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsA=___mixerGetLineControlsA")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsW=___mixerGetLineControlsW")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoA=___mixerGetLineInfoA")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoW=___mixerGetLineInfoW")
#pragma comment(linker, "/EXPORT:mixerGetNumDevs=___mixerGetNumDevs")
#pragma comment(linker, "/EXPORT:mixerMessage=___mixerMessage")
#pragma comment(linker, "/EXPORT:mixerOpen=___mixerOpen")
#pragma comment(linker, "/EXPORT:mixerSetControlDetails=___mixerSetControlDetails")
#pragma comment(linker, "/EXPORT:mmDrvInstall=___mmDrvInstall")
#pragma comment(linker, "/EXPORT:mmGetCurrentTask=___mmGetCurrentTask")
#pragma comment(linker, "/EXPORT:mmTaskBlock=___mmTaskBlock")
#pragma comment(linker, "/EXPORT:mmTaskCreate=___mmTaskCreate")
#pragma comment(linker, "/EXPORT:mmTaskSignal=___mmTaskSignal")
#pragma comment(linker, "/EXPORT:mmTaskYield=___mmTaskYield")
#pragma comment(linker, "/EXPORT:mmioAdvance=___mmioAdvance")
#pragma comment(linker, "/EXPORT:mmioAscend=___mmioAscend")
#pragma comment(linker, "/EXPORT:mmioClose=___mmioClose")
#pragma comment(linker, "/EXPORT:mmioCreateChunk=___mmioCreateChunk")
#pragma comment(linker, "/EXPORT:mmioDescend=___mmioDescend")
#pragma comment(linker, "/EXPORT:mmioFlush=___mmioFlush")
#pragma comment(linker, "/EXPORT:mmioGetInfo=___mmioGetInfo")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcA=___mmioInstallIOProcA")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcW=___mmioInstallIOProcW")
#pragma comment(linker, "/EXPORT:mmioOpenA=___mmioOpenA")
#pragma comment(linker, "/EXPORT:mmioOpenW=___mmioOpenW")
#pragma comment(linker, "/EXPORT:mmioRead=___mmioRead")
#pragma comment(linker, "/EXPORT:mmioRenameA=___mmioRenameA")
#pragma comment(linker, "/EXPORT:mmioRenameW=___mmioRenameW")
#pragma comment(linker, "/EXPORT:mmioSeek=___mmioSeek")
#pragma comment(linker, "/EXPORT:mmioSendMessage=___mmioSendMessage")
#pragma comment(linker, "/EXPORT:mmioSetBuffer=___mmioSetBuffer")
#pragma comment(linker, "/EXPORT:mmioSetInfo=___mmioSetInfo")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=___mmioStringToFOURCCA")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=___mmioStringToFOURCCW")
#pragma comment(linker, "/EXPORT:mmioWrite=___mmioWrite")
#pragma comment(linker, "/EXPORT:mmsystemGetVersion=___mmsystemGetVersion")
#pragma comment(linker, "/EXPORT:mod32Message=___mod32Message")
#pragma comment(linker, "/EXPORT:mxd32Message=___mxd32Message")
#pragma comment(linker, "/EXPORT:sndPlaySoundA=___sndPlaySoundA")
#pragma comment(linker, "/EXPORT:sndPlaySoundW=___sndPlaySoundW")
#pragma comment(linker, "/EXPORT:tid32Message=___tid32Message")
#pragma comment(linker, "/EXPORT:timeBeginPeriod=___timeBeginPeriod")
#pragma comment(linker, "/EXPORT:timeEndPeriod=___timeEndPeriod")
#pragma comment(linker, "/EXPORT:timeGetDevCaps=___timeGetDevCaps")
#pragma comment(linker, "/EXPORT:timeGetSystemTime=___timeGetSystemTime")
#pragma comment(linker, "/EXPORT:timeGetTime=___timeGetTime")
#pragma comment(linker, "/EXPORT:timeKillEvent=___timeKillEvent")
#pragma comment(linker, "/EXPORT:timeSetEvent=___timeSetEvent")
#pragma comment(linker, "/EXPORT:waveInAddBuffer=___waveInAddBuffer")
#pragma comment(linker, "/EXPORT:waveInClose=___waveInClose")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsA=___waveInGetDevCapsA")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsW=___waveInGetDevCapsW")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextA=___waveInGetErrorTextA")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextW=___waveInGetErrorTextW")
#pragma comment(linker, "/EXPORT:waveInGetID=___waveInGetID")
#pragma comment(linker, "/EXPORT:waveInGetNumDevs=___waveInGetNumDevs")
#pragma comment(linker, "/EXPORT:waveInGetPosition=___waveInGetPosition")
#pragma comment(linker, "/EXPORT:waveInMessage=___waveInMessage")
#pragma comment(linker, "/EXPORT:waveInOpen=___waveInOpen")
#pragma comment(linker, "/EXPORT:waveInPrepareHeader=___waveInPrepareHeader")
#pragma comment(linker, "/EXPORT:waveInReset=___waveInReset")
#pragma comment(linker, "/EXPORT:waveInStart=___waveInStart")
#pragma comment(linker, "/EXPORT:waveInStop=___waveInStop")
#pragma comment(linker, "/EXPORT:waveInUnprepareHeader=___waveInUnprepareHeader")
#pragma comment(linker, "/EXPORT:waveOutBreakLoop=___waveOutBreakLoop")
#pragma comment(linker, "/EXPORT:waveOutClose=___waveOutClose")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=___waveOutGetDevCapsA")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=___waveOutGetDevCapsW")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=___waveOutGetErrorTextA")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=___waveOutGetErrorTextW")
#pragma comment(linker, "/EXPORT:waveOutGetID=___waveOutGetID")
#pragma comment(linker, "/EXPORT:waveOutGetNumDevs=___waveOutGetNumDevs")
#pragma comment(linker, "/EXPORT:waveOutGetPitch=___waveOutGetPitch")
#pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=___waveOutGetPlaybackRate")
#pragma comment(linker, "/EXPORT:waveOutGetPosition=___waveOutGetPosition")
#pragma comment(linker, "/EXPORT:waveOutGetVolume=___waveOutGetVolume")
#pragma comment(linker, "/EXPORT:waveOutMessage=___waveOutMessage")
#pragma comment(linker, "/EXPORT:waveOutOpen=___waveOutOpen")
#pragma comment(linker, "/EXPORT:waveOutPause=___waveOutPause")
#pragma comment(linker, "/EXPORT:waveOutPrepareHeader=___waveOutPrepareHeader")
#pragma comment(linker, "/EXPORT:waveOutReset=___waveOutReset")
#pragma comment(linker, "/EXPORT:waveOutRestart=___waveOutRestart")
#pragma comment(linker, "/EXPORT:waveOutSetPitch=___waveOutSetPitch")
#pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=___waveOutSetPlaybackRate")
#pragma comment(linker, "/EXPORT:waveOutSetVolume=___waveOutSetVolume")
#pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=___waveOutUnprepareHeader")
#pragma comment(linker, "/EXPORT:waveOutWrite=___waveOutWrite")
#pragma comment(linker, "/EXPORT:wid32Message=___wid32Message")
#pragma comment(linker, "/EXPORT:wod32Message=___wod32Message")

HMODULE hDll = nullptr;
#define FUNCADDR(name) FARPROC _##name;
extern "C" {
	FUNCADDR(unkWinmm1)
	FUNCADDR(mciExecute)
	FUNCADDR(CloseDriver)
	FUNCADDR(DefDriverProc)
	FUNCADDR(DriverCallback)
	FUNCADDR(DrvGetModuleHandle)
	FUNCADDR(GetDriverModuleHandle)
	FUNCADDR(NotifyCallbackData)
	FUNCADDR(OpenDriver)
	FUNCADDR(PlaySound)
	FUNCADDR(PlaySoundA)
	FUNCADDR(PlaySoundW)
	FUNCADDR(SendDriverMessage)
	FUNCADDR(WOW32DriverCallback)
	FUNCADDR(WOW32ResolveMultiMediaHandle)
	FUNCADDR(WOWAppExit)
	FUNCADDR(aux32Message)
	FUNCADDR(auxGetDevCapsA)
	FUNCADDR(auxGetDevCapsW)
	FUNCADDR(auxGetNumDevs)
	FUNCADDR(auxGetVolume)
	FUNCADDR(auxOutMessage)
	FUNCADDR(auxSetVolume)
	FUNCADDR(joy32Message)
	FUNCADDR(joyConfigChanged)
	FUNCADDR(joyGetDevCapsA)
	FUNCADDR(joyGetDevCapsW)
	FUNCADDR(joyGetNumDevs)
	FUNCADDR(joyGetPos)
	FUNCADDR(joyGetPosEx)
	FUNCADDR(joyGetThreshold)
	FUNCADDR(joyReleaseCapture)
	FUNCADDR(joySetCapture)
	FUNCADDR(joySetThreshold)
	FUNCADDR(mci32Message)
	FUNCADDR(mciDriverNotify)
	FUNCADDR(mciDriverYield)
	FUNCADDR(mciFreeCommandResource)
	FUNCADDR(mciGetCreatorTask)
	FUNCADDR(mciGetDeviceIDA)
	FUNCADDR(mciGetDeviceIDFromElementIDA)
	FUNCADDR(mciGetDeviceIDFromElementIDW)
	FUNCADDR(mciGetDeviceIDW)
	FUNCADDR(mciGetDriverData)
	FUNCADDR(mciGetErrorStringA)
	FUNCADDR(mciGetErrorStringW)
	FUNCADDR(mciGetYieldProc)
	FUNCADDR(mciLoadCommandResource)
	FUNCADDR(mciSendCommandA)
	FUNCADDR(mciSendCommandW)
	FUNCADDR(mciSendStringA)
	FUNCADDR(mciSendStringW)
	FUNCADDR(mciSetDriverData)
	FUNCADDR(mciSetYieldProc)
	FUNCADDR(mid32Message)
	FUNCADDR(midiConnect)
	FUNCADDR(midiDisconnect)
	FUNCADDR(midiInAddBuffer)
	FUNCADDR(midiInClose)
	FUNCADDR(midiInGetDevCapsA)
	FUNCADDR(midiInGetDevCapsW)
	FUNCADDR(midiInGetErrorTextA)
	FUNCADDR(midiInGetErrorTextW)
	FUNCADDR(midiInGetID)
	FUNCADDR(midiInGetNumDevs)
	FUNCADDR(midiInMessage)
	FUNCADDR(midiInOpen)
	FUNCADDR(midiInPrepareHeader)
	FUNCADDR(midiInReset)
	FUNCADDR(midiInStart)
	FUNCADDR(midiInStop)
	FUNCADDR(midiInUnprepareHeader)
	FUNCADDR(midiOutCacheDrumPatches)
	FUNCADDR(midiOutCachePatches)
	FUNCADDR(midiOutClose)
	FUNCADDR(midiOutGetDevCapsA)
	FUNCADDR(midiOutGetDevCapsW)
	FUNCADDR(midiOutGetErrorTextA)
	FUNCADDR(midiOutGetErrorTextW)
	FUNCADDR(midiOutGetID)
	FUNCADDR(midiOutGetNumDevs)
	FUNCADDR(midiOutGetVolume)
	FUNCADDR(midiOutLongMsg)
	FUNCADDR(midiOutMessage)
	FUNCADDR(midiOutOpen)
	FUNCADDR(midiOutPrepareHeader)
	FUNCADDR(midiOutReset)
	FUNCADDR(midiOutSetVolume)
	FUNCADDR(midiOutShortMsg)
	FUNCADDR(midiOutUnprepareHeader)
	FUNCADDR(midiStreamClose)
	FUNCADDR(midiStreamOpen)
	FUNCADDR(midiStreamOut)
	FUNCADDR(midiStreamPause)
	FUNCADDR(midiStreamPosition)
	FUNCADDR(midiStreamProperty)
	FUNCADDR(midiStreamRestart)
	FUNCADDR(midiStreamStop)
	FUNCADDR(mixerClose)
	FUNCADDR(mixerGetControlDetailsA)
	FUNCADDR(mixerGetControlDetailsW)
	FUNCADDR(mixerGetDevCapsA)
	FUNCADDR(mixerGetDevCapsW)
	FUNCADDR(mixerGetID)
	FUNCADDR(mixerGetLineControlsA)
	FUNCADDR(mixerGetLineControlsW)
	FUNCADDR(mixerGetLineInfoA)
	FUNCADDR(mixerGetLineInfoW)
	FUNCADDR(mixerGetNumDevs)
	FUNCADDR(mixerMessage)
	FUNCADDR(mixerOpen)
	FUNCADDR(mixerSetControlDetails)
	FUNCADDR(mmDrvInstall)
	FUNCADDR(mmGetCurrentTask)
	FUNCADDR(mmTaskBlock)
	FUNCADDR(mmTaskCreate)
	FUNCADDR(mmTaskSignal)
	FUNCADDR(mmTaskYield)
	FUNCADDR(mmioAdvance)
	FUNCADDR(mmioAscend)
	FUNCADDR(mmioClose)
	FUNCADDR(mmioCreateChunk)
	FUNCADDR(mmioDescend)
	FUNCADDR(mmioFlush)
	FUNCADDR(mmioGetInfo)
	FUNCADDR(mmioInstallIOProcA)
	FUNCADDR(mmioInstallIOProcW)
	FUNCADDR(mmioOpenA)
	FUNCADDR(mmioOpenW)
	FUNCADDR(mmioRead)
	FUNCADDR(mmioRenameA)
	FUNCADDR(mmioRenameW)
	FUNCADDR(mmioSeek)
	FUNCADDR(mmioSendMessage)
	FUNCADDR(mmioSetBuffer)
	FUNCADDR(mmioSetInfo)
	FUNCADDR(mmioStringToFOURCCA)
	FUNCADDR(mmioStringToFOURCCW)
	FUNCADDR(mmioWrite)
	FUNCADDR(mmsystemGetVersion)
	FUNCADDR(mod32Message)
	FUNCADDR(mxd32Message)
	FUNCADDR(sndPlaySoundA)
	FUNCADDR(sndPlaySoundW)
	FUNCADDR(tid32Message)
	FUNCADDR(timeBeginPeriod)
	FUNCADDR(timeEndPeriod)
	FUNCADDR(timeGetDevCaps)
	FUNCADDR(timeGetSystemTime)
	FUNCADDR(timeGetTime)
	FUNCADDR(timeKillEvent)
	FUNCADDR(timeSetEvent)
	FUNCADDR(waveInAddBuffer)
	FUNCADDR(waveInClose)
	FUNCADDR(waveInGetDevCapsA)
	FUNCADDR(waveInGetDevCapsW)
	FUNCADDR(waveInGetErrorTextA)
	FUNCADDR(waveInGetErrorTextW)
	FUNCADDR(waveInGetID)
	FUNCADDR(waveInGetNumDevs)
	FUNCADDR(waveInGetPosition)
	FUNCADDR(waveInMessage)
	FUNCADDR(waveInOpen)
	FUNCADDR(waveInPrepareHeader)
	FUNCADDR(waveInReset)
	FUNCADDR(waveInStart)
	FUNCADDR(waveInStop)
	FUNCADDR(waveInUnprepareHeader)
	FUNCADDR(waveOutBreakLoop)
	FUNCADDR(waveOutClose)
	FUNCADDR(waveOutGetDevCapsA)
	FUNCADDR(waveOutGetDevCapsW)
	FUNCADDR(waveOutGetErrorTextA)
	FUNCADDR(waveOutGetErrorTextW)
	FUNCADDR(waveOutGetID)
	FUNCADDR(waveOutGetNumDevs)
	FUNCADDR(waveOutGetPitch)
	FUNCADDR(waveOutGetPlaybackRate)
	FUNCADDR(waveOutGetPosition)
	FUNCADDR(waveOutGetVolume)
	FUNCADDR(waveOutMessage)
	FUNCADDR(waveOutOpen)
	FUNCADDR(waveOutPause)
	FUNCADDR(waveOutPrepareHeader)
	FUNCADDR(waveOutReset)
	FUNCADDR(waveOutRestart)
	FUNCADDR(waveOutSetPitch)
	FUNCADDR(waveOutSetPlaybackRate)
	FUNCADDR(waveOutSetVolume)
	FUNCADDR(waveOutUnprepareHeader)
	FUNCADDR(waveOutWrite)
	FUNCADDR(wid32Message)
	FUNCADDR(wod32Message)
}
#define ALCDECL extern "C"  void __cdecl
//#define FUNC(name) ALCDECL __##name() { __asm jmp _##name }
#define FUNC(name) ALCDECL __##name();

FUNC(unkWinmm1)
FUNC(mciExecute)
FUNC(CloseDriver)
FUNC(DefDriverProc)
FUNC(DriverCallback)
FUNC(DrvGetModuleHandle)
FUNC(GetDriverModuleHandle)
FUNC(NotifyCallbackData)
FUNC(OpenDriver)
FUNC(PlaySound)
FUNC(PlaySoundA)
FUNC(PlaySoundW)
FUNC(SendDriverMessage)
FUNC(WOW32DriverCallback)
FUNC(WOW32ResolveMultiMediaHandle)
FUNC(WOWAppExit)
FUNC(aux32Message)
FUNC(auxGetDevCapsA)
FUNC(auxGetDevCapsW)
FUNC(auxGetNumDevs)
FUNC(auxGetVolume)
FUNC(auxOutMessage)
FUNC(auxSetVolume)
FUNC(joy32Message)
FUNC(joyConfigChanged)
FUNC(joyGetDevCapsA)
FUNC(joyGetDevCapsW)
FUNC(joyGetNumDevs)
FUNC(joyGetPos)
FUNC(joyGetPosEx)
FUNC(joyGetThreshold)
FUNC(joyReleaseCapture)
FUNC(joySetCapture)
FUNC(joySetThreshold)
FUNC(mci32Message)
FUNC(mciDriverNotify)
FUNC(mciDriverYield)
FUNC(mciFreeCommandResource)
FUNC(mciGetCreatorTask)
FUNC(mciGetDeviceIDA)
FUNC(mciGetDeviceIDFromElementIDA)
FUNC(mciGetDeviceIDFromElementIDW)
FUNC(mciGetDeviceIDW)
FUNC(mciGetDriverData)
FUNC(mciGetErrorStringA)
FUNC(mciGetErrorStringW)
FUNC(mciGetYieldProc)
FUNC(mciLoadCommandResource)
FUNC(mciSendCommandA)
FUNC(mciSendCommandW)
FUNC(mciSendStringA)
FUNC(mciSendStringW)
FUNC(mciSetDriverData)
FUNC(mciSetYieldProc)
FUNC(mid32Message)
FUNC(midiConnect)
FUNC(midiDisconnect)
FUNC(midiInAddBuffer)
FUNC(midiInClose)
FUNC(midiInGetDevCapsA)
FUNC(midiInGetDevCapsW)
FUNC(midiInGetErrorTextA)
FUNC(midiInGetErrorTextW)
FUNC(midiInGetID)
FUNC(midiInGetNumDevs)
FUNC(midiInMessage)
FUNC(midiInOpen)
FUNC(midiInPrepareHeader)
FUNC(midiInReset)
FUNC(midiInStart)
FUNC(midiInStop)
FUNC(midiInUnprepareHeader)
FUNC(midiOutCacheDrumPatches)
FUNC(midiOutCachePatches)
FUNC(midiOutClose)
FUNC(midiOutGetDevCapsA)
FUNC(midiOutGetDevCapsW)
FUNC(midiOutGetErrorTextA)
FUNC(midiOutGetErrorTextW)
FUNC(midiOutGetID)
FUNC(midiOutGetNumDevs)
FUNC(midiOutGetVolume)
FUNC(midiOutLongMsg)
FUNC(midiOutMessage)
FUNC(midiOutOpen)
FUNC(midiOutPrepareHeader)
FUNC(midiOutReset)
FUNC(midiOutSetVolume)
FUNC(midiOutShortMsg)
FUNC(midiOutUnprepareHeader)
FUNC(midiStreamClose)
FUNC(midiStreamOpen)
FUNC(midiStreamOut)
FUNC(midiStreamPause)
FUNC(midiStreamPosition)
FUNC(midiStreamProperty)
FUNC(midiStreamRestart)
FUNC(midiStreamStop)
FUNC(mixerClose)
FUNC(mixerGetControlDetailsA)
FUNC(mixerGetControlDetailsW)
FUNC(mixerGetDevCapsA)
FUNC(mixerGetDevCapsW)
FUNC(mixerGetID)
FUNC(mixerGetLineControlsA)
FUNC(mixerGetLineControlsW)
FUNC(mixerGetLineInfoA)
FUNC(mixerGetLineInfoW)
FUNC(mixerGetNumDevs)
FUNC(mixerMessage)
FUNC(mixerOpen)
FUNC(mixerSetControlDetails)
FUNC(mmDrvInstall)
FUNC(mmGetCurrentTask)
FUNC(mmTaskBlock)
FUNC(mmTaskCreate)
FUNC(mmTaskSignal)
FUNC(mmTaskYield)
FUNC(mmioAdvance)
FUNC(mmioAscend)
FUNC(mmioClose)
FUNC(mmioCreateChunk)
FUNC(mmioDescend)
FUNC(mmioFlush)
FUNC(mmioGetInfo)
FUNC(mmioInstallIOProcA)
FUNC(mmioInstallIOProcW)
FUNC(mmioOpenA)
FUNC(mmioOpenW)
FUNC(mmioRead)
FUNC(mmioRenameA)
FUNC(mmioRenameW)
FUNC(mmioSeek)
FUNC(mmioSendMessage)
FUNC(mmioSetBuffer)
FUNC(mmioSetInfo)
FUNC(mmioStringToFOURCCA)
FUNC(mmioStringToFOURCCW)
FUNC(mmioWrite)
FUNC(mmsystemGetVersion)
FUNC(mod32Message)
FUNC(mxd32Message)
FUNC(sndPlaySoundA)
FUNC(sndPlaySoundW)
FUNC(tid32Message)
FUNC(timeBeginPeriod)
FUNC(timeEndPeriod)
FUNC(timeGetDevCaps)
FUNC(timeGetSystemTime)
FUNC(timeGetTime)
FUNC(timeKillEvent)
FUNC(timeSetEvent)
FUNC(waveInAddBuffer)
FUNC(waveInClose)
FUNC(waveInGetDevCapsA)
FUNC(waveInGetDevCapsW)
FUNC(waveInGetErrorTextA)
FUNC(waveInGetErrorTextW)
FUNC(waveInGetID)
FUNC(waveInGetNumDevs)
FUNC(waveInGetPosition)
FUNC(waveInMessage)
FUNC(waveInOpen)
FUNC(waveInPrepareHeader)
FUNC(waveInReset)
FUNC(waveInStart)
FUNC(waveInStop)
FUNC(waveInUnprepareHeader)
FUNC(waveOutBreakLoop)
FUNC(waveOutClose)
FUNC(waveOutGetDevCapsA)
FUNC(waveOutGetDevCapsW)
FUNC(waveOutGetErrorTextA)
FUNC(waveOutGetErrorTextW)
FUNC(waveOutGetID)
FUNC(waveOutGetNumDevs)
FUNC(waveOutGetPitch)
FUNC(waveOutGetPlaybackRate)
FUNC(waveOutGetPosition)
FUNC(waveOutGetVolume)
FUNC(waveOutMessage)
FUNC(waveOutOpen)
FUNC(waveOutPause)
FUNC(waveOutPrepareHeader)
FUNC(waveOutReset)
FUNC(waveOutRestart)
FUNC(waveOutSetPitch)
FUNC(waveOutSetPlaybackRate)
FUNC(waveOutSetVolume)
FUNC(waveOutUnprepareHeader)
FUNC(waveOutWrite)
FUNC(wid32Message)
FUNC(wod32Message)

inline bool LoadDLL()
{
	wchar_t dllPath[MAX_PATH];
	if (GetSystemDirectoryW(dllPath, _ARRAYSIZE(dllPath)) != 0)
	{
		wcscat_s(dllPath, L"\\winmm.dll");
		hDll = LoadLibraryW(dllPath);
		if (hDll)
		{
#define GetAddr(name) _##name = GetProcAddress(hDll, #name);

			_unkWinmm1 = GetProcAddress(hDll, MAKEINTRESOURCEA(2));
			GetAddr(mciExecute);
			GetAddr(CloseDriver);
			GetAddr(DefDriverProc);
			GetAddr(DriverCallback);
			GetAddr(DrvGetModuleHandle);
			GetAddr(GetDriverModuleHandle);
			GetAddr(NotifyCallbackData);
			GetAddr(OpenDriver);
			GetAddr(PlaySound);
			GetAddr(PlaySoundA);
			GetAddr(PlaySoundW);
			GetAddr(SendDriverMessage);
			GetAddr(WOW32DriverCallback);
			GetAddr(WOW32ResolveMultiMediaHandle);
			GetAddr(WOWAppExit);
			GetAddr(aux32Message);
			GetAddr(auxGetDevCapsA);
			GetAddr(auxGetDevCapsW);
			GetAddr(auxGetNumDevs);
			GetAddr(auxGetVolume);
			GetAddr(auxOutMessage);
			GetAddr(auxSetVolume);
			GetAddr(joy32Message);
			GetAddr(joyConfigChanged);
			GetAddr(joyGetDevCapsA);
			GetAddr(joyGetDevCapsW);
			GetAddr(joyGetNumDevs);
			GetAddr(joyGetPos);
			GetAddr(joyGetPosEx);
			GetAddr(joyGetThreshold);
			GetAddr(joyReleaseCapture);
			GetAddr(joySetCapture);
			GetAddr(joySetThreshold);
			GetAddr(mci32Message);
			GetAddr(mciDriverNotify);
			GetAddr(mciDriverYield);
			GetAddr(mciFreeCommandResource);
			GetAddr(mciGetCreatorTask);
			GetAddr(mciGetDeviceIDA);
			GetAddr(mciGetDeviceIDFromElementIDA);
			GetAddr(mciGetDeviceIDFromElementIDW);
			GetAddr(mciGetDeviceIDW);
			GetAddr(mciGetDriverData);
			GetAddr(mciGetErrorStringA);
			GetAddr(mciGetErrorStringW);
			GetAddr(mciGetYieldProc);
			GetAddr(mciLoadCommandResource);
			GetAddr(mciSendCommandA);
			GetAddr(mciSendCommandW);
			GetAddr(mciSendStringA);
			GetAddr(mciSendStringW);
			GetAddr(mciSetDriverData);
			GetAddr(mciSetYieldProc);
			GetAddr(mid32Message);
			GetAddr(midiConnect);
			GetAddr(midiDisconnect);
			GetAddr(midiInAddBuffer);
			GetAddr(midiInClose);
			GetAddr(midiInGetDevCapsA);
			GetAddr(midiInGetDevCapsW);
			GetAddr(midiInGetErrorTextA);
			GetAddr(midiInGetErrorTextW);
			GetAddr(midiInGetID);
			GetAddr(midiInGetNumDevs);
			GetAddr(midiInMessage);
			GetAddr(midiInOpen);
			GetAddr(midiInPrepareHeader);
			GetAddr(midiInReset);
			GetAddr(midiInStart);
			GetAddr(midiInStop);
			GetAddr(midiInUnprepareHeader);
			GetAddr(midiOutCacheDrumPatches);
			GetAddr(midiOutCachePatches);
			GetAddr(midiOutClose);
			GetAddr(midiOutGetDevCapsA);
			GetAddr(midiOutGetDevCapsW);
			GetAddr(midiOutGetErrorTextA);
			GetAddr(midiOutGetErrorTextW);
			GetAddr(midiOutGetID);
			GetAddr(midiOutGetNumDevs);
			GetAddr(midiOutGetVolume);
			GetAddr(midiOutLongMsg);
			GetAddr(midiOutMessage);
			GetAddr(midiOutOpen);
			GetAddr(midiOutPrepareHeader);
			GetAddr(midiOutReset);
			GetAddr(midiOutSetVolume);
			GetAddr(midiOutShortMsg);
			GetAddr(midiOutUnprepareHeader);
			GetAddr(midiStreamClose);
			GetAddr(midiStreamOpen);
			GetAddr(midiStreamOut);
			GetAddr(midiStreamPause);
			GetAddr(midiStreamPosition);
			GetAddr(midiStreamProperty);
			GetAddr(midiStreamRestart);
			GetAddr(midiStreamStop);
			GetAddr(mixerClose);
			GetAddr(mixerGetControlDetailsA);
			GetAddr(mixerGetControlDetailsW);
			GetAddr(mixerGetDevCapsA);
			GetAddr(mixerGetDevCapsW);
			GetAddr(mixerGetID);
			GetAddr(mixerGetLineControlsA);
			GetAddr(mixerGetLineControlsW);
			GetAddr(mixerGetLineInfoA);
			GetAddr(mixerGetLineInfoW);
			GetAddr(mixerGetNumDevs);
			GetAddr(mixerMessage);
			GetAddr(mixerOpen);
			GetAddr(mixerSetControlDetails);
			GetAddr(mmDrvInstall);
			GetAddr(mmGetCurrentTask);
			GetAddr(mmTaskBlock);
			GetAddr(mmTaskCreate);
			GetAddr(mmTaskSignal);
			GetAddr(mmTaskYield);
			GetAddr(mmioAdvance);
			GetAddr(mmioAscend);
			GetAddr(mmioClose);
			GetAddr(mmioCreateChunk);
			GetAddr(mmioDescend);
			GetAddr(mmioFlush);
			GetAddr(mmioGetInfo);
			GetAddr(mmioInstallIOProcA);
			GetAddr(mmioInstallIOProcW);
			GetAddr(mmioOpenA);
			GetAddr(mmioOpenW);
			GetAddr(mmioRead);
			GetAddr(mmioRenameA);
			GetAddr(mmioRenameW);
			GetAddr(mmioSeek);
			GetAddr(mmioSendMessage);
			GetAddr(mmioSetBuffer);
			GetAddr(mmioSetInfo);
			GetAddr(mmioStringToFOURCCA);
			GetAddr(mmioStringToFOURCCW);
			GetAddr(mmioWrite);
			GetAddr(mmsystemGetVersion);
			GetAddr(mod32Message);
			GetAddr(mxd32Message);
			GetAddr(sndPlaySoundA);
			GetAddr(sndPlaySoundW);
			GetAddr(tid32Message);
			GetAddr(timeBeginPeriod);
			GetAddr(timeEndPeriod);
			GetAddr(timeGetDevCaps);
			GetAddr(timeGetSystemTime);
			GetAddr(timeGetTime);
			GetAddr(timeKillEvent);
			GetAddr(timeSetEvent);
			GetAddr(waveInAddBuffer);
			GetAddr(waveInClose);
			GetAddr(waveInGetDevCapsA);
			GetAddr(waveInGetDevCapsW);
			GetAddr(waveInGetErrorTextA);
			GetAddr(waveInGetErrorTextW);
			GetAddr(waveInGetID);
			GetAddr(waveInGetNumDevs);
			GetAddr(waveInGetPosition);
			GetAddr(waveInMessage);
			GetAddr(waveInOpen);
			GetAddr(waveInPrepareHeader);
			GetAddr(waveInReset);
			GetAddr(waveInStart);
			GetAddr(waveInStop);
			GetAddr(waveInUnprepareHeader);
			GetAddr(waveOutBreakLoop);
			GetAddr(waveOutClose);
			GetAddr(waveOutGetDevCapsA);
			GetAddr(waveOutGetDevCapsW);
			GetAddr(waveOutGetErrorTextA);
			GetAddr(waveOutGetErrorTextW);
			GetAddr(waveOutGetID);
			GetAddr(waveOutGetNumDevs);
			GetAddr(waveOutGetPitch);
			GetAddr(waveOutGetPlaybackRate);
			GetAddr(waveOutGetPosition);
			GetAddr(waveOutGetVolume);
			GetAddr(waveOutMessage);
			GetAddr(waveOutOpen);
			GetAddr(waveOutPause);
			GetAddr(waveOutPrepareHeader);
			GetAddr(waveOutReset);
			GetAddr(waveOutRestart);
			GetAddr(waveOutSetPitch);
			GetAddr(waveOutSetPlaybackRate);
			GetAddr(waveOutSetVolume);
			GetAddr(waveOutUnprepareHeader);
			GetAddr(waveOutWrite);
			GetAddr(wid32Message);
			GetAddr(wod32Message);

			return true;
		}
	}
	return false;
}
