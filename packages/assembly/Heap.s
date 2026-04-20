	.file	"Heap.c"
	.text
	.globl	create_heap
	.type	create_heap, @function
create_heap:
.LFB11:
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
	movl	%esi, %r12d
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, %rbx
	movslq	%ebp, %rdi
	salq	$2, %rdi
	call	malloc@PLT
	movq	%rax, (%rbx)
	movl	$0, 8(%rbx)
	movl	%ebp, 12(%rbx)
	movl	%r12d, 16(%rbx)
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	create_heap, .-create_heap
	.globl	swap
	.type	swap, @function
swap:
.LFB12:
	.cfi_startproc
	movl	(%rdi), %eax
	movl	(%rsi), %edx
	movl	%edx, (%rdi)
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE12:
	.size	swap, .-swap
	.globl	heapify_up
	.type	heapify_up, @function
heapify_up:
.LFB13:
	.cfi_startproc
	testl	%esi, %esi
	je	.L9
	movl	%esi, %eax
	leal	-1(%rsi), %ecx
	movl	%ecx, %edx
	shrl	$31, %edx
	addl	%ecx, %edx
	sarl	%edx
	cmpl	$0, 16(%rdi)
	je	.L6
	movq	(%rdi), %rsi
	movslq	%eax, %rcx
	movslq	%edx, %r8
	movl	(%rsi,%r8,4), %r9d
	cmpl	%r9d, (%rsi,%rcx,4)
	jl	.L7
	ret
.L6:
	movq	(%rdi), %rsi
	movslq	%eax, %rcx
	movslq	%edx, %r8
	movl	(%rsi,%r8,4), %r10d
	cmpl	%r10d, (%rsi,%rcx,4)
	jle	.L9
.L7:
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	(%rdi), %rsi
	movslq	%edx, %rcx
	leaq	(%rsi,%rcx,4), %rcx
	cltq
	leaq	(%rsi,%rax,4), %rax
	movl	(%rax), %esi
	movl	(%rcx), %r8d
	movl	%r8d, (%rax)
	movl	%esi, (%rcx)
	movl	%edx, %esi
	call	heapify_up
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
.L9:
	ret
	.cfi_endproc
.LFE13:
	.size	heapify_up, .-heapify_up
	.globl	insert_heap
	.type	insert_heap, @function
insert_heap:
.LFB14:
	.cfi_startproc
	movl	8(%rdi), %eax
	cmpl	12(%rdi), %eax
	je	.L14
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	cltq
	movq	(%rdi), %rdx
	movl	%esi, (%rdx,%rax,4)
	movl	8(%rdi), %esi
	call	heapify_up
	addl	$1, 8(%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L14:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE14:
	.size	insert_heap, .-insert_heap
	.globl	heapify_down
	.type	heapify_down, @function
heapify_down:
.LFB15:
	.cfi_startproc
	movl	%esi, %eax
	leal	(%rsi,%rsi), %esi
	leal	1(%rsi), %edx
	addl	$2, %esi
	movl	8(%rdi), %ecx
	cmpl	%edx, %ecx
	jle	.L18
	cmpl	$0, 16(%rdi)
	je	.L19
	movq	(%rdi), %r9
	movslq	%edx, %r8
	movslq	%eax, %r10
	movl	(%r9,%r10,4), %r11d
	cmpl	%r11d, (%r9,%r8,4)
	jl	.L20
	cmpl	%esi, %ecx
	jle	.L32
	movq	(%rdi), %rcx
	movslq	%esi, %rdx
	movslq	%eax, %r8
	movl	(%rcx,%r8,4), %r11d
	cmpl	%r11d, (%rcx,%rdx,4)
	jl	.L24
	ret
.L19:
	movq	(%rdi), %r8
	movslq	%edx, %r10
	movslq	%eax, %r9
	movl	(%r8,%r9,4), %r11d
	cmpl	%r11d, (%r8,%r10,4)
	cmovle	%eax, %edx
	cmpl	%esi, %ecx
	jg	.L23
	movl	%edx, %esi
	jmp	.L24
.L26:
	movl	%eax, %edx
	cmpl	$0, 16(%rdi)
	jne	.L27
.L23:
	movq	(%rdi), %rcx
	movslq	%esi, %r9
	movslq	%edx, %r8
	movl	(%rcx,%r8,4), %r10d
	cmpl	%r10d, (%rcx,%r9,4)
	cmovle	%edx, %esi
.L24:
	cmpl	%eax, %esi
	je	.L32
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	(%rdi), %rcx
	movslq	%esi, %rdx
	leaq	(%rcx,%rdx,4), %rdx
	cltq
	leaq	(%rcx,%rax,4), %rax
	movl	(%rax), %ecx
	movl	(%rdx), %r8d
	movl	%r8d, (%rax)
	movl	%ecx, (%rdx)
	call	heapify_down
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
.L27:
	movq	(%rdi), %rcx
	movslq	%esi, %r9
	movslq	%edx, %r8
	movl	(%rcx,%r8,4), %r11d
	cmpl	%r11d, (%rcx,%r9,4)
	cmovge	%edx, %esi
	jmp	.L24
.L18:
	cmpl	%esi, %ecx
	jg	.L26
	ret
.L20:
	cmpl	%esi, %ecx
	jg	.L27
	movl	%edx, %esi
	jmp	.L24
.L32:
	ret
	.cfi_endproc
.LFE15:
	.size	heapify_down, .-heapify_down
	.globl	extract_heap
	.type	extract_heap, @function
extract_heap:
.LFB16:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	8(%rdi), %eax
	testl	%eax, %eax
	je	.L37
	movq	(%rdi), %rdx
	movl	(%rdx), %ebx
	cltq
	movl	-4(%rdx,%rax,4), %eax
	movl	%eax, (%rdx)
	subl	$1, 8(%rdi)
	movl	$0, %esi
	call	heapify_down
.L35:
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L37:
	.cfi_restore_state
	movl	$-1, %ebx
	jmp	.L35
	.cfi_endproc
.LFE16:
	.size	extract_heap, .-extract_heap
	.globl	free_heap
	.type	free_heap, @function
free_heap:
.LFB17:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	(%rdi), %rdi
	call	free@PLT
	movq	%rbx, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE17:
	.size	free_heap, .-free_heap
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
