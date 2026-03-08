       ;       Adam Anwar (243DC245L4)
       ;AHMAD  AIDIL HAQEMY BUN ABDULLAH (243DC2462C)

       MOV     R0, #20 ; Store decimal value 20 into R0
       LDR     R1, =0x600D ; Address where the input number will be stored
       STRB    R0, [R1] ; Store the number (as byte) AKA STRB into 0x600D

       LDR     R3, =0 ; R3 = 0, used as comparison target for loop
       LDR     R1, =0x600F ; Start address to store shifted results
       MOV     R4, R0 ; Copy original value into R4 to preserve it

LOOP   
       LSR     R4, R4, #1 ; Logical shift R4 right by 1 bit (divide by 2)
       STRB    R4, [R1], #1 ; Store result and move to next byte address
       CMP     R4, R3 ; Compare shifted value with 0
       BGT     LOOP ; Repeat loop if value still greater than 0


