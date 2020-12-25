; This file contains code from https://github.com/ThirteenAG/Ultimate-ASI-Loader
; and https://github.com/plusls's pull request https://github.com/ysc3839/FontMod/pull/51

ifndef X64
	.386
	.model flat, C
endif

FuncStub macro name
	extern @CatStr(<addr>, name, <:ptr>)
	name proc export
		jmp @CatStr(<addr>, name)
	name endp
endm

.code

; dinput8
FuncStub DirectInput8Create
FuncStub DllCanUnloadNow
FuncStub DllGetClassObject
FuncStub DllRegisterServer
FuncStub DllUnregisterServer

; dinput
FuncStub DirectInputCreateA
FuncStub DirectInputCreateEx
FuncStub DirectInputCreateW
;DllCanUnloadNow
;DllGetClassObject
;DllRegisterServer
;DllUnregisterServer

; dsound
FuncStub DirectSoundCaptureCreate
FuncStub DirectSoundCaptureCreate8
FuncStub DirectSoundCaptureEnumerateA
FuncStub DirectSoundCaptureEnumerateW
FuncStub DirectSoundCreate
FuncStub DirectSoundCreate8
FuncStub DirectSoundEnumerateA
FuncStub DirectSoundEnumerateW
FuncStub DirectSoundFullDuplexCreate
;DllCanUnloadNow
;DllGetClassObject
FuncStub GetDeviceID

; d3d8 x86 only
ifndef X64
	;DebugSetMute
	FuncStub Direct3D8EnableMaximizedWindowedModeShim
	FuncStub Direct3DCreate8
	FuncStub ValidatePixelShader
	FuncStub ValidateVertexShader
endif

; d3d9
FuncStub D3DPERF_BeginEvent
FuncStub D3DPERF_EndEvent
FuncStub D3DPERF_GetStatus
FuncStub D3DPERF_QueryRepeatFrame
FuncStub D3DPERF_SetMarker
FuncStub D3DPERF_SetOptions
FuncStub D3DPERF_SetRegion
FuncStub DebugSetLevel
FuncStub DebugSetMute
FuncStub Direct3D9EnableMaximizedWindowedModeShim
FuncStub Direct3DCreate9
FuncStub Direct3DCreate9Ex
FuncStub Direct3DShaderValidatorCreate9
FuncStub PSGPError
FuncStub PSGPSampleTexture

; d3d11
FuncStub D3D11CoreCreateDevice
FuncStub D3D11CoreCreateLayeredDevice
FuncStub D3D11CoreGetLayeredDeviceSize
FuncStub D3D11CoreRegisterLayers
FuncStub D3D11CreateDevice
FuncStub D3D11CreateDeviceAndSwapChain
FuncStub D3DKMTCloseAdapter
FuncStub D3DKMTCreateAllocation
FuncStub D3DKMTCreateContext
FuncStub D3DKMTCreateDevice
FuncStub D3DKMTCreateSynchronizationObject
FuncStub D3DKMTDestroyAllocation
FuncStub D3DKMTDestroyContext
FuncStub D3DKMTDestroyDevice
FuncStub D3DKMTDestroySynchronizationObject
FuncStub D3DKMTEscape
FuncStub D3DKMTGetContextSchedulingPriority
FuncStub D3DKMTGetDeviceState
FuncStub D3DKMTGetDisplayModeList
FuncStub D3DKMTGetMultisampleMethodList
FuncStub D3DKMTGetRuntimeData
FuncStub D3DKMTGetSharedPrimaryHandle
FuncStub D3DKMTLock
FuncStub D3DKMTOpenAdapterFromHdc
FuncStub D3DKMTOpenResource
FuncStub D3DKMTPresent
FuncStub D3DKMTQueryAdapterInfo
FuncStub D3DKMTQueryAllocationResidency
FuncStub D3DKMTQueryResourceInfo
FuncStub D3DKMTRender
FuncStub D3DKMTSetAllocationPriority
FuncStub D3DKMTSetContextSchedulingPriority
FuncStub D3DKMTSetDisplayMode
FuncStub D3DKMTSetDisplayPrivateDriverFormat
FuncStub D3DKMTSetGammaRamp
FuncStub D3DKMTSetVidPnSourceOwner
FuncStub D3DKMTSignalSynchronizationObject
FuncStub D3DKMTUnlock
FuncStub D3DKMTWaitForSynchronizationObject
FuncStub D3DKMTWaitForVerticalBlankEvent
FuncStub D3DPerformance_BeginEvent
FuncStub D3DPerformance_EndEvent
FuncStub D3DPerformance_GetStatus
FuncStub D3DPerformance_SetMarker
FuncStub EnableFeatureLevelUpgrade
FuncStub OpenAdapter10
FuncStub OpenAdapter10_2

