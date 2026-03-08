       ;       ADAM ANWAR

       MOV     R0, #0x1A
       MOV     R1, #0x1000
       STR     R0, [R1]

       EOR     R0, R0, R0

       LDR     R2, [R1]
       MVN     R3, R2
       ADD     R4, R3, #1

       AND     R0, R3, #0xFF
       STR     R0, [R1, #4]

       AND     R0, R4, #0xFF
       STR     R0, [R1, #8]

       MOV     R0, #0x0F
       STR     R0, [R1, #12]

       MOV     R0, #0x1A
       AND     R6, R0, #0x0F

       MOV     R7, #0x00
       MOV     R5, #0x4000
       STR     R6, [R5, #8]
       STR     R7, [R5, #12]
