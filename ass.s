section .data
    hello db 'Hello, World!',0      ; Null-terminated string

section .text
    global _start                    ; Entry point for the program

_start:
    ; Write "Hello, World!" to stdout
    mov rax, 1                       ; syscall number for sys_write (1)
    mov rdi, 1                       ; file descriptor 1 is stdout
    mov rsi, hello                   ; address of the "Hello, World!" string
    mov rdx, 13                      ; length of the string
    syscall                          ; invoke syscall

    ; Exit program
    mov rax, 60                      ; syscall number for sys_exit (60)
    xor rdi, rdi                     ; return code 0
    syscall                          ; invoke syscall
