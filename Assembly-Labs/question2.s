       ;Adam   Anwar (243DC245L4)

       MOV     r0, #0x2A
       MOV     r1, #0x12
       MOV     r2, #55

       SUB     r3, r2, r1
       ADD     r3, r3, r0

       LDR     r4, =0x1000
       STR     r3, [r4]