       ; Adam Anwar (243DC245L4)
       
       LDR     R1, =0x3000
       LDR     R4, =0x1D19E6
       STR     R4, [R1]

       MOV     R5, #0xE
       STRB    R5, [R1]

       LDRB    R2, [R1]
       LDRB    R3, [R1,#2]

       ADDS    R0, R2, R3
       SUBS    R2, R2, R0