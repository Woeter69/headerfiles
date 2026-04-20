	.file	"Sorting.c"
	.text
	.globl	bubble_sort
	.type	bubble_sort, @function
bubble_sort:
.LFB0:
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
.LFE0:
	.size	bubble_sort, .-bubble_sort
	.globl	selection_sort
	.type	selection_sort, @function
selection_sort:
.LFB1:
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
.LFE1:
	.size	selection_sort, .-selection_sort
	.globl	insertion_sort
	.type	insertion_sort, @function
insertion_sort:
.LFB2:
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
.LFE2:
	.size	insertion_sort, .-insertion_sort
	.globl	my_heapify
	.type	my_heapify, @function
my_heapify:
.LFB3:
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
.LFE3:
	.size	my_heapify, .-my_heapify
	.globl	heap_sort
	.type	heap_sort, @function
heap_sort:
.LFB4:
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
.LFE4:
	.size	heap_sort, .-heap_sort
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
