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
	.globl	trie_create
	.type	trie_create, @function
trie_create:
.LFB27:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$216, %edi
	call	malloc@PLT
	movl	$0, 208(%rax)
	movq	%rax, %rdx
	leaq	208(%rax), %rcx
	.p2align 4
.L36:
	movq	$0, (%rdx)
	addq	$8, %rdx
	cmpq	%rcx, %rdx
	jne	.L36
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE27:
	.size	trie_create, .-trie_create
	.globl	trie_insert
	.type	trie_insert, @function
trie_insert:
.LFB28:
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
	movq	%rdi, %r12
	movzbl	(%rsi), %eax
	testb	%al, %al
	je	.L40
	leaq	1(%rsi), %rbp
	jmp	.L42
	.p2align 6
.L41:
	movslq	%ebx, %rbx
	movq	(%r12,%rbx,8), %r12
	addq	$1, %rbp
	movzbl	-1(%rbp), %eax
	testb	%al, %al
	je	.L40
.L42:
	movsbl	%al, %eax
	leal	-97(%rax), %ebx
	movslq	%ebx, %rax
	cmpq	$0, (%r12,%rax,8)
	jne	.L41
	call	trie_create
	movq	%rax, %rdx
	movslq	%ebx, %rax
	movq	%rdx, (%r12,%rax,8)
	jmp	.L41
.L40:
	movl	$1, 208(%r12)
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE28:
	.size	trie_insert, .-trie_insert
	.globl	trie_search
	.type	trie_search, @function
trie_search:
.LFB29:
	.cfi_startproc
	movzbl	(%rsi), %eax
	testb	%al, %al
	je	.L46
	addq	$1, %rsi
	.p2align 5
.L48:
	movsbl	%al, %eax
	subl	$97, %eax
	cltq
	movq	(%rdi,%rax,8), %rdi
	testq	%rdi, %rdi
	je	.L50
	addq	$1, %rsi
	movzbl	-1(%rsi), %eax
	testb	%al, %al
	jne	.L48
.L49:
	cmpl	$0, 208(%rdi)
	setne	%al
	movzbl	%al, %eax
	ret
.L46:
	testq	%rdi, %rdi
	jne	.L49
	movl	$0, %eax
	ret
.L50:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE29:
	.size	trie_search, .-trie_search
	.globl	trie_free
	.type	trie_free, @function
trie_free:
.LFB30:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L58
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %r12
	movq	%rdi, %rbx
	leaq	208(%rdi), %rbp
.L55:
	movq	(%rbx), %rdi
	call	trie_free
	addq	$8, %rbx
	cmpq	%rbp, %rbx
	jne	.L55
	movq	%r12, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L58:
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	ret
	.cfi_endproc
.LFE30:
	.size	trie_free, .-trie_free
	.globl	avl_height
	.type	avl_height, @function
avl_height:
.LFB31:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L63
	movl	24(%rdi), %eax
	ret
.L63:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE31:
	.size	avl_height, .-avl_height
	.globl	avl_get_balance
	.type	avl_get_balance, @function
avl_get_balance:
.LFB32:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L68
	movq	8(%rdi), %rax
	testq	%rax, %rax
	je	.L69
	movl	24(%rax), %eax
.L66:
	movq	16(%rdi), %rdx
	testq	%rdx, %rdx
	je	.L70
	movl	24(%rdx), %edx
.L67:
	subl	%edx, %eax
	ret
.L69:
	movl	$0, %eax
	jmp	.L66
.L70:
	movl	$0, %edx
	jmp	.L67
.L68:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE32:
	.size	avl_get_balance, .-avl_get_balance
	.globl	avl_create_node
	.type	avl_create_node, @function
avl_create_node:
.LFB33:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx
	movl	$32, %edi
	call	malloc@PLT
	movl	%ebx, (%rax)
	movq	$0, 16(%rax)
	movq	$0, 8(%rax)
	movl	$1, 24(%rax)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE33:
	.size	avl_create_node, .-avl_create_node
	.globl	avl_right_rotate
	.type	avl_right_rotate, @function
avl_right_rotate:
.LFB34:
	.cfi_startproc
	movq	8(%rdi), %rax
	movq	16(%rax), %rdx
	movq	%rdi, 16(%rax)
	movq	%rdx, 8(%rdi)
	testq	%rdx, %rdx
	je	.L74
	movl	24(%rdx), %ecx
	movq	16(%rdi), %rdx
	testq	%rdx, %rdx
	je	.L84
.L83:
	movl	24(%rdx), %edx
.L75:
	cmpl	%ecx, %edx
	jge	.L76
	leal	1(%rcx), %edx
.L77:
	movl	%edx, 24(%rdi)
	movq	8(%rax), %rdx
	testq	%rdx, %rdx
	je	.L78
	movl	24(%rdx), %ecx
	movq	16(%rax), %rdx
	testq	%rdx, %rdx
	je	.L85
.L82:
	movl	24(%rdx), %edx
.L79:
	cmpl	%ecx, %edx
	jge	.L80
	leal	1(%rcx), %edx
.L81:
	movl	%edx, 24(%rax)
	ret
.L84:
	movl	$0, %edx
	jmp	.L75
.L87:
	movl	$0, %edx
.L76:
	addl	$1, %edx
	jmp	.L77
.L85:
	movl	$0, %edx
	jmp	.L79
.L86:
	movl	$0, %edx
.L80:
	addl	$1, %edx
	jmp	.L81
.L78:
	movq	16(%rax), %rdx
	testq	%rdx, %rdx
	je	.L86
	movl	$0, %ecx
	jmp	.L82
