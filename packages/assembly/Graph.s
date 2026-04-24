	.file	"Graph.c"
	.text
	.globl	comp_edge
	.type	comp_edge, @function
comp_edge:
.LFB29:
	.cfi_startproc
	movl	8(%rdi), %eax
	subl	8(%rsi), %eax
	ret
	.cfi_endproc
.LFE29:
	.size	comp_edge, .-comp_edge
	.globl	create_graph
	.type	create_graph, @function
create_graph:
.LFB22:
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
	movl	%edi, %ebp
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, %rbx
	movl	%ebp, (%rax)
	movslq	%ebp, %r12
	salq	$3, %r12
	movq	%r12, %rdi
	call	malloc@PLT
	movq	%rax, 8(%rbx)
	testl	%ebp, %ebp
	jle	.L2
	movq	%rax, %rdx
	addq	%r12, %rax
	.p2align 4
.L4:
	movq	$0, (%rdx)
	addq	$8, %rdx
	cmpq	%rax, %rdx
	jne	.L4
.L2:
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	create_graph, .-create_graph
	.globl	add_edge
	.type	add_edge, @function
add_edge:
.LFB23:
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
	movl	%esi, %r13d
	movl	%edx, %ebx
	movl	%ecx, %r12d
	movl	$16, %edi
	call	malloc@PLT
	movl	%ebx, (%rax)
	movl	%r12d, 4(%rax)
	movslq	%r13d, %rcx
	movq	8(%rbp), %rdx
	leaq	(%rdx,%rcx,8), %rdx
	movq	(%rdx), %rcx
	movq	%rcx, 8(%rax)
	movq	%rax, (%rdx)
	movl	$16, %edi
	call	malloc@PLT
	movl	%r13d, (%rax)
	movl	%r12d, 4(%rax)
	movslq	%ebx, %rbx
	movq	8(%rbp), %rdx
	leaq	(%rdx,%rbx,8), %rdx
	movq	(%rdx), %rcx
	movq	%rcx, 8(%rax)
	movq	%rax, (%rdx)
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
.LFE23:
	.size	add_edge, .-add_edge
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"BFS: "
.LC1:
	.string	"%d "
	.text
	.globl	bfs
	.type	bfs, @function
bfs:
.LFB24:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	movq	%rdi, %r15
	movl	%esi, %ebx
	movslq	(%rdi), %r12
	movl	$4, %esi
	movq	%r12, %rdi
	call	calloc@PLT
	movq	%rax, %rbp
	leaq	0(,%r12,4), %rdi
	call	malloc@PLT
	movq	%rax, %r12
	movslq	%ebx, %rax
	movl	$1, 0(%rbp,%rax,4)
	movl	%ebx, (%r12)
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %r14d
	movl	$1, %ebx
	jmp	.L13
	.p2align 5
.L11:
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L10
.L12:
	movl	(%rax), %edx
	movslq	%edx, %rcx
	leaq	0(%rbp,%rcx,4), %rcx
	cmpl	$0, (%rcx)
	jne	.L11
	movl	$1, (%rcx)
	movslq	%ebx, %rcx
	movl	%edx, (%r12,%rcx,4)
	leal	1(%rbx), %ebx
	jmp	.L11
.L10:
	addq	$1, %r14
	cmpl	%r14d, %ebx
	jle	.L17
.L13:
	movl	(%r12,%r14,4), %r13d
	movl	%r13d, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movslq	%r13d, %r13
	movq	8(%r15), %rax
	movq	(%rax,%r13,8), %rax
	testq	%rax, %rax
	jne	.L12
	jmp	.L10
.L17:
	movl	$10, %edi
	call	putchar@PLT
	movq	%rbp, %rdi
	call	free@PLT
	movq	%r12, %rdi
	call	free@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	bfs, .-bfs
	.globl	dfs_util
	.type	dfs_util, @function
