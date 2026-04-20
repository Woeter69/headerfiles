	.file	"Stack.c"
	.text
	.globl	create_stack
	.type	create_stack, @function
create_stack:
.LFB11:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	call	malloc@PLT
	movq	$0, (%rax)
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	create_stack, .-create_stack
	.globl	push
	.type	push, @function
push:
.LFB12:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	(%rdi), %rdi
	call	insert_singly@PLT
	movq	%rax, (%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	push, .-push
	.globl	pop
	.type	pop, @function
pop:
.LFB13:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	(%rdi), %rax
	testq	%rax, %rax
	je	.L7
	movl	(%rax), %ebx
	movq	8(%rax), %rdx
	movq	%rdx, (%rdi)
	movq	%rax, %rdi
	call	free@PLT
.L5:
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L7:
	.cfi_restore_state
	movl	$-1, %ebx
	jmp	.L5
	.cfi_endproc
.LFE13:
	.size	pop, .-pop
	.globl	is_empty_stack
	.type	is_empty_stack, @function
is_empty_stack:
.LFB14:
	.cfi_startproc
	cmpq	$0, (%rdi)
	sete	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE14:
	.size	is_empty_stack, .-is_empty_stack
	.globl	free_stack
	.type	free_stack, @function
free_stack:
.LFB15:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	(%rdi), %rdi
	call	free_singly@PLT
	movq	%rbx, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE15:
	.size	free_stack, .-free_stack
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
