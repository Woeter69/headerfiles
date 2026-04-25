	.file	"Sorting.c"
	.text
	.globl	bubble_sort
	.type	bubble_sort, @function
bubble_sort:
.LFB11:
	.cfi_startproc
	cmpl	$1, %esi
	jle	.L1
	leaq	4(%rdi), %r9
	jmp	.L3
	.p2align 5
.L4:
	addq	$4, %rax
	cmpq	%r8, %rax
	je	.L10
.L5:
	movl	(%rax), %edx
	movl	4(%rax), %ecx
	cmpl	%ecx, %edx
	jle	.L4
	movl	%ecx, (%rax)
	movl	%edx, 4(%rax)
	jmp	.L4
.L10:
	subl	$1, %esi
	cmpl	$1, %esi
	je	.L1
.L3:
	cmpl	$1, %esi
	jle	.L11
	movq	%rdi, %rax
	leal	-2(%rsi), %edx
	leaq	(%r9,%rdx,4), %r8
	jmp	.L5
.L11:
	subl	$1, %esi
	jmp	.L3
.L1:
	ret
	.cfi_endproc
.LFE11:
	.size	bubble_sort, .-bubble_sort
	.globl	selection_sort
	.type	selection_sort, @function
selection_sort:
.LFB12:
	.cfi_startproc
	cmpl	$1, %esi
	jle	.L21
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%esi, %ebx
	movq	$-4, %r11
	movl	$0, %r10d
	movl	$1, %r9d
.L17:
	leal	-1(%r9), %edx
	cmpl	%r9d, %esi
	jle	.L14
	movq	%r9, %rax
	leaq	(%r10,%r11), %r8
	addq	%rdi, %r8
	.p2align 5
.L16:
	movslq	%edx, %rcx
	movl	(%rdi,%rcx,4), %ecx
	cmpl	%ecx, 4(%r8,%rax,4)
	cmovl	%eax, %edx
	addq	$1, %rax
	cmpl	%eax, %esi
	jg	.L16
.L14:
	movslq	%edx, %rdx
	leaq	(%rdi,%rdx,4), %rax
	movl	(%rax), %edx
	movl	(%rdi,%r10), %ecx
	movl	%ecx, (%rax)
	movl	%edx, (%rdi,%r10)
	addq	$1, %r9
	addq	$4, %r10
	subq	$4, %r11
	cmpq	%rbx, %r9
	jne	.L17
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L21:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE12:
	.size	selection_sort, .-selection_sort
	.globl	insertion_sort
	.type	insertion_sort, @function
insertion_sort:
.LFB13:
	.cfi_startproc
	cmpl	$1, %esi
	jle	.L24
	leaq	4(%rdi), %r9
	leal	-1(%rsi), %r10d
	movl	$0, %r8d
	jmp	.L30
.L28:
	addl	$1, %edx
	movslq	%edx, %rdx
	movl	%esi, (%rdi,%rdx,4)
	addq	$1, %r8
	cmpq	%r10, %r8
	je	.L24
	addq	$4, %r9
.L30:
	movl	(%r9), %esi
	movl	%r8d, %edx
	movq	%r9, %rax
	testl	%r8d, %r8d
	js	.L35
	.p2align 5
.L26:
	movl	-4(%rax), %ecx
	cmpl	%esi, %ecx
	jle	.L28
	movl	%ecx, (%rax)
	subl	$1, %edx
	subq	$4, %rax
	cmpl	$-1, %edx
	jne	.L26
	jmp	.L28
.L35:
	leal	1(%r8), %eax
	cltq
	movl	%esi, (%rdi,%rax,4)
	addq	$1, %r8
	addq	$4, %r9
	jmp	.L30
.L24:
	ret
	.cfi_endproc
.LFE13:
	.size	insertion_sort, .-insertion_sort
	.globl	my_heapify
	.type	my_heapify, @function
my_heapify:
.LFB14:
	.cfi_startproc
	movl	%edx, %eax
	leal	(%rdx,%rdx), %edx
	leal	1(%rdx), %ecx
	addl	$2, %edx
	cmpl	%esi, %ecx
	jge	.L37
	movslq	%ecx, %r8
	movslq	%eax, %r9
	movl	(%rdi,%r9,4), %r10d
	cmpl	%r10d, (%rdi,%r8,4)
	jle	.L37
	cmpl	%esi, %edx
	jge	.L40
	movslq	%edx, %r9
	movl	(%rdi,%r8,4), %r11d
	cmpl	%r11d, (%rdi,%r9,4)
	cmovle	%ecx, %edx
	jmp	.L38
