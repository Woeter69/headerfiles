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
	.globl	is_valid_parentheses
	.type	is_valid_parentheses, @function
is_valid_parentheses:
.LFB16:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	movq	%rdi, %rbp
	call	create_stack
	movq	%rax, %r12
	movzbl	0(%rbp), %ebx
	testb	%bl, %bl
	je	.L13
	addq	$1, %rbp
	jmp	.L23
.L24:
	movsbl	%bl, %esi
	movq	%r12, %rdi
	call	push
.L16:
	addq	$1, %rbp
	movzbl	-1(%rbp), %ebx
	testb	%bl, %bl
	je	.L13
.L23:
	movl	%ebx, %eax
	andl	$-33, %eax
	cmpb	$40, %bl
	je	.L24
	cmpb	$91, %al
	je	.L24
	cmpb	$41, %bl
	sete	%r13b
	cmpb	$93, %al
	je	.L25
	testb	%r13b, %r13b
	je	.L16
.L25:
	cmpq	$0, (%r12)
	je	.L30
	movq	%r12, %rdi
	call	pop
	cmpl	$40, %eax
	je	.L26
	testb	%r13b, %r13b
	jne	.L20
.L26:
	cmpb	$125, %bl
	jne	.L27
	cmpl	$123, %eax
	jne	.L20
.L27:
	cmpl	$91, %eax
	je	.L16
	cmpb	$93, %bl
	jne	.L16
.L20:
	movq	%r12, %rdi
	call	free_stack
	movl	$0, %ebx
	jmp	.L12
.L30:
	movq	%r12, %rdi
	call	free_stack
	movl	$0, %ebx
	jmp	.L12
.L13:
	cmpq	$0, (%r12)
	sete	%bl
	movzbl	%bl, %ebx
	movq	%r12, %rdi
	call	free_stack
.L12:
	movl	%ebx, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE16:
	.size	is_valid_parentheses, .-is_valid_parentheses
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
