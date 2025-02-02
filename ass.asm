section .data
    msg db "The number is: ", 0

section .bss
    num resb 10           ; Reserve 10 bytes for the number string

section .text
    global _start

_start:
    ; The integer we want to print
    mov rsi, 12345        ; The integer to print

    ; Convert integer to string
    mov rbx, 10           ; Set divisor to 10 (decimal base)
    mov rdi, num + 9      ; Set rdi to the last byte of the num buffer (reverse order)
    mov byte [rdi], 0     ; Null-terminate the string
convert:
    dec rdi               ; Move to previous byte in buffer
    xor rdx, rdx          ; Clear rdx (important for division)
    div rbx               ; Divide rsi by 10, quotient in rsi, remainder (digit) in rdx
    add dl, '0'           ; Convert remainder (digit) to ASCII ('0' -> 48 in ASCII)
    mov [rdi], dl         ; Store ASCII character in the buffer
    test rsi, rsi         ; Check if quotient is zero
    jnz convert           ; If not, continue converting

    ; Print "The number is: "
    mov rax, 1            ; syscall number for sys_write
    mov rdi, 1            ; file descriptor (stdout)
    mov rsi, msg          ; pointer to the string
    mov rdx, 15           ; length of the string
    syscall

    ; Print the number
    mov rax, 1            ; syscall number for sys_write
    mov rdi, 1            ; file descriptor (stdout)
    mov rsi, num          ; pointer to the number string
    mov rdx, 10           ; length of the string (max 10 digits)
    syscall

    ; Exit the program
    mov rax, 60           ; syscall number for sys_exit
    xor rdi, rdi          ; exit code 0
    syscall
