; o GPE/GCBE
; o (c) Indy, 2010.
;
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
IpCount		ULONG ?	; ����� ���������� � �����.
KitFlags		ULONG ?
CrossLink		PVOID ?	; ����������� ������ ����� ��������� Rw' � Cs'.
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
; ���� ��� ���� ��������, �� ���������������(�� ��������� ���, ����. ���������).

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

EhIpCount			equ BLOCK_HEADER.IpCount

; ��������� ������������ ���������.
CALL_HEADER struct
Link			LIST_ENTRY <>	; ..HEADER_TYPE_CALL
; Flink:
;   00 Line
; > 01 Subroutine
;   10 Branch
;   11 Conditional branch
; Blink:
;   X0 ����� ��������� �� ��������(Call Eax, etc.)
;   X1 ����� ��������� ��������.
; - ��� ������������� ����(ACCESSED_MASK_FLAG).
;   NX
Address		PVOID ?
UserData		PVOID ?
BranchAddress	PVOID ?
BranchLink	PVOID ?
;   X0 ��������� ��������.
;   X1 ��������� ��������.
KitFlags		ULONG ?
CrossLink		PVOID ?
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
;   X0 ����� ��������� �� ��������(Jmp Eax, etc.)
;   X1 ����� ��������� ��������.
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
KitFlags		ULONG ?
CrossLink		PVOID ?
BRANCH_HEADER ends
PBRANCH_HEADER typedef ptr BRANCH_HEADER

EhBranchAddress	equ BRANCH_HEADER.BranchAddress
EhBranchLink		equ BRANCH_HEADER.BranchLink

BRANCH_SIZE_MASK	equ 01H	; BRANCH_HEADER.BranchLink
EhBranchSize		equ BRANCH_HEADER.BranchLink	; BRANCH_SIZE_MASK
; 0 - short, 1 - near.

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
KitFlags		ULONG ?
CrossLink		PVOID ?
XX_BRANCH_HEADER ends
PXX_BRANCH_HEADER typedef ptr XX_BRANCH_HEADER

BRANCH_CX_FLAG		equ 01B	; XX_BRANCH_HEADER.Link.Blink
EhJcxType			equ XX_BRANCH_HEADER.Link.Blink	; BRANCH_CX_FLAG

EhKitFlags		equ BLOCK_HEADER.KitFlags
EhCrossLink		equ XX_BRANCH_HEADER.CrossLink

; ��� ��������� ����������� ���������� ���� �� ������. ����� ��������� � LDE �� 
; �����������, � ����������� ��������� ��� ���������. ��� ��������� ������������ 
; ���������(����� �� ��� � ��������� ��������).

JCC_SHORT_OPCODE_BASE	equ 70H
JCC_NEAR_OPCODE_BASE	equ 80H

JCC_O	equ 0	; OF
JCC_NO	equ 1	; !OF
JCC_C	equ 2	; CF
JCC_B	equ 2	; CF
JCC_NAE	equ 2	; CF
JCC_NC	equ 3	; !CF
JCC_NB	equ 3	; !CF
JCC_AE	equ 3	; !CF
JCC_Z	equ 4	; ZF
JCC_E	equ 4	; ZF
JCC_NZ	equ 5	; !ZF
JCC_NE	equ 5	; !ZF
JCC_NA	equ 6	; CF | ZF
JCC_BE	equ 6	; CF | ZF
JCC_A	equ 7	; !CF & !ZF
JCC_NBE	equ 7	; !CF & !ZF
JCC_S	equ 8	; SF
JCC_NS	equ 9	; !SF
JCC_P	equ 0AH	; PF
JCC_PE	equ 0AH	; PF
JCC_NP	equ 0BH	; !PF
JCC_PO	equ 0BH	; !PF
JCC_L	equ 0CH	; SF != OF
JCC_NGE	equ 0CH	; SF != OF
JCC_NL	equ 0DH	; SF = OF
JCC_GE	equ 0DH	; SF = OF
JCC_NG	equ 0EH	; ZF | (SF != OF)
JCC_LE	equ 0EH	; ZF | (SF != OF)
JCC_G	equ 0FH	; !ZF & (SF = OF)
JCC_NLE	equ 0FH	; !ZF & (SF = OF)

; o Jump short: 0x70 + JCC_*
; o Jump near: 0x0F 0x80 + JCC_*

JCC_LOOPNE	equ 0E0H	; Ecx & !ZF
JCC_LOOPE		equ 0E1H	; Ecx & ZF
JCC_LOOP		equ 0E2H	; Ecx
JCC_ECXZ		equ 0E3H	; !Ecx

JCX_OPCODE_BASE	equ 0E0H

JCC_TYPE_MASK	equ 00001111B	; BLOCK_HEADER.KitFlags
EhJccType		equ BLOCK_HEADER.KitFlags	; JCC_TYPE_MASK
JCC_X16_MASK	equ 00010000B	; BLOCK_HEADER.KitFlags, Pfx 0x67

BRANCH_DELTA_SIGN	equ 00100000B	; ���� ��������(0: +, 1: -).

EhBranchOffset	equ EhUserData	; �������� ��������� � ���������� ����.