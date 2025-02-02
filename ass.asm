section .data
    num db "42", 0          ; String representation of the integer
    len equ $ - num         ; Length of the string

section .text
    global _start           ; Entry point for the program

_start:
    ; sys_write (system call number 1)
    mov rax, 1              ; sys_write
    mov rdi, 1              ; file descriptor 1 (stdout)
    mov rsi, num            ; address of the string to print
    mov rdx, len            ; length of the string
    syscall                 ; invoke system call

    ; sys_exit (system call number 60)
    mov rax, 60             ; sys_exit
    xor rdi, rdi            ; exit status 0
    syscall                 ; invoke system call