dfs_util:
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
	movq	%rdi, %r12
	movq	%rdx, %rbp
	movslq	%esi, %rbx
	movl	$1, (%rdx,%rbx,4)
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	8(%r12), %rax
	movq	(%rax,%rbx,8), %rbx
	testq	%rbx, %rbx
	jne	.L21
.L18:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 5
.L20:
	.cfi_restore_state
	movq	8(%rbx), %rbx
	testq	%rbx, %rbx
	je	.L18
.L21:
	movl	(%rbx), %esi
	movslq	%esi, %rax
	cmpl	$0, 0(%rbp,%rax,4)
	jne	.L20
	movq	%rbp, %rdx
	movq	%r12, %rdi
	call	dfs_util
	jmp	.L20
	.cfi_endproc
.LFE25:
	.size	dfs_util, .-dfs_util
	.section	.rodata.str1.1
.LC2:
	.string	"DFS: "
	.text
	.globl	dfs
	.type	dfs, @function
dfs:
.LFB26:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbp
	movl	%esi, %r14d
	movslq	(%rdi), %rdi
	movl	$4, %esi
	call	calloc@PLT
	movq	%rax, %rbx
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdx
	movl	%r14d, %esi
	movq	%rbp, %rdi
	call	dfs_util
	movl	$10, %edi
	call	putchar@PLT
	movq	%rbx, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	dfs, .-dfs
	.globl	find
	.type	find, @function
find:
.LFB27:
	.cfi_startproc
	movslq	%esi, %rax
	movl	(%rdi,%rax,4), %edx
	movl	%esi, %eax
	cmpl	%esi, %edx
	je	.L30
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	%edx, %esi
	call	find
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
.L30:
	ret
	.cfi_endproc
.LFE27:
	.size	find, .-find
	.globl	Union
	.type	Union, @function
Union:
.LFB28:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
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
	movq	%rdi, %rbx
	movq	%rsi, %rbp
	movl	%edx, %esi
	movl	%ecx, %r14d
	call	find
	movl	%eax, %r12d
	movl	%r14d, %esi
	movq	%rbx, %rdi
	call	find
	movslq	%r12d, %r8
	leaq	0(%rbp,%r8,4), %rdx
	movl	(%rdx), %edi
	movslq	%eax, %rcx
	movl	0(%rbp,%rcx,4), %esi
	cmpl	%esi, %edi
	jge	.L34
	movl	%eax, (%rbx,%r8,4)
.L33:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L34:
	.cfi_restore_state
	jle	.L36
	movl	%r12d, (%rbx,%rcx,4)
	jmp	.L33
.L36:
	movl	%r12d, (%rbx,%rcx,4)
	addl	$1, (%rdx)
	jmp	.L33
	.cfi_endproc
.LFE28:
	.size	Union, .-Union
	.section	.rodata.str1.1
.LC3:
	.string	"Kruskal MST: "
.LC4:
	.string	"(%d-%d:%d) "
	.text
	.globl	kruskal_mst
	.type	kruskal_mst, @function
kruskal_mst:
.LFB30:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	%rdi, %r13
	movl	(%rdi), %ebx
	movl	%ebx, %eax
	imull	%ebx, %eax
	cltq
	leaq	(%rax,%rax,2), %rdi
	salq	$2, %rdi
	call	malloc@PLT
	movq	%rax, %rbp
	testl	%ebx, %ebx
	jle	.L39
	movq	8(%r13), %r9
	movslq	%ebx, %r8
	movl	$0, %ecx
	movl	$0, %ebx
	jmp	.L43
	.p2align 4
.L41:
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L40
.L42:
	cmpl	%ecx, (%rax)
	jle	.L41
	movslq	%ebx, %rdx
	leaq	(%rdx,%rdx,2), %rdx
	leaq	0(%rbp,%rdx,4), %rdx
	movl	%edi, (%rdx)
	movl	(%rax), %esi
	movl	%esi, 4(%rdx)
	movl	4(%rax), %esi
	movl	%esi, 8(%rdx)
	addl	$1, %ebx
	jmp	.L41
	.p2align 5
