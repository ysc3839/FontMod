;PUBLIC hello_from_asm
;EXTERN puts:PROC
IFDEF RAX
ELSE
.MODEL Flat
ENDIF

FUNC MACRO name
PUBLIC @CatStr(<___>, name)
@CatStr(<___>, name) PROC
IFDEF RAX
jmp @CatStr(<_>, name)
ELSE
jmp @CatStr(<__>, name)
ENDIF
@CatStr(<___>, name) ENDP
ENDM

FUNCADDR MACRO name
IFDEF RAX
EXTERNDEF @CatStr(<_>, name):QWORD
ELSE
EXTERNDEF @CatStr(<__>, name):DWORD
ENDIF
ENDM


IFDEF RAX
EXTERNDEF addrCreateFontIndirectW:QWORD
EXTERNDEF addrGetStockObject:QWORD
ELSE
EXTERNDEF _addrCreateFontIndirectW:DWORD
EXTERNDEF _addrGetStockObject:DWORD
ENDIF



FUNCADDR unkWinmm1
FUNCADDR mciExecute
FUNCADDR CloseDriver 
FUNCADDR DefDriverProc 
FUNCADDR DriverCallback 
FUNCADDR DrvGetModuleHandle 
FUNCADDR GetDriverModuleHandle 
FUNCADDR NotifyCallbackData 
FUNCADDR OpenDriver 
FUNCADDR PlaySound 
FUNCADDR PlaySoundA 
FUNCADDR PlaySoundW 
FUNCADDR SendDriverMessage 
FUNCADDR WOW32DriverCallback 
FUNCADDR WOW32ResolveMultiMediaHandle 
FUNCADDR WOWAppExit 
FUNCADDR aux32Message 
FUNCADDR auxGetDevCapsA 
FUNCADDR auxGetDevCapsW 
FUNCADDR auxGetNumDevs 
FUNCADDR auxGetVolume 
FUNCADDR auxOutMessage 
FUNCADDR auxSetVolume 
FUNCADDR joy32Message 
FUNCADDR joyConfigChanged 
FUNCADDR joyGetDevCapsA 
FUNCADDR joyGetDevCapsW 
FUNCADDR joyGetNumDevs 
FUNCADDR joyGetPos 
FUNCADDR joyGetPosEx 
FUNCADDR joyGetThreshold 
FUNCADDR joyReleaseCapture 
FUNCADDR joySetCapture 
FUNCADDR joySetThreshold 
FUNCADDR mci32Message 
FUNCADDR mciDriverNotify 
FUNCADDR mciDriverYield 
FUNCADDR mciFreeCommandResource 
FUNCADDR mciGetCreatorTask 
FUNCADDR mciGetDeviceIDA 
FUNCADDR mciGetDeviceIDFromElementIDA 
FUNCADDR mciGetDeviceIDFromElementIDW 
FUNCADDR mciGetDeviceIDW 
FUNCADDR mciGetDriverData 
FUNCADDR mciGetErrorStringA 
FUNCADDR mciGetErrorStringW 
FUNCADDR mciGetYieldProc 
FUNCADDR mciLoadCommandResource 
FUNCADDR mciSendCommandA 
FUNCADDR mciSendCommandW 
FUNCADDR mciSendStringA 
FUNCADDR mciSendStringW 
FUNCADDR mciSetDriverData 
FUNCADDR mciSetYieldProc 
FUNCADDR mid32Message 
FUNCADDR midiConnect 
FUNCADDR midiDisconnect 
FUNCADDR midiInAddBuffer 
FUNCADDR midiInClose 
FUNCADDR midiInGetDevCapsA 
FUNCADDR midiInGetDevCapsW 
FUNCADDR midiInGetErrorTextA 
FUNCADDR midiInGetErrorTextW 
FUNCADDR midiInGetID 
FUNCADDR midiInGetNumDevs 
FUNCADDR midiInMessage 
FUNCADDR midiInOpen 
FUNCADDR midiInPrepareHeader 
FUNCADDR midiInReset 
FUNCADDR midiInStart 
FUNCADDR midiInStop 
FUNCADDR midiInUnprepareHeader 
FUNCADDR midiOutCacheDrumPatches 
FUNCADDR midiOutCachePatches 
FUNCADDR midiOutClose 
FUNCADDR midiOutGetDevCapsA 
FUNCADDR midiOutGetDevCapsW 
FUNCADDR midiOutGetErrorTextA 
FUNCADDR midiOutGetErrorTextW 
FUNCADDR midiOutGetID 
FUNCADDR midiOutGetNumDevs 
FUNCADDR midiOutGetVolume 
FUNCADDR midiOutLongMsg 
FUNCADDR midiOutMessage 
FUNCADDR midiOutOpen 
FUNCADDR midiOutPrepareHeader 
FUNCADDR midiOutReset 
FUNCADDR midiOutSetVolume 
FUNCADDR midiOutShortMsg 
FUNCADDR midiOutUnprepareHeader 
FUNCADDR midiStreamClose 
FUNCADDR midiStreamOpen 
FUNCADDR midiStreamOut 
FUNCADDR midiStreamPause 
FUNCADDR midiStreamPosition 
FUNCADDR midiStreamProperty 
FUNCADDR midiStreamRestart 
FUNCADDR midiStreamStop 
FUNCADDR mixerClose 
FUNCADDR mixerGetControlDetailsA 
FUNCADDR mixerGetControlDetailsW 
FUNCADDR mixerGetDevCapsA 
FUNCADDR mixerGetDevCapsW 
FUNCADDR mixerGetID 
FUNCADDR mixerGetLineControlsA 
FUNCADDR mixerGetLineControlsW 
FUNCADDR mixerGetLineInfoA 
FUNCADDR mixerGetLineInfoW 
FUNCADDR mixerGetNumDevs 
FUNCADDR mixerMessage 
FUNCADDR mixerOpen 
FUNCADDR mixerSetControlDetails 
FUNCADDR mmDrvInstall 
FUNCADDR mmGetCurrentTask 
FUNCADDR mmTaskBlock 
FUNCADDR mmTaskCreate 
FUNCADDR mmTaskSignal 
FUNCADDR mmTaskYield 
FUNCADDR mmioAdvance 
FUNCADDR mmioAscend 
FUNCADDR mmioClose 
FUNCADDR mmioCreateChunk 
FUNCADDR mmioDescend 
FUNCADDR mmioFlush 
FUNCADDR mmioGetInfo 
FUNCADDR mmioInstallIOProcA 
FUNCADDR mmioInstallIOProcW 
FUNCADDR mmioOpenA 
FUNCADDR mmioOpenW 
FUNCADDR mmioRead 
FUNCADDR mmioRenameA 
FUNCADDR mmioRenameW 
FUNCADDR mmioSeek 
FUNCADDR mmioSendMessage 
FUNCADDR mmioSetBuffer 
FUNCADDR mmioSetInfo 
FUNCADDR mmioStringToFOURCCA 
FUNCADDR mmioStringToFOURCCW 
FUNCADDR mmioWrite 
FUNCADDR mmsystemGetVersion 
FUNCADDR mod32Message 
FUNCADDR mxd32Message 
FUNCADDR sndPlaySoundA 
FUNCADDR sndPlaySoundW 
FUNCADDR tid32Message 
FUNCADDR timeBeginPeriod 
FUNCADDR timeEndPeriod 
FUNCADDR timeGetDevCaps 
FUNCADDR timeGetSystemTime 
FUNCADDR timeGetTime 
FUNCADDR timeKillEvent 
FUNCADDR timeSetEvent 
FUNCADDR waveInAddBuffer 
FUNCADDR waveInClose 
FUNCADDR waveInGetDevCapsA 
FUNCADDR waveInGetDevCapsW 
FUNCADDR waveInGetErrorTextA 
FUNCADDR waveInGetErrorTextW 
FUNCADDR waveInGetID 
FUNCADDR waveInGetNumDevs 
FUNCADDR waveInGetPosition 
FUNCADDR waveInMessage 
FUNCADDR waveInOpen 
FUNCADDR waveInPrepareHeader 
FUNCADDR waveInReset 
FUNCADDR waveInStart 
FUNCADDR waveInStop 
FUNCADDR waveInUnprepareHeader 
FUNCADDR waveOutBreakLoop 
FUNCADDR waveOutClose 
FUNCADDR waveOutGetDevCapsA 
FUNCADDR waveOutGetDevCapsW 
FUNCADDR waveOutGetErrorTextA 
FUNCADDR waveOutGetErrorTextW 
FUNCADDR waveOutGetID 
FUNCADDR waveOutGetNumDevs 
FUNCADDR waveOutGetPitch 
FUNCADDR waveOutGetPlaybackRate 
FUNCADDR waveOutGetPosition 
FUNCADDR waveOutGetVolume 
FUNCADDR waveOutMessage 
FUNCADDR waveOutOpen 
FUNCADDR waveOutPause 
FUNCADDR waveOutPrepareHeader 
FUNCADDR waveOutReset 
FUNCADDR waveOutRestart 
FUNCADDR waveOutSetPitch 
FUNCADDR waveOutSetPlaybackRate 
FUNCADDR waveOutSetVolume 
FUNCADDR waveOutUnprepareHeader 
FUNCADDR waveOutWrite 
FUNCADDR wid32Message 
FUNCADDR wod32Message 


