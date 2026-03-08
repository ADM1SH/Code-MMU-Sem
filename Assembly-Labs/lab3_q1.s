       ;Adam Anwar (243DC245L4)
       
       LDR     R0, =0x600A

       MOV     R1, #34
       MOV     R2, #0x60
       SUB     R3, R1, R2
       STRB    R3, [R0], #1

       MOV     R4, #0x55
       ADD     R3, R3, R4
       STRB    R3, [R0], #1

       MOV     R5, #4
       SUB     R3, R3, R5
       ADD     R0, R0, #1
       STRB    R3, [R0]