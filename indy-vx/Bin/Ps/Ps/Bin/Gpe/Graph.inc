; �������� ������ ���� ����� ������� ������ ���������
; �, ������� ����������� � ������ ��������������� � �
; � �������� �����������. �������� ���� ����������� �
; ���� ������ �������(�� ��������� ������ ����������).
; ������� ��������� �������� ��������� ��� ������� ��
; ������� ����� � ���������. �������, ��� ��������� � 
; ��� � ���� � ���������� ��������� �� ������� 4-� ��
; ��. ����� ������� ������� ��� ���� ������ �� ������
; ��� �������� � ������������ ��� �����.

TYPE_MASK			equ 11B

; [����� �������� ����� � ���������� ���������� � ���
; ����� Eh(Entry Header). ������ ������������ ������
; ���� ��������������� ����� �� ���� � ���������.]
; �������� ������ 4-� ����� ���� ���������� ���������.
 
; ��������� ��������� �����.
BLOCK_HEADER struct
Link			LIST_ENTRY <>	; Link.Flink & HEADER_TYPE_MASK = HEADER_TYPE_LINE
; Flink:
; > 00 Line
;   01 Subroutine
;   10 Branch
;   11 Conditional branch
; Blink:
; - �����(GCBE_PARSE_SEPARATE).
;   XN
; - ��� ������������� ����(ACCESSED_MASK_FLAG).
;   NX
Address		PVOID ?
UserData		PVOID ?
_Size		ULONG ?	; ������ �����(����� ���� ���� ���������� �������� � ����������� ����).
_Align		ULONG ?
BLOCK_HEADER ends
PBLOCK_HEADER typedef ptr BLOCK_HEADER

; ���� ���������� ��� ���� ��������� ��������� �������� ����������.
EhSepatateFlag		equ BLOCK_HEADER.Link.Blink
SEPARATE_MACRO_FLAG	equ 01B

EhSize			equ BLOCK_HEADER._Size

; ��������� ���� ����� ����� ���������� ������, ��� 
; ��������� �������� ��.

ENTRY_HEADER_SIZE	equ sizeof(BLOCK_HEADER)

; ��� ��������� ������� ����� ����� � ������������ ��
; ��� ������������ ������.

EhFlink			equ BLOCK_HEADER.Link.Flink
EhBlink			equ BLOCK_HEADER.Link.Blink

; ������ ��� ���� ����������(Link) - ��� ������, �� �
; �������� � ���������� ���������. ������� ��� ���� �
; ����� �� ��������� ���������(Link.Flink) ���������� 
; ��� ���������.

EhEntryType		equ BLOCK_HEADER.Link.Flink	; TYPE_MASK

; ����� ������������ 4 ����:

HEADER_TYPE_LINE	equ 00B	; �������� ����.
HEADER_TYPE_CALL	equ 01B	; ����������� ���������.
HEADER_TYPE_JMP	equ 10B	; ����������� ���������.
HEADER_TYPE_JXX	equ 11B	; �������� ���������.

; ���������� Loop, Loope, Loopne � Jcxz �������� ��������� �����������(HEADER_TYPE_JXX).

; ������ ���� ����������(Address) �������� ��������� 
; �� ����������� ����������.

EhAddress			equ BLOCK_HEADER.Address

; ��� 1 ���� Link.Blink �� ���� ���������� ������� � 
; ������������ ��� ����������� ������� ���������. (��
; ���������� ���������� �������� ����� ���� ��� �����
; � �������, ������� ��� ����� ��������� ������� ����
; �������).

EhAccessFlag		equ BLOCK_HEADER.Link.Blink	; ACCESSED_MASK_FLAG
ACCESSED_MASK_FLAG	equ 10B	; _HEADER.Link.Blink

; 4-� ���� ���������� ������� � ������������ ��� ����
; ���� ���������������� ������, ��������� � ���������
; �. ������������ ��� �������� ������� ����������� �
; �����.