.data

.code

IFDEF RAX
PUBLIC CallOrigCreateFontIndirectW
PUBLIC CallOrigGetStockObject
CallOrigCreateFontIndirectW:
	push rbx
	sub rsp, 20h
	mov rbx, rcx
	mov dword ptr [rsp + 38h], 49414eh
	jmp addrCreateFontIndirectW

CallOrigGetStockObject:
	push rbx
	sub rsp, 20h
	mov ebx, ecx
	mov dword ptr [rsp + 38h], 49414eh
	jmp addrGetStockObject

ELSE
PUBLIC _CallOrigCreateFontIndirectW@4
PUBLIC _CallOrigGetStockObject@4
_CallOrigCreateFontIndirectW@4:
	mov edi, edi
	push ebp
	mov ebp, esp
	push ecx
	jmp _addrCreateFontIndirectW

_CallOrigGetStockObject@4:
	mov edi, edi
	push ebp
	mov ebp, esp
	push ecx
	jmp _addrGetStockObject

ENDIF
FUNC unkWinmm1
FUNC mciExecute 
FUNC CloseDriver 
FUNC DefDriverProc 
FUNC DriverCallback 
FUNC DrvGetModuleHandle 
FUNC GetDriverModuleHandle 
FUNC NotifyCallbackData 
FUNC OpenDriver 
FUNC PlaySound 
FUNC PlaySoundA 
FUNC PlaySoundW 
FUNC SendDriverMessage 
FUNC WOW32DriverCallback 
FUNC WOW32ResolveMultiMediaHandle 
FUNC WOWAppExit 
FUNC aux32Message 
FUNC auxGetDevCapsA 
FUNC auxGetDevCapsW 
FUNC auxGetNumDevs 
FUNC auxGetVolume 
FUNC auxOutMessage 
FUNC auxSetVolume 
FUNC joy32Message 
FUNC joyConfigChanged 
FUNC joyGetDevCapsA 
FUNC joyGetDevCapsW 
FUNC joyGetNumDevs 
FUNC joyGetPos 
FUNC joyGetPosEx 
FUNC joyGetThreshold 
FUNC joyReleaseCapture 
FUNC joySetCapture 
FUNC joySetThreshold 
FUNC mci32Message 
FUNC mciDriverNotify 
FUNC mciDriverYield 
FUNC mciFreeCommandResource 
FUNC mciGetCreatorTask 
FUNC mciGetDeviceIDA 
FUNC mciGetDeviceIDFromElementIDA 
FUNC mciGetDeviceIDFromElementIDW 
FUNC mciGetDeviceIDW 
FUNC mciGetDriverData 
FUNC mciGetErrorStringA 
FUNC mciGetErrorStringW 
FUNC mciGetYieldProc 
FUNC mciLoadCommandResource 
FUNC mciSendCommandA 
FUNC mciSendCommandW 
FUNC mciSendStringA 
FUNC mciSendStringW 
FUNC mciSetDriverData 
FUNC mciSetYieldProc 
FUNC mid32Message 
FUNC midiConnect 
FUNC midiDisconnect 
FUNC midiInAddBuffer 
FUNC midiInClose 
FUNC midiInGetDevCapsA 
FUNC midiInGetDevCapsW 
FUNC midiInGetErrorTextA 
FUNC midiInGetErrorTextW 
FUNC midiInGetID 
FUNC midiInGetNumDevs 
FUNC midiInMessage 
FUNC midiInOpen 
FUNC midiInPrepareHeader 
FUNC midiInReset 
FUNC midiInStart 
FUNC midiInStop 
FUNC midiInUnprepareHeader 
FUNC midiOutCacheDrumPatches 
FUNC midiOutCachePatches 
FUNC midiOutClose 
FUNC midiOutGetDevCapsA 
FUNC midiOutGetDevCapsW 
FUNC midiOutGetErrorTextA 
FUNC midiOutGetErrorTextW 
FUNC midiOutGetID 
FUNC midiOutGetNumDevs 
FUNC midiOutGetVolume 
FUNC midiOutLongMsg 
FUNC midiOutMessage 
FUNC midiOutOpen 
FUNC midiOutPrepareHeader 
FUNC midiOutReset 
FUNC midiOutSetVolume 
FUNC midiOutShortMsg 
FUNC midiOutUnprepareHeader 
FUNC midiStreamClose 
FUNC midiStreamOpen 
FUNC midiStreamOut 
FUNC midiStreamPause 
FUNC midiStreamPosition 
FUNC midiStreamProperty 
FUNC midiStreamRestart 
FUNC midiStreamStop 
FUNC mixerClose 
FUNC mixerGetControlDetailsA 
FUNC mixerGetControlDetailsW 
FUNC mixerGetDevCapsA 
FUNC mixerGetDevCapsW 
FUNC mixerGetID 
FUNC mixerGetLineControlsA 
FUNC mixerGetLineControlsW 
FUNC mixerGetLineInfoA 
FUNC mixerGetLineInfoW 
FUNC mixerGetNumDevs 
FUNC mixerMessage 
FUNC mixerOpen 
FUNC mixerSetControlDetails 
FUNC mmDrvInstall 
FUNC mmGetCurrentTask 
FUNC mmTaskBlock 
FUNC mmTaskCreate 
FUNC mmTaskSignal 
FUNC mmTaskYield 
FUNC mmioAdvance 
FUNC mmioAscend 
FUNC mmioClose 
FUNC mmioCreateChunk 
FUNC mmioDescend 
FUNC mmioFlush 
FUNC mmioGetInfo 
FUNC mmioInstallIOProcA 
FUNC mmioInstallIOProcW 
FUNC mmioOpenA 
FUNC mmioOpenW 
FUNC mmioRead 
FUNC mmioRenameA 
FUNC mmioRenameW 
FUNC mmioSeek 
FUNC mmioSendMessage 
FUNC mmioSetBuffer 
FUNC mmioSetInfo 
FUNC mmioStringToFOURCCA 
FUNC mmioStringToFOURCCW 
FUNC mmioWrite 
FUNC mmsystemGetVersion 
FUNC mod32Message 
FUNC mxd32Message 
FUNC sndPlaySoundA 
FUNC sndPlaySoundW 
FUNC tid32Message 
FUNC timeBeginPeriod 
FUNC timeEndPeriod 
FUNC timeGetDevCaps 
FUNC timeGetSystemTime 
FUNC timeGetTime 
FUNC timeKillEvent 
FUNC timeSetEvent 
FUNC waveInAddBuffer 
FUNC waveInClose 
FUNC waveInGetDevCapsA 
FUNC waveInGetDevCapsW 
FUNC waveInGetErrorTextA 
FUNC waveInGetErrorTextW 
FUNC waveInGetID 
FUNC waveInGetNumDevs 
FUNC waveInGetPosition 
FUNC waveInMessage 
FUNC waveInOpen 
FUNC waveInPrepareHeader 
FUNC waveInReset 
FUNC waveInStart 
FUNC waveInStop 
FUNC waveInUnprepareHeader 
FUNC waveOutBreakLoop 
FUNC waveOutClose 
FUNC waveOutGetDevCapsA 
FUNC waveOutGetDevCapsW 
FUNC waveOutGetErrorTextA 
FUNC waveOutGetErrorTextW 
FUNC waveOutGetID 
FUNC waveOutGetNumDevs 
FUNC waveOutGetPitch 
FUNC waveOutGetPlaybackRate 
FUNC waveOutGetPosition 
FUNC waveOutGetVolume 
FUNC waveOutMessage 
FUNC waveOutOpen 
FUNC waveOutPause 
FUNC waveOutPrepareHeader 
FUNC waveOutReset 
FUNC waveOutRestart 
FUNC waveOutSetPitch 
FUNC waveOutSetPlaybackRate 
FUNC waveOutSetVolume 
FUNC waveOutUnprepareHeader 
FUNC waveOutWrite 
FUNC wid32Message 
FUNC wod32Message 

END