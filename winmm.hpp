#pragma once
#define ALCDECL extern "C" __declspec(naked) void __cdecl

#pragma comment(linker, "/EXPORT:unkWinmm1=___unkWinmm1,@2,NONAME")
#pragma comment(linker, "/EXPORT:mciExecute=___mciExecute,@3")
#pragma comment(linker, "/EXPORT:CloseDriver=___CloseDriver,@4")
#pragma comment(linker, "/EXPORT:DefDriverProc=___DefDriverProc,@5")
#pragma comment(linker, "/EXPORT:DriverCallback=___DriverCallback,@6")
#pragma comment(linker, "/EXPORT:DrvGetModuleHandle=___DrvGetModuleHandle,@7")
#pragma comment(linker, "/EXPORT:GetDriverModuleHandle=___GetDriverModuleHandle,@8")
#pragma comment(linker, "/EXPORT:NotifyCallbackData=___NotifyCallbackData,@9")
#pragma comment(linker, "/EXPORT:OpenDriver=___OpenDriver,@10")
#pragma comment(linker, "/EXPORT:PlaySound=___PlaySound,@11")
#pragma comment(linker, "/EXPORT:PlaySoundA=___PlaySoundA,@12")
#pragma comment(linker, "/EXPORT:PlaySoundW=___PlaySoundW,@13")
#pragma comment(linker, "/EXPORT:SendDriverMessage=___SendDriverMessage,@14")
#pragma comment(linker, "/EXPORT:WOW32DriverCallback=___WOW32DriverCallback,@15")
#pragma comment(linker, "/EXPORT:WOW32ResolveMultiMediaHandle=___WOW32ResolveMultiMediaHandle,@16")
#pragma comment(linker, "/EXPORT:WOWAppExit=___WOWAppExit,@17")
#pragma comment(linker, "/EXPORT:aux32Message=___aux32Message,@18")
#pragma comment(linker, "/EXPORT:auxGetDevCapsA=___auxGetDevCapsA,@19")
#pragma comment(linker, "/EXPORT:auxGetDevCapsW=___auxGetDevCapsW,@20")
#pragma comment(linker, "/EXPORT:auxGetNumDevs=___auxGetNumDevs,@21")
#pragma comment(linker, "/EXPORT:auxGetVolume=___auxGetVolume,@22")
#pragma comment(linker, "/EXPORT:auxOutMessage=___auxOutMessage,@23")
#pragma comment(linker, "/EXPORT:auxSetVolume=___auxSetVolume,@24")
#pragma comment(linker, "/EXPORT:joy32Message=___joy32Message,@25")
#pragma comment(linker, "/EXPORT:joyConfigChanged=___joyConfigChanged,@26")
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=___joyGetDevCapsA,@27")
#pragma comment(linker, "/EXPORT:joyGetDevCapsW=___joyGetDevCapsW,@28")
#pragma comment(linker, "/EXPORT:joyGetNumDevs=___joyGetNumDevs,@29")
#pragma comment(linker, "/EXPORT:joyGetPos=___joyGetPos,@30")
#pragma comment(linker, "/EXPORT:joyGetPosEx=___joyGetPosEx,@31")
#pragma comment(linker, "/EXPORT:joyGetThreshold=___joyGetThreshold,@32")
#pragma comment(linker, "/EXPORT:joyReleaseCapture=___joyReleaseCapture,@33")
#pragma comment(linker, "/EXPORT:joySetCapture=___joySetCapture,@34")
#pragma comment(linker, "/EXPORT:joySetThreshold=___joySetThreshold,@35")
#pragma comment(linker, "/EXPORT:mci32Message=___mci32Message,@36")
#pragma comment(linker, "/EXPORT:mciDriverNotify=___mciDriverNotify,@37")
#pragma comment(linker, "/EXPORT:mciDriverYield=___mciDriverYield,@38")
#pragma comment(linker, "/EXPORT:mciFreeCommandResource=___mciFreeCommandResource,@39")
#pragma comment(linker, "/EXPORT:mciGetCreatorTask=___mciGetCreatorTask,@40")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDA=___mciGetDeviceIDA,@41")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=___mciGetDeviceIDFromElementIDA,@42")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=___mciGetDeviceIDFromElementIDW,@43")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDW=___mciGetDeviceIDW,@44")
#pragma comment(linker, "/EXPORT:mciGetDriverData=___mciGetDriverData,@45")
#pragma comment(linker, "/EXPORT:mciGetErrorStringA=___mciGetErrorStringA,@46")
#pragma comment(linker, "/EXPORT:mciGetErrorStringW=___mciGetErrorStringW,@47")
#pragma comment(linker, "/EXPORT:mciGetYieldProc=___mciGetYieldProc,@48")
#pragma comment(linker, "/EXPORT:mciLoadCommandResource=___mciLoadCommandResource,@49")
#pragma comment(linker, "/EXPORT:mciSendCommandA=___mciSendCommandA,@50")
#pragma comment(linker, "/EXPORT:mciSendCommandW=___mciSendCommandW,@51")
#pragma comment(linker, "/EXPORT:mciSendStringA=___mciSendStringA,@52")
#pragma comment(linker, "/EXPORT:mciSendStringW=___mciSendStringW,@53")
#pragma comment(linker, "/EXPORT:mciSetDriverData=___mciSetDriverData,@54")
#pragma comment(linker, "/EXPORT:mciSetYieldProc=___mciSetYieldProc,@55")
#pragma comment(linker, "/EXPORT:mid32Message=___mid32Message,@56")
#pragma comment(linker, "/EXPORT:midiConnect=___midiConnect,@57")
#pragma comment(linker, "/EXPORT:midiDisconnect=___midiDisconnect,@58")
#pragma comment(linker, "/EXPORT:midiInAddBuffer=___midiInAddBuffer,@59")
#pragma comment(linker, "/EXPORT:midiInClose=___midiInClose,@60")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsA=___midiInGetDevCapsA,@61")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsW=___midiInGetDevCapsW,@62")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextA=___midiInGetErrorTextA,@63")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextW=___midiInGetErrorTextW,@64")
#pragma comment(linker, "/EXPORT:midiInGetID=___midiInGetID,@65")
#pragma comment(linker, "/EXPORT:midiInGetNumDevs=___midiInGetNumDevs,@66")
#pragma comment(linker, "/EXPORT:midiInMessage=___midiInMessage,@67")
#pragma comment(linker, "/EXPORT:midiInOpen=___midiInOpen,@68")
#pragma comment(linker, "/EXPORT:midiInPrepareHeader=___midiInPrepareHeader,@69")
#pragma comment(linker, "/EXPORT:midiInReset=___midiInReset,@70")
#pragma comment(linker, "/EXPORT:midiInStart=___midiInStart,@71")
#pragma comment(linker, "/EXPORT:midiInStop=___midiInStop,@72")
#pragma comment(linker, "/EXPORT:midiInUnprepareHeader=___midiInUnprepareHeader,@73")
#pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=___midiOutCacheDrumPatches,@74")
#pragma comment(linker, "/EXPORT:midiOutCachePatches=___midiOutCachePatches,@75")
#pragma comment(linker, "/EXPORT:midiOutClose=___midiOutClose,@76")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=___midiOutGetDevCapsA,@77")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=___midiOutGetDevCapsW,@78")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=___midiOutGetErrorTextA,@79")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=___midiOutGetErrorTextW,@80")
#pragma comment(linker, "/EXPORT:midiOutGetID=___midiOutGetID,@81")
#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=___midiOutGetNumDevs,@82")
#pragma comment(linker, "/EXPORT:midiOutGetVolume=___midiOutGetVolume,@83")
#pragma comment(linker, "/EXPORT:midiOutLongMsg=___midiOutLongMsg,@84")
#pragma comment(linker, "/EXPORT:midiOutMessage=___midiOutMessage,@85")
#pragma comment(linker, "/EXPORT:midiOutOpen=___midiOutOpen,@86")
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=___midiOutPrepareHeader,@87")
#pragma comment(linker, "/EXPORT:midiOutReset=___midiOutReset,@88")
#pragma comment(linker, "/EXPORT:midiOutSetVolume=___midiOutSetVolume,@89")
#pragma comment(linker, "/EXPORT:midiOutShortMsg=___midiOutShortMsg,@90")
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=___midiOutUnprepareHeader,@91")
#pragma comment(linker, "/EXPORT:midiStreamClose=___midiStreamClose,@92")
#pragma comment(linker, "/EXPORT:midiStreamOpen=___midiStreamOpen,@93")
#pragma comment(linker, "/EXPORT:midiStreamOut=___midiStreamOut,@94")
#pragma comment(linker, "/EXPORT:midiStreamPause=___midiStreamPause,@95")
#pragma comment(linker, "/EXPORT:midiStreamPosition=___midiStreamPosition,@96")
#pragma comment(linker, "/EXPORT:midiStreamProperty=___midiStreamProperty,@97")
#pragma comment(linker, "/EXPORT:midiStreamRestart=___midiStreamRestart,@98")
#pragma comment(linker, "/EXPORT:midiStreamStop=___midiStreamStop,@99")
#pragma comment(linker, "/EXPORT:mixerClose=___mixerClose,@100")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=___mixerGetControlDetailsA,@101")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=___mixerGetControlDetailsW,@102")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsA=___mixerGetDevCapsA,@103")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsW=___mixerGetDevCapsW,@104")
#pragma comment(linker, "/EXPORT:mixerGetID=___mixerGetID,@105")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsA=___mixerGetLineControlsA,@106")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsW=___mixerGetLineControlsW,@107")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoA=___mixerGetLineInfoA,@108")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoW=___mixerGetLineInfoW,@109")
#pragma comment(linker, "/EXPORT:mixerGetNumDevs=___mixerGetNumDevs,@110")
#pragma comment(linker, "/EXPORT:mixerMessage=___mixerMessage,@111")
#pragma comment(linker, "/EXPORT:mixerOpen=___mixerOpen,@112")
#pragma comment(linker, "/EXPORT:mixerSetControlDetails=___mixerSetControlDetails,@113")
#pragma comment(linker, "/EXPORT:mmDrvInstall=___mmDrvInstall,@114")
#pragma comment(linker, "/EXPORT:mmGetCurrentTask=___mmGetCurrentTask,@115")
#pragma comment(linker, "/EXPORT:mmTaskBlock=___mmTaskBlock,@116")
#pragma comment(linker, "/EXPORT:mmTaskCreate=___mmTaskCreate,@117")
#pragma comment(linker, "/EXPORT:mmTaskSignal=___mmTaskSignal,@118")
#pragma comment(linker, "/EXPORT:mmTaskYield=___mmTaskYield,@119")
#pragma comment(linker, "/EXPORT:mmioAdvance=___mmioAdvance,@120")
#pragma comment(linker, "/EXPORT:mmioAscend=___mmioAscend,@121")
#pragma comment(linker, "/EXPORT:mmioClose=___mmioClose,@122")
#pragma comment(linker, "/EXPORT:mmioCreateChunk=___mmioCreateChunk,@123")
#pragma comment(linker, "/EXPORT:mmioDescend=___mmioDescend,@124")
#pragma comment(linker, "/EXPORT:mmioFlush=___mmioFlush,@125")
#pragma comment(linker, "/EXPORT:mmioGetInfo=___mmioGetInfo,@126")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcA=___mmioInstallIOProcA,@127")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcW=___mmioInstallIOProcW,@128")
#pragma comment(linker, "/EXPORT:mmioOpenA=___mmioOpenA,@129")
#pragma comment(linker, "/EXPORT:mmioOpenW=___mmioOpenW,@130")
#pragma comment(linker, "/EXPORT:mmioRead=___mmioRead,@131")
#pragma comment(linker, "/EXPORT:mmioRenameA=___mmioRenameA,@132")
#pragma comment(linker, "/EXPORT:mmioRenameW=___mmioRenameW,@133")
#pragma comment(linker, "/EXPORT:mmioSeek=___mmioSeek,@134")
#pragma comment(linker, "/EXPORT:mmioSendMessage=___mmioSendMessage,@135")
#pragma comment(linker, "/EXPORT:mmioSetBuffer=___mmioSetBuffer,@136")
#pragma comment(linker, "/EXPORT:mmioSetInfo=___mmioSetInfo,@137")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=___mmioStringToFOURCCA,@138")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=___mmioStringToFOURCCW,@139")
#pragma comment(linker, "/EXPORT:mmioWrite=___mmioWrite,@140")
#pragma comment(linker, "/EXPORT:mmsystemGetVersion=___mmsystemGetVersion,@141")
#pragma comment(linker, "/EXPORT:mod32Message=___mod32Message,@142")
#pragma comment(linker, "/EXPORT:mxd32Message=___mxd32Message,@143")
#pragma comment(linker, "/EXPORT:sndPlaySoundA=___sndPlaySoundA,@144")
#pragma comment(linker, "/EXPORT:sndPlaySoundW=___sndPlaySoundW,@145")
#pragma comment(linker, "/EXPORT:tid32Message=___tid32Message,@146")
#pragma comment(linker, "/EXPORT:timeBeginPeriod=___timeBeginPeriod,@147")
#pragma comment(linker, "/EXPORT:timeEndPeriod=___timeEndPeriod,@148")
#pragma comment(linker, "/EXPORT:timeGetDevCaps=___timeGetDevCaps,@149")
#pragma comment(linker, "/EXPORT:timeGetSystemTime=___timeGetSystemTime,@150")
#pragma comment(linker, "/EXPORT:timeGetTime=___timeGetTime,@151")
#pragma comment(linker, "/EXPORT:timeKillEvent=___timeKillEvent,@152")
#pragma comment(linker, "/EXPORT:timeSetEvent=___timeSetEvent,@153")
#pragma comment(linker, "/EXPORT:waveInAddBuffer=___waveInAddBuffer,@154")
#pragma comment(linker, "/EXPORT:waveInClose=___waveInClose,@155")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsA=___waveInGetDevCapsA,@156")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsW=___waveInGetDevCapsW,@157")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextA=___waveInGetErrorTextA,@158")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextW=___waveInGetErrorTextW,@159")
#pragma comment(linker, "/EXPORT:waveInGetID=___waveInGetID,@160")
#pragma comment(linker, "/EXPORT:waveInGetNumDevs=___waveInGetNumDevs,@161")
#pragma comment(linker, "/EXPORT:waveInGetPosition=___waveInGetPosition,@162")
#pragma comment(linker, "/EXPORT:waveInMessage=___waveInMessage,@163")
#pragma comment(linker, "/EXPORT:waveInOpen=___waveInOpen,@164")
#pragma comment(linker, "/EXPORT:waveInPrepareHeader=___waveInPrepareHeader,@165")
#pragma comment(linker, "/EXPORT:waveInReset=___waveInReset,@166")
#pragma comment(linker, "/EXPORT:waveInStart=___waveInStart,@167")
#pragma comment(linker, "/EXPORT:waveInStop=___waveInStop,@168")
#pragma comment(linker, "/EXPORT:waveInUnprepareHeader=___waveInUnprepareHeader,@169")
#pragma comment(linker, "/EXPORT:waveOutBreakLoop=___waveOutBreakLoop,@170")
#pragma comment(linker, "/EXPORT:waveOutClose=___waveOutClose,@171")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=___waveOutGetDevCapsA,@172")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=___waveOutGetDevCapsW,@173")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=___waveOutGetErrorTextA,@174")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=___waveOutGetErrorTextW,@175")
#pragma comment(linker, "/EXPORT:waveOutGetID=___waveOutGetID,@176")
#pragma comment(linker, "/EXPORT:waveOutGetNumDevs=___waveOutGetNumDevs,@177")
#pragma comment(linker, "/EXPORT:waveOutGetPitch=___waveOutGetPitch,@178")
#pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=___waveOutGetPlaybackRate,@179")
#pragma comment(linker, "/EXPORT:waveOutGetPosition=___waveOutGetPosition,@180")
#pragma comment(linker, "/EXPORT:waveOutGetVolume=___waveOutGetVolume,@181")
#pragma comment(linker, "/EXPORT:waveOutMessage=___waveOutMessage,@182")
#pragma comment(linker, "/EXPORT:waveOutOpen=___waveOutOpen,@183")
#pragma comment(linker, "/EXPORT:waveOutPause=___waveOutPause,@184")
#pragma comment(linker, "/EXPORT:waveOutPrepareHeader=___waveOutPrepareHeader,@185")
#pragma comment(linker, "/EXPORT:waveOutReset=___waveOutReset,@186")
#pragma comment(linker, "/EXPORT:waveOutRestart=___waveOutRestart,@187")
#pragma comment(linker, "/EXPORT:waveOutSetPitch=___waveOutSetPitch,@188")
#pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=___waveOutSetPlaybackRate,@189")
#pragma comment(linker, "/EXPORT:waveOutSetVolume=___waveOutSetVolume,@190")
#pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=___waveOutUnprepareHeader,@191")
#pragma comment(linker, "/EXPORT:waveOutWrite=___waveOutWrite,@192")
#pragma comment(linker, "/EXPORT:wid32Message=___wid32Message,@193")
#pragma comment(linker, "/EXPORT:wod32Message=___wod32Message,@194")

HMODULE hDll = nullptr;

#define FUNCADDR(name) FARPROC _##name;

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

#define FUNC(name) ALCDECL __##name() { __asm jmp _##name }

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
			
			_unkWinmm1= GetProcAddress(hDll, MAKEINTRESOURCEA(2));
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
