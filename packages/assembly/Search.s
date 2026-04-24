	.file	"Search.c"
	.text
	.globl	linear_search
	.type	linear_search, @function
linear_search:
.LFB0:
	.cfi_startproc
	testl	%esi, %esi
	jle	.L5
	movslq	%esi, %rsi
	movl	$0, %eax
	.p2align 4
.L4:
	cmpl	%edx, (%rdi,%rax,4)
	je	.L1
	addq	$1, %rax
	cmpq	%rsi, %rax
	jne	.L4
	movl	$-1, %eax
	ret
.L5:
	movl	$-1, %eax
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	linear_search, .-linear_search
	.globl	binary_search
	.type	binary_search, @function
binary_search:
.LFB1:
	.cfi_startproc
	subl	$1, %esi
	js	.L12
	movl	$0, %ecx
	jmp	.L11
.L9:
	leal	-1(%rax), %esi
.L10:
	cmpl	%esi, %ecx
	jg	.L14
.L11:
	movl	%esi, %r8d
	subl	%ecx, %r8d
	movl	%r8d, %eax
	shrl	$31, %eax
	addl	%r8d, %eax
	sarl	%eax
	addl	%ecx, %eax
	movslq	%eax, %r8
	movl	(%rdi,%r8,4), %r8d
	cmpl	%edx, %r8d
	je	.L7
	jge	.L9
	leal	1(%rax), %ecx
	jmp	.L10
.L14:
	movl	$-1, %eax
	ret
.L12:
	movl	$-1, %eax
.L7:
	ret
	.cfi_endproc
.LFE1:
	.size	binary_search, .-binary_search
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