EhUserData		equ BLOCK_HEADER.UserData

; ��������� ������������ ���������.
CALL_HEADER struct
Link			LIST_ENTRY <>	; ..HEADER_TYPE_CALL
; Flink:
;   00 Line
; > 01 Subroutine
;   10 Branch
;   11 Conditional branch
; Blink:
;   X0 ����� ��������� ��������.
;   X1 ����� ��������� �� ��������(Call Eax, etc.)
; - ��� ������������� ����(ACCESSED_MASK_FLAG).
;   NX
Address		PVOID ?
UserData		PVOID ?
BranchAddress	PVOID ?
BranchLink	PVOID ?
CALL_HEADER ends
PCALL_HEADER typedef ptr CALL_HEADER

DISCLOSURE_CALL_FLAG	equ 01B
EhDisclosureFlag		equ CALL_HEADER.BranchLink	; DISCLOSURE_CALL_FLAG

; ��������� ������������ ���������.	
BRANCH_HEADER struct
Link			LIST_ENTRY <>	; ..HEADER_TYPE_JMP
; Flink:
;   00 Line
;   01 Subroutine
; > 10 Branch
;   11 Conditional branch
; Blink:
;   X0 ����� ��������� ��������.
;   X1 ����� ��������� �� ��������(Jmp Eax, etc.)
; - ��� ������������� ����(ACCESSED_MASK_FLAG).
;   NX
Address		PVOID ?
UserData		PVOID ?
BranchAddress	PVOID ?	; ����� ���� ���������� ���������.
BranchLink	PVOID ?	; ��������� ���������� �� ������, �� ������� ���������� ���������.
; - ��� ���������(���������� �����������).
;   X0 Short
;   X1 Near
; - �������� ���������(��������� � �������� �������������).
;   NX
BRANCH_HEADER ends
PBRANCH_HEADER typedef ptr BRANCH_HEADER

EhBranchAddress	equ BRANCH_HEADER.BranchAddress
EhBranchLink		equ BRANCH_HEADER.BranchLink

BRANCH_SIZE_MASK	equ 01H	; BRANCH_HEADER.BranchLink
EhBranchSize		equ BRANCH_HEADER.BranchLink	; BRANCH_SIZE_MASK

; ���������� ���� ������������ ���������.
BRANCH_IDLE_FLAG	equ 10B	; BRANCH_HEADER.BranchLink
EhIdleBranch		equ BRANCH_HEADER.BranchLink	; BRANCH_IDLE_FLAG

BRANCH_DEFINED_FLAG	equ 01B	; BRANCH_HEADER.Link.Blink
EhBranchType		equ BRANCH_HEADER.Link.Blink	; BRANCH_DEFINED_FLAG

; ��������� ��������� ���������(Jcc, Loop, Loope, Loopne � Jcxz).	
XX_BRANCH_HEADER struct
Link			LIST_ENTRY <>	; ..HEADER_TYPE_JXX
; Flink:
;   00 Line
;   01 Subroutine
;   10 Branch
; > 11 Conditional branch
; Blink:
;   X0 Jcc.
;   X1 Loop, Loope, Loopne � Jcxz.
; - ��� ������������� ����(ACCESSED_MASK_FLAG).
;   NX
Address		PVOID ?
UserData		PVOID ?
BranchAddress	PVOID ?	; ����� ���� ���������� ���������.
BranchLink	PVOID ?	; ��������� ���������� �� ������, �� ������� ���������� ���������.
; - ��� ���������.
;   X0 Short
;   X1 Near
; - �������� ���������.
;   NX
XX_BRANCH_HEADER ends
PXX_BRANCH_HEADER typedef ptr XX_BRANCH_HEADER

BRANCH_CX_FLAG		equ 01B	; XX_BRANCH_HEADER.Link.Blink
EhJccType			equ XX_BRANCH_HEADER.Link.Blink	; BRANCH_CX_FLAG