	.file	"Tree.c"
	.text
	.globl	bst_insert
	.type	bst_insert, @function
bst_insert:
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
	movl	%esi, %ebp
	testq	%rdi, %rdi
	je	.L6
	movq	%rdi, %rbx
	movl	(%rdi), %eax
	cmpl	%esi, %eax
	jg	.L7
	jl	.L8
.L3:
	movq	%rbx, %rax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, %rbx
	movl	%ebp, (%rax)
	movq	$0, 16(%rax)
	movq	$0, 8(%rax)
	jmp	.L3
.L7:
	movq	8(%rdi), %rdi
	call	bst_insert
	movq	%rax, 8(%rbx)
	jmp	.L3
.L8:
	movq	16(%rdi), %rdi
	call	bst_insert
	movq	%rax, 16(%rbx)
	jmp	.L3
	.cfi_endproc
.LFE22:
	.size	bst_insert, .-bst_insert
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d "
	.text
	.globl	bst_inorder
	.type	bst_inorder, @function
bst_inorder:
.LFB23:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L12
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	8(%rdi), %rdi
	call	bst_inorder
	movl	(%rbx), %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	16(%rbx), %rdi
	call	bst_inorder
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE23:
	.size	bst_inorder, .-bst_inorder
	.globl	bst_free
	.type	bst_free, @function
bst_free:
.LFB24:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L18
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	8(%rdi), %rdi
	call	bst_free
	movq	16(%rbx), %rdi
	call	bst_free
	movq	%rbx, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L18:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE24:
	.size	bst_free, .-bst_free
	.globl	nary_create
	.type	nary_create, @function
nary_create:
.LFB25:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	%edi, %r12d
	movl	%esi, %ebp
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, %rbx
	movl	%r12d, (%rax)
	movl	%ebp, 4(%rax)
	movslq	%ebp, %r12
	salq	$3, %r12
	movq	%r12, %rdi
	call	malloc@PLT
	movq	%rax, 8(%rbx)
	testl	%ebp, %ebp
	jle	.L21
	movq	%rax, %rdx
	addq	%r12, %rax
	.p2align 4
.L23:
	movq	$0, (%rdx)
	addq	$8, %rdx
	cmpq	%rax, %rdx
	jne	.L23
.L21:
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE25:
	.size	nary_create, .-nary_create
	.globl	nary_free
	.type	nary_free, @function
nary_free:
.LFB26:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L32
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbx
	cmpl	$0, 4(%rdi)
	jle	.L28
	movl	$0, %ebp
.L29:
	movq	8(%rbx), %rax
	movq	(%rax,%rbp,8), %rdi
	call	nary_free
	addq	$1, %rbp
	cmpl	%ebp, 4(%rbx)
	jg	.L29
.L28:
	movq	8(%rbx), %rdi
	call	free@PLT
	movq	%rbx, %rdi
	call	free@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L32:
	.cfi_restore 3
	.cfi_restore 6
	ret
	.cfi_endproc
.LFE26:
	.size	nary_free, .-nary_free
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
