GroupN_Q2 
          MOV     R0, #5 ; Move even or odd value into R1 (User Input)

          ANDS    R1, R0, #1 ; Calculates and sets flags
          BEQ     EVEN ; If flag Z = 1, then go to label EVEN
          BNE     ODD ; Else if flag Z != 1, then go to label ODD

          ;       If R1 = 0, then R0 is an even number, because
          ;       after the logical operation the lSB of the result
          ;       value will always be 0
          ;
          ;       For example:
          ;       0100 (4)
          ;       0001 (1)
          ;       ----
          ;       0000 (0) <--
          ;
          ;       If R1 = 1, then R0 is an odd number, because
          ;       after the logical operation the lSB of the result
          ;       value will always be 1
          ;
          ;       For example:
          ;       0101 (5)
          ;       0001 (1)
          ;       ----
          ;       0001 (1) <--

EVEN      
          ;       Value in R0 is an even number
          BEQ     EXIT

ODD       
          ;       Value in R0 is an odd number
          BNE     EXIT

EXIT      
          MOV     R0, #0
          MOV     R1, #0
          ;       Exited