.L40:
	movl	%ecx, %edx
	jmp	.L38
.L37:
	cmpl	%esi, %edx
	jge	.L42
	movslq	%edx, %rcx
	movslq	%eax, %r8
	movl	(%rdi,%r8,4), %r11d
	cmpl	%r11d, (%rdi,%rcx,4)
	jle	.L45
.L38:
	cmpl	%eax, %edx
	je	.L42
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	cltq
	leaq	(%rdi,%rax,4), %rcx
	movl	(%rcx), %r8d
	movslq	%edx, %rax
	leaq	(%rdi,%rax,4), %rax
	movl	(%rax), %r9d
	movl	%r9d, (%rcx)
	movl	%r8d, (%rax)
	call	my_heapify
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
.L45:
	ret
.L42:
	ret
	.cfi_endproc
.LFE14:
	.size	my_heapify, .-my_heapify
	.globl	heap_sort
	.type	heap_sort, @function
heap_sort:
.LFB15:
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
	movq	%rdi, %rbp
	movl	%esi, %r12d
	movl	%esi, %ebx
	shrl	$31, %ebx
	addl	%esi, %ebx
	sarl	%ebx
	subl	$1, %ebx
	js	.L47
.L48:
	movl	%ebx, %edx
	movl	%r12d, %esi
	movq	%rbp, %rdi
	call	my_heapify
	subl	$1, %ebx
	cmpl	$-1, %ebx
	jne	.L48
.L47:
	leal	-1(%r12), %ebx
	testl	%ebx, %ebx
	jle	.L46
	movslq	%r12d, %r12
	leaq	0(%rbp,%r12,4), %r12
.L50:
	movl	0(%rbp), %eax
	movl	-4(%r12), %edx
	movl	%edx, 0(%rbp)
	movl	%eax, -4(%r12)
	movl	$0, %edx
	movl	%ebx, %esi
	movq	%rbp, %rdi
	call	my_heapify
	subq	$4, %r12
	subl	$1, %ebx
	jne	.L50
.L46:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE15:
	.size	heap_sort, .-heap_sort
	.globl	quick_sort
	.type	quick_sort, @function
quick_sort:
.LFB17:
	.cfi_startproc
	cmpl	%edx, %esi
	jl	.L63
	ret
.L63:
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbx
	movl	%edx, %r12d
	movslq	%edx, %rax
	leaq	(%rdi,%rax,4), %r10
	movl	(%r10), %r8d
	leal	-1(%rsi), %ebp
	movslq	%esi, %rcx
	leaq	(%rdi,%rcx,4), %rax
	subl	%esi, %edx
	addq	%rcx, %rdx
	leaq	(%rdi,%rdx,4), %rdi
	jmp	.L57
	.p2align 4
.L56:
	addq	$4, %rax
	cmpq	%rdi, %rax
	je	.L64
.L57:
	movl	(%rax), %edx
	cmpl	%edx, %r8d
	jle	.L56
	addl	$1, %ebp
	movslq	%ebp, %rcx
	leaq	(%rbx,%rcx,4), %rcx
	movl	(%rcx), %r9d
	movl	%edx, (%rcx)
	movl	%r9d, (%rax)
	jmp	.L56
.L64:
	movslq	%ebp, %rax
	leaq	4(%rbx,%rax,4), %rax
	movl	(%rax), %edx
	movl	(%r10), %ecx
	movl	%ecx, (%rax)
	movl	%edx, (%r10)
	movl	%ebp, %edx
	movq	%rbx, %rdi
	call	quick_sort
	leal	2(%rbp), %esi
	movl	%r12d, %edx
	movq	%rbx, %rdi
	call	quick_sort
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE17:
	.size	quick_sort, .-quick_sort
	.globl	merge_sort
	.type	merge_sort, @function
merge_sort:
.LFB19:
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
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%rdi, (%rsp)
	cmpl	%edx, %esi
	jl	.L86
