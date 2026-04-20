	.file	"LinkedList.c"
	.text
	.globl	insert_singly
	.type	insert_singly, @function
insert_singly:
.LFB22:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbx
	movl	%esi, %ebp
	movl	$16, %edi
	call	malloc@PLT
	movl	%ebp, (%rax)
	movq	%rbx, 8(%rax)
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	insert_singly, .-insert_singly
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d "
	.text
	.globl	print_singly
	.type	print_singly, @function
print_singly:
.LFB23:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testq	%rdi, %rdi
	je	.L4
	movq	%rdi, %rbx
	leaq	.LC0(%rip), %rbp
.L5:
	movl	(%rbx), %esi
	movq	%rbp, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	8(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.L5
.L4:
	movl	$10, %edi
	call	putchar@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	print_singly, .-print_singly
	.globl	free_singly
	.type	free_singly, @function
free_singly:
.LFB24:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	testq	%rdi, %rdi
	je	.L8
.L10:
	movq	%rbx, %rdi
	movq	8(%rbx), %rbx
	call	free@PLT
	testq	%rbx, %rbx
	jne	.L10
.L8:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	free_singly, .-free_singly
	.globl	insert_doubly
	.type	insert_doubly, @function
insert_doubly:
.LFB25:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbx
	movl	%esi, %ebp
	movl	$24, %edi
	call	malloc@PLT
	movl	%ebp, (%rax)
	movq	%rbx, 8(%rax)
	movq	$0, 16(%rax)
	testq	%rbx, %rbx
	je	.L13
	movq	%rax, 16(%rbx)
.L13:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE25:
	.size	insert_doubly, .-insert_doubly
	.globl	print_doubly
	.type	print_doubly, @function
print_doubly:
.LFB26:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testq	%rdi, %rdi
	je	.L17
	movq	%rdi, %rbx
	leaq	.LC0(%rip), %rbp
.L18:
	movl	(%rbx), %esi
	movq	%rbp, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	8(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.L18
.L17:
	movl	$10, %edi
	call	putchar@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	print_doubly, .-print_doubly
	.globl	free_doubly
	.type	free_doubly, @function
free_doubly:
.LFB27:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	testq	%rdi, %rdi
	je	.L21
.L23:
	movq	%rbx, %rdi
	movq	8(%rbx), %rbx
	call	free@PLT
	testq	%rbx, %rbx
	jne	.L23
.L21:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE27:
	.size	free_doubly, .-free_doubly
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
