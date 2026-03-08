       ;((A6H  + 19) / 8) x 4H, Address 1000, 1001, 1002

       LDR     R0, =0x1000 ; Initialize R0 with address 1000
       MOV     R1, #0xA6 ; Initialize R1 with data A6H
       ADD     R1, R1, #19 ; Calculates (A6H + 19) into R1
       STRB    R1, [R0], #1 ; Stores into address 1000 and post increment by 1

       LSR     R1, R1, #3 ; Calculates R1 / 8 into R1 (#n means 2^n)
       STRB    R1, [R0], #1 ; Stores into address 1001 and post increment by 1

       LSL     R1, R1, #2 ; Calculates R1 x 4 into R1
       STRB    R1, [R0] ; Stores into address 1002