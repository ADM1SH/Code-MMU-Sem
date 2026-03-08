       ;Adam   Anwar (243DC245L4)

       MOV     r0, #30H ;RO = 30H
       MOV     r1, #39H; R1 = 39

       SUB     r2, r0, r1
       ADD     r3, r2, #5H

       LDR     r3, =0x6000
       STR     r2, [r3]

