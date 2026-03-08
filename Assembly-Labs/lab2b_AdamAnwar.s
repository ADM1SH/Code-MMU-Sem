       ;ADAM ANWAR
       
       MOV     R0, #8
       LDR     R1, =0x5000
       MOV     R2, #0

LOOP1  
       STR     R0, [R1, R2, LSL #2]
       LSL     R0, R0, #1
       ADD     R2, R2, #1
       CMP     R2, #4
       BLT     LOOP1

       MOV     R0, #0x80
       LDR     R1, =0x5010
       MOV     R2, #0

LOOP2  
       STR     R0, [R1, R2, LSL #2]
       LSL     R0, R0, #1
       ADD     R2, R2, #1
       CMP     R2, #4
       BLT     LOOP2
