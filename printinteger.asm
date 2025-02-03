SYS_WRITE   equ     1 
SYS_EXIT    equ     60
STDOUT      equ     1

global _start

section .data
    ; output string (0x0A = newline
    output      db "0", 0x0A
    ; length of output
    output_len  equ $-output

section .text
_start:
    ; using al instead of r10 so when we write it into the string it will only write one byte
    mov al, 9
    add al, '0' ; single quotes use the character's ascii value as a number

    ; move al into the first character of output
    ; +1 would be the 2nd index, you could also add a register here
    mov [output+0], al

    ; print
    mov rax, SYS_WRITE
    mov rdi, STDOUT
    ; moving output into rsi would write the pointer to the address of output
    ; most values passed into rsi for syscalls are pointers
    mov rsi, output
    mov rdx, output_len
    syscall

    ; exit
    mov rax, SYS_EXIT
    xor rdi, rdi
    syscall