.L65:
	addq	$24, %rsp
	.cfi_remember_state
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
.L86:
	.cfi_restore_state
	movl	%esi, %ebx
	movl	%edx, %ebp
	subl	%esi, %edx
	movl	%edx, %eax
	shrl	$31, %eax
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %r15d
	movl	%eax, 8(%rsp)
	leal	(%rax,%rsi), %r14d
	movl	%r14d, 12(%rsp)
	movl	%r14d, %edx
	movq	%rdi, %r12
	call	merge_sort
	leal	1(%r14), %esi
	movl	%ebp, %edx
	movq	%r12, (%rsp)
	movq	%r12, %rdi
	call	merge_sort
	addl	$1, %r15d
	subl	%r14d, %ebp
	movslq	%r15d, %rdi
	salq	$2, %rdi
	call	malloc@PLT
	movq	%rax, %r13
	movslq	%ebp, %r14
	salq	$2, %r14
	movq	%r14, %rdi
	call	malloc@PLT
	movq	%rax, %r12
	movl	%r15d, %esi
	salq	$2, %rsi
	movslq	%ebx, %rdx
	salq	$2, %rdx
	movq	(%rsp), %rax
	leaq	(%rax,%rdx), %rdi
	movl	$0, %eax
	.p2align 5
.L67:
	movl	(%rdi,%rax), %ecx
	movl	%ecx, 0(%r13,%rax)
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L67
	testl	%ebp, %ebp
	jle	.L78
	movslq	12(%rsp), %rax
	movq	(%rsp), %rdi
	leaq	(%rdi,%rax,4), %rsi
	movl	$0, %eax
	.p2align 5
.L69:
	movl	4(%rsi,%rax), %ecx
	movl	%ecx, (%r12,%rax)
	addq	$4, %rax
	cmpq	%rax, %r14
	jne	.L69
	movq	(%rsp), %rax
	addq	%rax, %rdx
	movl	$0, %ecx
	movl	$0, %eax
	jmp	.L72
.L70:
	movl	%esi, (%rdx)
	addl	$1, %ecx
.L71:
	addl	$1, %ebx
	addq	$4, %rdx
	cmpl	%eax, %r15d
	jle	.L79
	cmpl	%ecx, %ebp
	jle	.L79
.L72:
	movslq	%eax, %rsi
	movl	0(%r13,%rsi,4), %edi
	movslq	%ecx, %rsi
	movl	(%r12,%rsi,4), %esi
	cmpl	%esi, %edi
	jg	.L70
	movl	%edi, (%rdx)
	addl	$1, %eax
	jmp	.L71
.L79:
	cmpl	%eax, %r15d
	jle	.L74
.L68:
	movl	%eax, %r8d
	movl	8(%rsp), %esi
	subl	%eax, %esi
	cltq
	leaq	0(%r13,%rax,4), %r9
	movslq	%ebx, %rax
	movq	(%rsp), %rdi
	leaq	(%rdi,%rax,4), %rdi
	movl	$0, %eax
	addq	$1, %rsi
	.p2align 4
.L75:
	movl	(%r9,%rax,4), %edx
	movl	%edx, (%rdi,%rax,4)
	addq	$1, %rax
	cmpq	%rsi, %rax
	jne	.L75
	movl	8(%rsp), %eax
	leal	1(%rbx,%rax), %ebx
	subl	%r8d, %ebx
.L74:
	cmpl	%ecx, %ebp
	jle	.L76
	subl	%ecx, %ebp
	salq	$2, %rbp
	movslq	%ecx, %rcx
	leaq	(%r12,%rcx,4), %rsi
	movslq	%ebx, %rbx
	movq	(%rsp), %rax
	leaq	(%rax,%rbx,4), %rcx
	movl	$0, %eax
	.p2align 4
.L77:
	movl	(%rsi,%rax), %edx
	movl	%edx, (%rcx,%rax)
	addq	$4, %rax
	cmpq	%rbp, %rax
	jne	.L77
.L76:
	movq	%r13, %rdi
	call	free@PLT
	movq	%r12, %rdi
	call	free@PLT
	jmp	.L65
.L78:
	movl	$0, %ecx
	movl	$0, %eax
	jmp	.L68
	.cfi_endproc
.LFE19:
	.size	merge_sort, .-merge_sort
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