; ddraw
FuncStub AcquireDDThreadLock
FuncStub CompleteCreateSysmemSurface
FuncStub D3DParseUnknownCommand
FuncStub DDGetAttachedSurfaceLcl
FuncStub DDInternalLock
FuncStub DDInternalUnlock
FuncStub DSoundHelp
FuncStub DirectDrawCreate
FuncStub DirectDrawCreateClipper
FuncStub DirectDrawCreateEx
FuncStub DirectDrawEnumerateA
FuncStub DirectDrawEnumerateExA
FuncStub DirectDrawEnumerateExW
FuncStub DirectDrawEnumerateW
;DllCanUnloadNow
;DllGetClassObject
FuncStub GetDDSurfaceLocal
FuncStub GetOLEThunkData
FuncStub GetSurfaceFromDC
FuncStub RegisterSpecialCase
FuncStub ReleaseDDThreadLock
FuncStub SetAppCompatData

; winmm
FuncStub CloseDriver
FuncStub DefDriverProc
FuncStub DriverCallback
FuncStub DrvGetModuleHandle
FuncStub GetDriverModuleHandle
FuncStub NotifyCallbackData
FuncStub OpenDriver
FuncStub PlaySound
FuncStub PlaySoundA
FuncStub PlaySoundW
FuncStub SendDriverMessage
FuncStub WOW32DriverCallback
FuncStub WOW32ResolveMultiMediaHandle
FuncStub WOWAppExit
FuncStub aux32Message
FuncStub auxGetDevCapsA
FuncStub auxGetDevCapsW
FuncStub auxGetNumDevs
FuncStub auxGetVolume
FuncStub auxOutMessage
FuncStub auxSetVolume
FuncStub joy32Message
FuncStub joyConfigChanged
FuncStub joyGetDevCapsA
FuncStub joyGetDevCapsW
FuncStub joyGetNumDevs
FuncStub joyGetPos
FuncStub joyGetPosEx
FuncStub joyGetThreshold
FuncStub joyReleaseCapture
FuncStub joySetCapture
FuncStub joySetThreshold
FuncStub mci32Message
FuncStub mciDriverNotify
FuncStub mciDriverYield
FuncStub mciExecute
FuncStub mciFreeCommandResource
FuncStub mciGetCreatorTask
FuncStub mciGetDeviceIDA
FuncStub mciGetDeviceIDFromElementIDA
FuncStub mciGetDeviceIDFromElementIDW
FuncStub mciGetDeviceIDW
FuncStub mciGetDriverData
FuncStub mciGetErrorStringA
FuncStub mciGetErrorStringW
FuncStub mciGetYieldProc
FuncStub mciLoadCommandResource
FuncStub mciSendCommandA
FuncStub mciSendCommandW
FuncStub mciSendStringA
FuncStub mciSendStringW
FuncStub mciSetDriverData
FuncStub mciSetYieldProc
FuncStub mid32Message
FuncStub midiConnect
FuncStub midiDisconnect
FuncStub midiInAddBuffer
FuncStub midiInClose
FuncStub midiInGetDevCapsA
FuncStub midiInGetDevCapsW
FuncStub midiInGetErrorTextA
FuncStub midiInGetErrorTextW
FuncStub midiInGetID
FuncStub midiInGetNumDevs
FuncStub midiInMessage
FuncStub midiInOpen
FuncStub midiInPrepareHeader
FuncStub midiInReset
FuncStub midiInStart
FuncStub midiInStop
FuncStub midiInUnprepareHeader
FuncStub midiOutCacheDrumPatches
FuncStub midiOutCachePatches
FuncStub midiOutClose
FuncStub midiOutGetDevCapsA
FuncStub midiOutGetDevCapsW
FuncStub midiOutGetErrorTextA
FuncStub midiOutGetErrorTextW
FuncStub midiOutGetID
FuncStub midiOutGetNumDevs
FuncStub midiOutGetVolume
FuncStub midiOutLongMsg
FuncStub midiOutMessage
FuncStub midiOutOpen
FuncStub midiOutPrepareHeader
FuncStub midiOutReset
FuncStub midiOutSetVolume
FuncStub midiOutShortMsg
FuncStub midiOutUnprepareHeader
FuncStub midiStreamClose
FuncStub midiStreamOpen
FuncStub midiStreamOut
FuncStub midiStreamPause
FuncStub midiStreamPosition
FuncStub midiStreamProperty
FuncStub midiStreamRestart
FuncStub midiStreamStop
FuncStub mixerClose
FuncStub mixerGetControlDetailsA
FuncStub mixerGetControlDetailsW
FuncStub mixerGetDevCapsA
FuncStub mixerGetDevCapsW
FuncStub mixerGetID
FuncStub mixerGetLineControlsA
FuncStub mixerGetLineControlsW
FuncStub mixerGetLineInfoA
FuncStub mixerGetLineInfoW
FuncStub mixerGetNumDevs
FuncStub mixerMessage
FuncStub mixerOpen
FuncStub mixerSetControlDetails
FuncStub mmDrvInstall
FuncStub mmGetCurrentTask
FuncStub mmTaskBlock
FuncStub mmTaskCreate
FuncStub mmTaskSignal
FuncStub mmTaskYield
FuncStub mmioAdvance
FuncStub mmioAscend
FuncStub mmioClose
FuncStub mmioCreateChunk
FuncStub mmioDescend
FuncStub mmioFlush
FuncStub mmioGetInfo
FuncStub mmioInstallIOProcA
FuncStub mmioInstallIOProcW
FuncStub mmioOpenA
FuncStub mmioOpenW
FuncStub mmioRead
FuncStub mmioRenameA
FuncStub mmioRenameW
FuncStub mmioSeek
FuncStub mmioSendMessage
FuncStub mmioSetBuffer
FuncStub mmioSetInfo
FuncStub mmioStringToFOURCCA
FuncStub mmioStringToFOURCCW
FuncStub mmioWrite
FuncStub mmsystemGetVersion
FuncStub mod32Message
FuncStub mxd32Message
FuncStub sndPlaySoundA
FuncStub sndPlaySoundW
FuncStub tid32Message
FuncStub timeBeginPeriod
FuncStub timeEndPeriod
FuncStub timeGetDevCaps
FuncStub timeGetSystemTime
FuncStub timeGetTime
FuncStub timeKillEvent
FuncStub timeSetEvent
FuncStub waveInAddBuffer
FuncStub waveInClose
FuncStub waveInGetDevCapsA
FuncStub waveInGetDevCapsW
FuncStub waveInGetErrorTextA
FuncStub waveInGetErrorTextW
FuncStub waveInGetID
FuncStub waveInGetNumDevs
FuncStub waveInGetPosition
FuncStub waveInMessage
FuncStub waveInOpen
FuncStub waveInPrepareHeader
FuncStub waveInReset
FuncStub waveInStart
FuncStub waveInStop
FuncStub waveInUnprepareHeader
FuncStub waveOutBreakLoop
FuncStub waveOutClose
FuncStub waveOutGetDevCapsA
FuncStub waveOutGetDevCapsW
FuncStub waveOutGetErrorTextA
FuncStub waveOutGetErrorTextW
FuncStub waveOutGetID
FuncStub waveOutGetNumDevs
FuncStub waveOutGetPitch
FuncStub waveOutGetPlaybackRate
FuncStub waveOutGetPosition
FuncStub waveOutGetVolume
FuncStub waveOutMessage
FuncStub waveOutOpen
FuncStub waveOutPause
FuncStub waveOutPrepareHeader
FuncStub waveOutReset
FuncStub waveOutRestart
FuncStub waveOutSetPitch
FuncStub waveOutSetPlaybackRate
FuncStub waveOutSetVolume
FuncStub waveOutUnprepareHeader
FuncStub waveOutWrite
FuncStub wid32Message
FuncStub wod32Message

; version
FuncStub GetFileVersionInfoA
FuncStub GetFileVersionInfoByHandle
FuncStub GetFileVersionInfoExA
FuncStub GetFileVersionInfoExW
FuncStub GetFileVersionInfoSizeA
FuncStub GetFileVersionInfoSizeExA
FuncStub GetFileVersionInfoSizeExW
FuncStub GetFileVersionInfoSizeW
FuncStub GetFileVersionInfoW
FuncStub VerFindFileA
FuncStub VerFindFileW
FuncStub VerInstallFileA
FuncStub VerInstallFileW
FuncStub VerLanguageNameA
FuncStub VerLanguageNameW
FuncStub VerQueryValueA
FuncStub VerQueryValueW

; msimg32
FuncStub AlphaBlend
FuncStub DllInitialize
FuncStub GradientFill
FuncStub TransparentBlt
FuncStub vSetDdrawflag

end