.L40:
	addq	$1, %rcx
	cmpq	%r8, %rcx
	je	.L59
.L43:
	movq	(%r9,%rcx,8), %rax
	testq	%rax, %rax
	je	.L40
	movl	%ecx, %edi
	jmp	.L42
.L59:
	movslq	%ebx, %r12
	leaq	comp_edge(%rip), %rcx
	movl	$12, %edx
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	qsort@PLT
	movl	0(%r13), %r15d
	movslq	%r15d, %r14
	leaq	0(,%r14,4), %rdi
	call	malloc@PLT
	movq	%rax, %r13
	movl	$4, %esi
	movq	%r14, %rdi
	call	calloc@PLT
	movq	%rax, 24(%rsp)
	testl	%r15d, %r15d
	jle	.L44
.L49:
	movl	$0, %eax
	.p2align 4
.L45:
	movl	%eax, 0(%r13,%rax,4)
	addq	$1, %rax
	cmpq	%rax, %r14
	jne	.L45
.L44:
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	testl	%ebx, %ebx
	jle	.L46
	movq	%rbp, %rbx
	leaq	(%r12,%r12,2), %rax
	leaq	0(%rbp,%rax,4), %rax
	movq	%rax, 16(%rsp)
	jmp	.L48
.L47:
	addq	$12, %rbx
	movq	16(%rsp), %rax
	cmpq	%rax, %rbx
	je	.L46
.L48:
	movl	(%rbx), %r14d
	movl	4(%rbx), %r15d
	movl	%r14d, %esi
	movq	%r13, %rdi
	call	find
	movl	%eax, 12(%rsp)
	movl	%r15d, %esi
	movq	%r13, %rdi
	call	find
	movl	%eax, %r12d
	cmpl	%eax, 12(%rsp)
	je	.L47
	movl	8(%rbx), %ecx
	movl	%r15d, %edx
	movl	%r14d, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	%r12d, %ecx
	movl	12(%rsp), %edx
	movq	24(%rsp), %rsi
	movq	%r13, %rdi
	call	Union
	jmp	.L47
.L39:
	leaq	comp_edge(%rip), %rcx
	movl	$12, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	qsort@PLT
	movl	0(%r13), %r15d
	movslq	%r15d, %r14
	leaq	0(,%r14,4), %rdi
	call	malloc@PLT
	movq	%rax, %r13
	movl	$4, %esi
	movq	%r14, %rdi
	call	calloc@PLT
	movq	%rax, 24(%rsp)
	movl	$0, %ebx
	movl	$0, %r12d
	testl	%r15d, %r15d
	jg	.L49
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L46:
	movl	$10, %edi
	call	putchar@PLT
	movq	%r13, %rdi
	call	free@PLT
	movq	24(%rsp), %rdi
	call	free@PLT
	movq	%rbp, %rdi
	call	free@PLT
	addq	$40, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE30:
	.size	kruskal_mst, .-kruskal_mst
	.globl	free_graph
	.type	free_graph, @function
free_graph:
.LFB31:
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
	cmpl	$0, (%rdi)
	jle	.L61
	movl	$0, %ebp
.L64:
	movq	8(%r12), %rax
	movq	(%rax,%rbp,8), %rbx
	testq	%rbx, %rbx
	je	.L62
.L63:
	movq	%rbx, %rdi
	movq	8(%rbx), %rbx
	call	free@PLT
	testq	%rbx, %rbx
	jne	.L63
.L62:
	addq	$1, %rbp
	cmpl	%ebp, (%r12)
	jg	.L64
.L61:
	movq	8(%r12), %rdi
	call	free@PLT
	movq	%r12, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE31:
	.size	free_graph, .-free_graph
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
