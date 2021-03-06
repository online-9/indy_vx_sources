MAX_INSTRUCTION_LENGTH	equ 15

MODRM_MOD_MASK		equ 11000000B
MODRM_REG_MASK		equ 00111000B
MODRM_RM_MASK		equ 00000111B

; TEB.Tib.StackBase � StackLimit.
;
PcStackBase	equ 4
PcStackLimit	equ 8

EOL	equ NULL	; End Of List.

; ~ RtlpCheckHeapSignature().
;
MSG_HEAP_INVALID_SIGNATURE		equ 033391F16H	; HASH("Invalid heap signature for heap "), 0x20
MSG_HEAP_INVALID_SIGNATURE_LENGTH	equ 32

WSP_PARSE_DATA struct
WsHandle			HANDLE ?	; mswsock.dll
WSPSocketLvl2		GP_SNAPSHOT <>	; Cs'
WSPSocketLvl0		GP_SNAPSHOT <>	; Rw', !GpLimit
WSP_PARSE_DATA ends
PWSP_PARSE_DATA typedef ptr WSP_PARSE_DATA

BADREF_MAGIC_BASE	equ 00DBAC0D0H

; ����� ���������� � ������� ������� AFD.
;
HT_ENTRIES	equ 64

; ������ � ������� �������.
;
HT_ENTRY struct
Handle	HANDLE ?
Magic	ULONG ?
HT_ENTRY ends
PHT_ENTRY typedef ptr HT_ENTRY

; �����.
;
ENVIRONMENT struct
Apis			APIS <>	; � ������ ���������!
ifdef DBGBUILD
; ��� ������������� ������� �������� ������� ��������� � TLS.
   TraceOverCount		ULONG ?
   TraceIntoCount		ULONG ?
   SkipTraceStubCount	ULONG ?
   OpenCount			ULONG ?
   CloseCount			ULONG ?
   BadrefCount			ULONG ?
   IoControlCount		ULONG ?
   BreakCount			ULONG ?
   PrintCount			ULONG ?
   RtlpCheckHeapSignatureCalls	ULONG ?
   BadrefStubCount		ULONG ?
   LastTraceIp			PVOID ?
endif
WspSnapshot	WSP_PARSE_DATA <>
HmgrSnapshot	GP_SNAPSHOT <>
BodySnapshot	GP_SNAPSHOT <>
HandleTable	HT_ENTRY HT_ENTRIES + 1 DUP (<>)
ENVIRONMENT ends
PENVIRONMENT typedef ptr ENVIRONMENT

; TLS.
;
TLS struct
RouteIp	PVOID ?	; ����� �������� ��� ������������� RtlpCheckHeapSignature().
SkipIp	PVOID ?	; ����� �������� ��� �����������.
Ip2ndf	PVOID ?	; ����� �������� � WSPSocket().
PostIp	PVOID ?	; ����� �������� �� WSPSocket() ��� ���������� ���������� �����������.
Flags	ULONG ?
TLS ends
PTLS typedef ptr TLS

; �������� ������ �� ����� � PEB.
;
PEB_ENV_PTR	equ X86_PAGE_SIZE - 4

; ��������� �����.
;
%GET_ENV_PTR macro Reg32
	mov Reg32,fs:[TEB.Peb]
	mov Reg32,dword ptr [Reg32 + PEB_ENV_PTR]
endm

; �������� �����.
;
%SET_ENV_PTR macro pEnv
	mov eax,fs:[TEB.Peb]
	mov dword ptr [eax + PEB_ENV_PTR],pEnv
endm

%HALT macro
	jmp $
endm

OBJECT_HANDLE_FLAG_INFORMATION struct
Inherit			BOOL ?
ProtectFromClose	BOOL ?
OBJECT_HANDLE_FLAG_INFORMATION ends
POBJECT_HANDLE_FLAG_INFORMATION typedef ptr OBJECT_HANDLE_FLAG_INFORMATION