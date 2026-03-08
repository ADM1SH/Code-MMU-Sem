           ;       Adam Anwar (243DC245L4)
           ;AHMAD  AIDIL HAQEMY BUN ABDULLAH (243DC2462C)

           LDR     R6, =0x5000 ; Start address in memory to store values
           MOV     R0, #0xA ; Initial value to store (starting from 0xA)
           MOV     R1, #0 ; Loop counter = 0

STORE_LOOP ;       Loop to store 6 values (0xA to 0xF)
           STR     R0, [R6], #4 ; Store current value into memory, increment address by 4 bytes
           ADD     R0, R0, #1 ; Move to the next value
           ADD     R1, R1, #1 ; Increment counter
           CMP     R1, #6 ; Have we stored 6 values?
           BNE     STORE_LOOP ; If not, continue loop

           LDR     R7, =0x5000 ; Source address for copying
           LDR     R8, =0x8000 ; Destination address for copied values
           MOV     R1, #0 ; Reset loop counter to 0

COPY_LOOP  ;       Loop to copy 6 values from 0x5000 to 0x8000
           LDR     R0, [R7], #4 ; Load value from source, increment address
           STR     R0, [R8], #4 ; Store value to destination, increment address
           ADD     R1, R1, #1 ; Increment counter
           CMP     R1, #6 ; Have we copied all 6 values?
           BNE     COPY_LOOP ; If not, continue copying