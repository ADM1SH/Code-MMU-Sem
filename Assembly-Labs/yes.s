; Group members: [Your Names Here]
    AREA    MyProgram, CODE, READONLY  ; Line 2 fixed
    ENTRY

; ==== Question 1(a): Store data at 0x5000 ====
Q1a
    LDR R1, =0x5000
    MOV R0, #0x02
    STRB R0, [R1], #1
    MOV R0, #0x0E
    STRB R0, [R1], #1
    MOV R0, #0x08
    STRB R0, [R1], #1
    MOV R0, #0x07
    STRB R0, [R1], #1
    MOV R0, #0x0F
    STRB R0, [R1], #1
    MOV R0, #0x04
    STRB R0, [R1]

; ==== Question 1(b): Sum, Max, Min ====
Q1b
    LDR R1, =0x5000
    MOV R2, #6            ; Counter for 6 elements
    LDRB R3, [R1], #1     ; Load first value
    MOV R4, R3            ; Initialize min
    MOV R5, R3            ; Initialize max
    MOV R6, R3            ; Initialize sum

loop
    SUBS R2, R2, #1       ; Decrement counter
    BEQ store_results      ; Exit loop if counter=0
    LDRB R3, [R1], #1     ; Load next value
    ADD R6, R6, R3        ; Add to sum
    CMP R3, R4            ; Compare with min
    MOVLT R4, R3          ; Update min if smaller
    CMP R3, R5            ; Compare with max
    MOVGT R5, R3          ; Update max if larger
    B loop

store_results
    LDR R1, =0x6000
    STR R6, [R1]          ; Store sum
    LDR R1, =0x6004
    STR R5, [R1]          ; Store max
    LDR R1, =0x6008
    STR R4, [R1]          ; Store min

; ==== Question 1(c): Search Value ====
Q1c
    ; Set input value directly in register
    MOV R0, #0x37         ; ASCII '7' - change this value to test
    ; Conversion code remains the same
    CMP R0, #0x39         ; Compare with '9'
    BLE digit
    SUB R2, R0, #0x37     ; Convert A-F to value
    B start_search
digit
    SUB R2, R0, #0x30     ; Convert 0-9 to value

start_search
    LDR R1, =0x5000       ; Data start
    MOV R3, #0            ; Search counter
    MOV R4, #6            ; Elements count

search_loop
    LDRB R5, [R1], #1     ; Load data byte
    ADD R3, R3, #1        ; Increment counter
    CMP R5, R2            ; Compare with input
    BEQ found             ; Match found
    SUBS R4, R4, #1       ; Decrement remaining
    BNE search_loop       ; Continue if more

    ; No match
    LDR R1, =0x700B
    MOV R0, #0x0B
    STRB R0, [R1]         ; Store 0xB at 0x700B
    B save_count

found
    LDR R1, =0x700A
    MOV R0, #0x0A
    STRB R0, [R1]         ; Store 0xA at 0x700A

save_count
    LDR R1, =0x700C
    STRB R3, [R1]         ; Store search count

; Safe exit
exit
    B exit                ; Line 95 fixed