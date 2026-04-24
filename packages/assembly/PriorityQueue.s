	.file	"PriorityQueue.c"
	.text
	.globl	create_pq
	.type	create_pq, @function
create_pq:
.LFB11:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	%edi, %r14d
	movl	$8, %edi
	call	malloc@PLT
	movq	%rax, %rbx
	movl	$1, %esi
	movl	%r14d, %edi
	call	create_heap@PLT
	movq	%rax, (%rbx)
	movq	%rbx, %rax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	create_pq, .-create_pq
	.globl	pq_push
	.type	pq_push, @function
pq_push:
.LFB12:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	(%rdi), %rdi
	call	insert_heap@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	pq_push, .-pq_push
	.globl	pq_pop
	.type	pq_pop, @function
pq_pop:
.LFB13:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	(%rdi), %rdi
	call	extract_heap@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE13:
	.size	pq_pop, .-pq_pop
	.globl	free_pq
	.type	free_pq, @function
free_pq:
.LFB14:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	(%rdi), %rdi
	call	free_heap@PLT
	movq	%rbx, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE14:
	.size	free_pq, .-free_pq
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
