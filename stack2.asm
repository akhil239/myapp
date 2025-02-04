	.file	"stack.c"
	.intel_syntax noprefix
	.text
	.comm	n,4,4
	.comm	stack,8,8
	.comm	top,4,4
	.comm	first,4,4
	.globl	push
	.type	push, @function
push:
.LFB6:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], edi
	mov	eax, DWORD PTR top[rip]
	add	eax, 1
	mov	DWORD PTR top[rip], eax
	mov	eax, DWORD PTR top[rip]
	mov	DWORD PTR top[rip], eax
	mov	rax, QWORD PTR stack[rip]
	mov	edx, DWORD PTR top[rip]
	movsx	rdx, edx
	sal	rdx, 2
	add	rdx, rax
	mov	eax, DWORD PTR -4[rbp]
	mov	DWORD PTR [rdx], eax
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	push, .-push
	.globl	pop
	.type	pop, @function
pop:
.LFB7:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	eax, DWORD PTR top[rip]
	sub	eax, 1
	mov	DWORD PTR top[rip], eax
	mov	eax, DWORD PTR top[rip]
	mov	DWORD PTR top[rip], eax
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	pop, .-pop
	.globl	queuepush
	.type	queuepush, @function
queuepush:
.LFB8:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], edi
	mov	rax, QWORD PTR stack[rip]
	mov	edx, DWORD PTR top[rip]
	movsx	rdx, edx
	sal	rdx, 2
	add	rdx, rax
	mov	eax, DWORD PTR -4[rbp]
	mov	DWORD PTR [rdx], eax
	mov	eax, DWORD PTR top[rip]
	sub	eax, 1
	mov	DWORD PTR top[rip], eax
	mov	eax, DWORD PTR top[rip]
	mov	DWORD PTR top[rip], eax
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	queuepush, .-queuepush
	.globl	queuepop
	.type	queuepop, @function
queuepop:
.LFB9:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	eax, DWORD PTR first[rip]
	sub	eax, 1
	mov	DWORD PTR first[rip], eax
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	queuepop, .-queuepop
	.globl	main
	.type	main, @function
main:
.LFB10:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR n[rip], 5
	mov	eax, DWORD PTR n[rip]
	cdqe
	sal	rax, 2
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR stack[rip], rax
	mov	DWORD PTR top[rip], -1
	mov	DWORD PTR first[rip], -1
	mov	rax, QWORD PTR stack[rip]
	mov	edx, DWORD PTR top[rip]
	movsx	rdx, edx
	sal	rdx, 2
	add	rax, rdx
	mov	DWORD PTR [rax], 5
	mov	rax, QWORD PTR stack[rip]
	mov	edx, DWORD PTR top[rip]
	movsx	rdx, edx
	sal	rdx, 2
	sub	rdx, 4
	add	rax, rdx
	mov	DWORD PTR [rax], 500
	mov	eax, 0
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