.L74:
	movq	16(%rdi), %rdx
	testq	%rdx, %rdx
	je	.L87
	movl	$0, %ecx
	jmp	.L83
	.cfi_endproc
.LFE34:
	.size	avl_right_rotate, .-avl_right_rotate
	.globl	avl_left_rotate
	.type	avl_left_rotate, @function
avl_left_rotate:
.LFB35:
	.cfi_startproc
	movq	16(%rdi), %rax
	movq	8(%rax), %rdx
	movq	%rdi, 8(%rax)
	movq	%rdx, 16(%rdi)
	movq	8(%rdi), %rcx
	testq	%rcx, %rcx
	je	.L90
	movl	24(%rcx), %ecx
	testq	%rdx, %rdx
	je	.L100
.L99:
	movl	24(%rdx), %edx
.L91:
	cmpl	%ecx, %edx
	jge	.L92
	leal	1(%rcx), %edx
.L93:
	movl	%edx, 24(%rdi)
	movq	8(%rax), %rdx
	testq	%rdx, %rdx
	je	.L94
	movl	24(%rdx), %ecx
	movq	16(%rax), %rdx
	testq	%rdx, %rdx
	je	.L101
.L98:
	movl	24(%rdx), %edx
.L95:
	cmpl	%ecx, %edx
	jge	.L96
	leal	1(%rcx), %edx
.L97:
	movl	%edx, 24(%rax)
	ret
.L100:
	movl	$0, %edx
	jmp	.L91
.L103:
	movl	$0, %edx
.L92:
	addl	$1, %edx
	jmp	.L93
.L101:
	movl	$0, %edx
	jmp	.L95
.L102:
	movl	$0, %edx
.L96:
	addl	$1, %edx
	jmp	.L97
.L94:
	movq	16(%rax), %rdx
	testq	%rdx, %rdx
	je	.L102
	movl	$0, %ecx
	jmp	.L98
.L90:
	testq	%rdx, %rdx
	je	.L103
	movl	$0, %ecx
	jmp	.L99
	.cfi_endproc
.LFE35:
	.size	avl_left_rotate, .-avl_left_rotate
	.globl	avl_insert
	.type	avl_insert, @function
avl_insert:
.LFB36:
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
	movl	%esi, %ebp
	testq	%rdi, %rdi
	je	.L122
	movq	%rdi, %rbx
	movl	(%rdi), %eax
	cmpl	%esi, %eax
	jg	.L123
	jl	.L124
.L120:
	movq	%rbx, %rax
	addq	$8, %rsp
	.cfi_remember_state
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
.L122:
	.cfi_restore_state
	movl	%esi, %edi
	call	avl_create_node
	movq	%rax, %rbx
	jmp	.L120
.L123:
	movq	8(%rdi), %rdi
	call	avl_insert
	movq	%rax, 8(%rbx)
.L109:
	movq	8(%rbx), %r12
	testq	%r12, %r12
	je	.L110
	movl	24(%r12), %edx
	movq	16(%rbx), %r13
	testq	%r13, %r13
	je	.L118
.L117:
	movl	24(%r13), %eax
.L111:
	cmpl	%edx, %eax
	jge	.L112
	leal	1(%rdx), %eax
.L113:
	movl	%eax, 24(%rbx)
	movq	%rbx, %rdi
	call	avl_get_balance
	cmpl	$1, %eax
	jle	.L114
	cmpl	%ebp, (%r12)
	jg	.L125
	cmpl	%ebp, (%r12)
	jge	.L120
	movq	%r12, %rdi
	call	avl_left_rotate
	movq	%rax, 8(%rbx)
	movq	%rbx, %rdi
	call	avl_right_rotate
	movq	%rax, %rbx
	jmp	.L120
.L124:
	movq	16(%rdi), %rdi
	call	avl_insert
	movq	%rax, 16(%rbx)
	jmp	.L109
.L118:
	movl	$0, %eax
	jmp	.L111
.L119:
	movl	$0, %eax
.L112:
	addl	$1, %eax
	jmp	.L113
.L125:
	movq	%rbx, %rdi
	call	avl_right_rotate
	movq	%rax, %rbx
	jmp	.L120
.L114:
	cmpl	$-1, %eax
	jge	.L120
	movl	0(%r13), %eax
	cmpl	%ebp, %eax
	jl	.L126
	jle	.L120
	movq	%r13, %rdi
	call	avl_right_rotate
	movq	%rax, 16(%rbx)
	movq	%rbx, %rdi
	call	avl_left_rotate
	movq	%rax, %rbx
	jmp	.L120
.L126:
	movq	%rbx, %rdi
	call	avl_left_rotate
	movq	%rax, %rbx
	jmp	.L120
.L110:
	movq	16(%rbx), %r13
	testq	%r13, %r13
	je	.L119
	movl	$0, %edx
	jmp	.L117
	.cfi_endproc
.LFE36:
	.size	avl_insert, .-avl_insert
	.globl	avl_inorder
	.type	avl_inorder, @function
avl_inorder:
.LFB37:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L130
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	8(%rdi), %rdi
	call	avl_inorder
	movl	(%rbx), %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	16(%rbx), %rdi
	call	avl_inorder
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L130:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE37:
	.size	avl_inorder, .-avl_inorder
	.globl	avl_free
	.type	avl_free, @function
avl_free:
.LFB38:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L136
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	8(%rdi), %rdi
	call	avl_free
	movq	16(%rbx), %rdi
	call	avl_free
	movq	%rbx, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L136:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE38:
	.size	avl_free, .-avl_free
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
