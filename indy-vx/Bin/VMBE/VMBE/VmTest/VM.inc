; VMBE
;
; (c) Indy, 2012
;
VMBYPASS:
; proto C Ip:PVOID, Args:PVOID, ArgNum:ULONG
;
; OUT:
;	Eax: API()
;	Ecx: Ip's
;	Edx: MAGIC(0xC2)
;
; o ��� ����� �� ��������� popfd/ret(���� ���������� ������������� �� ������ ��������).
;
; __________________ Autogenerated dump _____________________
DB 0E9H, 0F1H, 004H, 000H, 000H, 055H, 08BH, 0ECH, 083H, 0C4H
DB 0F0H, 053H, 056H, 057H, 0C7H, 045H, 0F0H, 010H, 000H, 000H
DB 000H, 0C7H, 045H, 0F4H, 0F0H, 0F2H, 0F3H, 02EH, 0C7H, 045H
DB 0F8H, 03EH, 036H, 026H, 064H, 0C7H, 045H, 0FCH, 065H, 066H
DB 067H, 000H, 08BH, 075H, 008H, 0FCH, 08DH, 055H, 0F4H, 033H
DB 0DBH, 0FFH, 04DH, 0F0H, 075H, 006H, 033H, 0C0H, 033H, 0C9H
DB 0EBH, 025H, 0ACH, 08BH, 0FAH, 03CH, 067H, 0B9H, 00BH, 000H
DB 000H, 000H, 075H, 003H, 080H, 0CBH, 001H, 0F2H, 0AEH, 074H
DB 0E2H, 04EH, 033H, 0C0H, 00FH, 0B6H, 04EH, 0FFH, 02BH, 075H
DB 008H, 075H, 004H, 033H, 0C9H, 0EBH, 002H, 08BH, 0C6H, 08BH
DB 0D3H, 05FH, 05EH, 05BH, 0C9H, 0C2H, 004H, 000H, 055H, 08BH
DB 0ECH, 053H, 056H, 057H, 08BH, 05DH, 008H, 033H, 0FFH, 00FH
DB 0B6H, 003H, 08BH, 075H, 00CH, 08BH, 0D0H, 024H, 007H, 0C0H
DB 0C2H, 002H, 0C7H, 045H, 00CH, 000H, 000H, 000H, 000H, 080H
DB 0E2H, 003H, 075H, 02BH, 03CH, 003H, 077H, 00BH, 0F7H, 0D8H
DB 08BH, 084H, 086H, 0B0H, 000H, 000H, 000H, 0EBH, 04FH, 03CH
DB 004H, 075H, 008H, 0E8H, 092H, 000H, 000H, 000H, 047H, 0EBH
DB 043H, 03CH, 005H, 075H, 008H, 08BH, 043H, 001H, 083H, 0C7H
DB 004H, 0EBH, 037H, 02CH, 002H, 0EBH, 0D9H, 080H, 0FAH, 003H
DB 074H, 053H, 03CH, 003H, 077H, 036H, 0F7H, 0D8H, 08BH, 084H
DB 086H, 0B0H, 000H, 000H, 000H, 080H, 0FAH, 001H, 075H, 013H
DB 00FH, 0B6H, 054H, 01FH, 001H, 047H, 00FH, 0BAH, 0F2H, 007H
DB 073H, 00EH, 02DH, 080H, 000H, 000H, 000H, 0EBH, 007H, 08BH
DB 054H, 01FH, 001H, 083H, 0C7H, 004H, 003H, 0C2H, 08BH, 0CFH
DB 08BH, 055H, 00CH, 05FH, 05EH, 05BH, 0C9H, 0C2H, 008H, 000H
DB 03CH, 004H, 077H, 008H, 0E8H, 037H, 000H, 000H, 000H, 047H
DB 0EBH, 0C7H, 03CH, 005H, 075H, 005H, 083H, 0E8H, 006H, 0EBH
DB 0B5H, 02CH, 002H, 0EBH, 0B1H, 0C7H, 045H, 00CH, 001H, 000H
DB 000H, 000H, 03CH, 003H, 00FH, 086H, 072H, 0FFH, 0FFH, 0FFH
DB 03CH, 004H, 077H, 008H, 083H, 0E8H, 009H, 0E9H, 066H, 0FFH
DB 0FFH, 0FFH, 03CH, 005H, 075H, 085H, 083H, 0E8H, 006H, 0E9H
DB 05AH, 0FFH, 0FFH, 0FFH, 00FH, 0B6H, 04BH, 001H, 08BH, 0C1H
DB 0C0H, 0C1H, 002H, 0C1H, 0E8H, 003H, 024H, 007H, 080H, 0E1H
DB 003H, 03CH, 005H, 075H, 005H, 083H, 0E8H, 006H, 0EBH, 010H
DB 03CH, 004H, 075H, 006H, 033H, 0C0H, 0EBH, 013H, 0EBH, 006H
DB 03CH, 005H, 076H, 002H, 02CH, 002H, 0F7H, 0D8H, 08BH, 084H
DB 086H, 0B0H, 000H, 000H, 000H, 0D3H, 0E0H, 00FH, 0B6H, 04BH
DB 001H, 080H, 0E1H, 007H, 080H, 0F9H, 004H, 075H, 008H, 003H
DB 086H, 0C4H, 000H, 000H, 000H, 0EBH, 02EH, 080H, 0F9H, 005H
DB 075H, 014H, 00AH, 0D2H, 075H, 008H, 003H, 043H, 002H, 083H
DB 0C7H, 004H, 0EBH, 01DH, 003H, 086H, 0B4H, 000H, 000H, 000H
DB 0EBH, 015H, 080H, 0F9H, 003H, 077H, 00BH, 0F7H, 0D9H, 003H
DB 084H, 08EH, 0B0H, 000H, 000H, 000H, 0EBH, 005H, 080H, 0E9H
DB 002H, 0EBH, 0F0H, 0C3H, 055H, 08BH, 0ECH, 083H, 065H, 008H
DB 00FH, 08BH, 045H, 008H, 08BH, 04DH, 00CH, 083H, 065H, 008H
DB 001H, 0E8H, 00AH, 000H, 000H, 000H, 00FH, 092H, 0C0H, 031H
DB 045H, 008H, 0C9H, 0C2H, 008H, 000H, 0D1H, 0E8H, 083H, 0E0H
DB 007H, 074H, 038H, 0FEH, 0C8H, 074H, 039H, 0FEH, 0C8H, 074H
DB 03AH, 0FEH, 0C8H, 074H, 045H, 0FEH, 0C8H, 074H, 037H, 0FEH
DB 0C8H, 074H, 038H, 0FEH, 0C8H, 074H, 009H, 0FEH, 0C8H, 00FH
DB 0BAH, 0E1H, 006H, 073H, 001H, 0C3H, 0F7H, 0C1H, 080H, 000H
DB 000H, 000H, 00FH, 0BAH, 0E1H, 00BH, 075H, 004H, 072H, 007H
DB 0EBH, 002H, 073H, 003H, 033H, 0C0H, 0C3H, 0F9H, 0C3H, 00FH
DB 0BAH, 0E1H, 00BH, 0C3H, 00FH, 0BAH, 0E1H, 000H, 0C3H, 00FH
DB 0BAH, 0E1H, 006H, 0C3H, 00FH, 0BAH, 0E1H, 007H, 0C3H, 00FH
DB 0BAH, 0E1H, 002H, 0C3H, 0F7H, 0C1H, 041H, 000H, 000H, 000H
DB 075H, 0DDH, 0C3H, 055H, 08BH, 0ECH, 053H, 056H, 08BH, 05DH
DB 008H, 08BH, 075H, 00CH, 00FH, 0B6H, 003H, 03CH, 00FH, 074H
DB 03EH, 03CH, 070H, 00FH, 082H, 0B1H, 000H, 000H, 000H, 03CH
DB 07FH, 077H, 05AH, 0FFH, 0B6H, 0C0H, 000H, 000H, 000H, 050H
DB 0E8H, 055H, 0FFH, 0FFH, 0FFH, 00FH, 0B6H, 043H, 001H, 075H
DB 005H, 083H, 0C3H, 002H, 0EBH, 019H, 00FH, 0BAH, 0F0H, 007H
DB 073H, 005H, 02DH, 080H, 000H, 000H, 000H, 08DH, 05CH, 003H
DB 002H, 00BH, 0D2H, 074H, 006H, 081H, 0E3H, 0FFH, 0FFH, 000H
DB 000H, 0EBH, 073H, 00FH, 0B6H, 043H, 001H, 03CH, 080H, 072H
DB 073H, 03CH, 08FH, 077H, 06FH, 0FFH, 0B6H, 0C0H, 000H, 000H
DB 000H, 050H, 0E8H, 017H, 0FFH, 0FFH, 0FFH, 075H, 005H, 083H
DB 0C3H, 006H, 0EBH, 007H, 08BH, 043H, 002H, 08DH, 05CH, 003H
DB 006H, 0EBH, 04BH, 02CH, 0E0H, 08BH, 08EH, 0ACH, 000H, 000H
DB 000H, 072H, 049H, 03CH, 003H, 077H, 045H, 075H, 006H, 085H
DB 0C9H, 074H, 092H, 0EBH, 032H, 00BH, 0C9H, 074H, 02EH, 048H
DB 075H, 010H, 00FH, 0BAH, 0A6H, 0C0H, 000H, 000H, 000H, 006H
DB 00FH, 083H, 07BH, 0FFH, 0FFH, 0FFH, 0EBH, 01BH, 048H, 075H
DB 010H, 00FH, 0BAH, 0A6H, 0C0H, 000H, 000H, 000H, 006H, 00FH
DB 082H, 068H, 0FFH, 0FFH, 0FFH, 0EBH, 008H, 085H, 0C9H, 00FH
DB 085H, 05EH, 0FFH, 0FFH, 0FFH, 083H, 0C3H, 002H, 08BH, 0C3H
DB 05EH, 05BH, 0C9H, 0C2H, 008H, 000H, 033H, 0C0H, 0EBH, 0F6H
DB 055H, 08BH, 0ECH, 053H, 08BH, 05DH, 008H, 00FH, 0B6H, 003H
DB 03CH, 0EBH, 075H, 015H, 00FH, 0B6H, 043H, 001H, 00FH, 0BAH
DB 0F0H, 007H, 073H, 005H, 02DH, 080H, 000H, 000H, 000H, 08DH
DB 044H, 003H, 002H, 0EBH, 036H, 03CH, 0E9H, 075H, 009H, 08BH
DB 043H, 001H, 08DH, 044H, 003H, 005H, 0EBH, 029H, 03CH, 0FFH
DB 075H, 023H, 00FH, 0B6H, 043H, 001H, 024H, 038H, 0C0H, 0E8H
DB 003H, 03CH, 004H, 075H, 016H, 043H, 0FFH, 075H, 00CH, 053H
DB 0E8H, 01FH, 0FDH, 0FFH, 0FFH, 00BH, 0C0H, 074H, 00AH, 00BH
DB 0D2H, 075H, 002H, 08BH, 000H, 0EBH, 002H, 033H, 0C0H, 05BH
DB 0C9H, 0C2H, 008H, 000H, 055H, 08BH, 0ECH, 053H, 08BH, 05DH
DB 008H, 00FH, 0B6H, 00BH, 080H, 0F9H, 0E8H, 075H, 00CH, 08DH
DB 048H, 005H, 08BH, 053H, 001H, 08DH, 044H, 013H, 005H, 0EBH
DB 032H, 080H, 0F9H, 0FFH, 075H, 02BH, 00FH, 0B6H, 04BH, 001H
DB 080H, 0E1H, 038H, 0C0H, 0E9H, 003H, 080H, 0F9H, 002H, 075H
DB 01CH, 050H, 043H, 0FFH, 075H, 00CH, 053H, 0E8H, 0D2H, 0FCH
DB 0FFH, 0FFH, 00BH, 0C0H, 074H, 006H, 00BH, 0D2H, 075H, 002H
DB 08BH, 000H, 05AH, 08DH, 04CH, 00AH, 002H, 0EBH, 002H, 033H
DB 0C0H, 05BH, 0C9H, 0C2H, 008H, 000H, 055H, 08BH, 0ECH, 08BH
DB 055H, 008H, 00FH, 0B6H, 00CH, 010H, 08BH, 045H, 00CH, 080H
DB 0F9H, 0C3H, 074H, 005H, 080H, 0F9H, 0C2H, 075H, 00AH, 08BH
DB 080H, 0C4H, 000H, 000H, 000H, 08BH, 000H, 0EBH, 002H, 033H
DB 0C0H, 0C9H, 0C2H, 008H, 000H, 058H, 0C3H, 0E8H, 0F9H, 0FFH
DB 0FFH, 0FFH, 0FFH, 073H, 014H, 068H, 002H, 001H, 000H, 000H
DB 08BH, 05BH, 010H, 09DH, 0C3H, 0E8H, 0E7H, 0FFH, 0FFH, 0FFH
DB 055H, 08BH, 0ECH, 053H, 056H, 057H, 08BH, 075H, 008H, 08BH
DB 07DH, 010H, 08BH, 05EH, 00CH, 083H, 07EH, 004H, 000H, 075H
DB 008H, 081H, 03EH, 004H, 000H, 000H, 080H, 074H, 00AH, 0B8H
DB 001H, 000H, 000H, 000H, 0E9H, 0D6H, 000H, 000H, 000H, 08BH
DB 075H, 00CH, 039H, 05EH, 008H, 074H, 00CH, 081H, 08FH, 0C0H
DB 000H, 000H, 000H, 000H, 001H, 000H, 000H, 0EBH, 016H, 0C7H
DB 046H, 01CH, 0C2H, 000H, 000H, 000H, 081H, 0A7H, 0C0H, 000H
DB 000H, 000H, 0FFH, 0FEH, 0FFH, 0FFH, 0E9H, 0AAH, 000H, 000H
DB 000H, 08BH, 046H, 014H, 00BH, 0C0H, 074H, 017H, 083H, 07EH
DB 01CH, 000H, 075H, 006H, 03BH, 0D8H, 075H, 0E0H, 0EBH, 00BH
DB 03BH, 0D8H, 072H, 0DAH, 083H, 0C0H, 00FH, 03BH, 0D8H, 073H
DB 0D3H, 0FFH, 046H, 018H, 0C7H, 046H, 01CH, 000H, 000H, 000H
DB 000H, 053H, 0E8H, 094H, 0FBH, 0FFH, 0FFH, 003H, 0D8H, 057H
DB 053H, 0E8H, 088H, 0FEH, 0FFH, 0FFH, 00BH, 0C0H, 075H, 06CH
DB 057H, 053H, 0E8H, 0AEH, 0FDH, 0FFH, 0FFH, 00BH, 0C0H, 075H
DB 061H, 057H, 053H, 0E8H, 0D0H, 0FEH, 0FFH, 0FFH, 00BH, 0C0H
DB 075H, 056H, 057H, 053H, 0E8H, 017H, 0FFH, 0FFH, 0FFH, 00BH
DB 0C0H, 075H, 04BH, 080H, 03BH, 00FH, 075H, 006H, 080H, 07BH
DB 001H, 034H, 074H, 00BH, 080H, 03BH, 0CDH, 075H, 02EH, 080H
DB 07BH, 001H, 02EH, 075H, 028H, 0E8H, 021H, 0FFH, 0FFH, 0FFH
DB 08BH, 08FH, 0C4H, 000H, 000H, 000H, 08BH, 097H, 0A4H, 000H
DB 000H, 000H, 081H, 0A7H, 0C0H, 000H, 000H, 000H, 0FFH, 0FEH
DB 0FFH, 0FFH, 087H, 001H, 089H, 056H, 010H, 089H, 0B7H, 0A4H
DB 000H, 000H, 000H, 0EBH, 00DH, 08BH, 04DH, 008H, 0C7H, 046H
DB 01CH, 001H, 000H, 000H, 000H, 08BH, 041H, 00CH, 089H, 046H
DB 014H, 033H, 0C0H, 05FH, 05EH, 05BH, 0C9H, 0C2H, 010H, 000H
DB 055H, 08BH, 0ECH, 033H, 0C0H, 08BH, 04DH, 010H, 050H, 050H
DB 050H, 050H, 0E8H, 02BH, 000H, 000H, 000H, 055H, 050H, 0E8H
DB 0DFH, 0FEH, 0FFH, 0FFH, 050H, 064H, 0FFH, 035H, 000H, 000H
DB 000H, 000H, 08BH, 045H, 00CH, 064H, 089H, 025H, 000H, 000H
DB 000H, 000H, 0FFH, 074H, 088H, 0FCH, 049H, 075H, 0F9H, 068H
DB 002H, 001H, 000H, 000H, 09DH, 0FFH, 055H, 008H, 0EBH, 005H
DB 0E8H, 0A2H, 0FEH, 0FFH, 0FFH, 064H, 08FH, 005H, 000H, 000H
DB 000H, 000H, 059H, 059H, 05DH, 059H, 059H, 059H, 05AH, 0C9H
DB 0C2H, 00CH, 000H
; __________________________ 0x549 __________________________