	.file	"Queue.c"
	.text
	.globl	create_queue
	.type	create_queue, @function
create_queue:
.LFB11:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	call	malloc@PLT
	movq	$0, 8(%rax)
	movq	$0, (%rax)
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	create_queue, .-create_queue
	.globl	enqueue
	.type	enqueue, @function
enqueue:
.LFB12:
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
	movq	$0, 8(%rax)
	movq	8(%rbx), %rdx
	testq	%rdx, %rdx
	je	.L4
	movq	%rax, 8(%rdx)
	movq	%rax, 8(%rbx)
.L3:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	movq	%rax, 8(%rbx)
	movq	%rax, (%rbx)
	jmp	.L3
	.cfi_endproc
.LFE12:
	.size	enqueue, .-enqueue
	.globl	dequeue
	.type	dequeue, @function
dequeue:
.LFB13:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	(%rdi), %rax
	testq	%rax, %rax
	je	.L10
	movl	(%rax), %ebx
	movq	8(%rax), %rdx
	movq	%rdx, (%rdi)
	testq	%rdx, %rdx
	je	.L12
.L9:
	movq	%rax, %rdi
	call	free@PLT
.L7:
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore_state
	movq	$0, 8(%rdi)
	jmp	.L9
.L10:
	movl	$-1, %ebx
	jmp	.L7
	.cfi_endproc
.LFE13:
	.size	dequeue, .-dequeue
	.globl	free_queue
	.type	free_queue, @function
free_queue:
.LFB14:
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
.LFE14:
	.size	free_queue, .-free_queue
	.globl	create_deque
	.type	create_deque, @function
create_deque:
.LFB15:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	call	malloc@PLT
	movq	$0, 8(%rax)
	movq	$0, (%rax)
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE15:
	.size	create_deque, .-create_deque
	.globl	push_front
	.type	push_front, @function
push_front:
.LFB16:
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
	movq	$0, 16(%rax)
	movq	(%rbx), %rdx
	movq	%rdx, 8(%rax)
	testq	%rdx, %rdx
	je	.L18
	movq	%rax, 16(%rdx)
.L18:
	movq	%rax, (%rbx)
	cmpq	$0, 8(%rbx)
	je	.L21
.L17:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L21:
	.cfi_restore_state
	movq	%rax, 8(%rbx)
	jmp	.L17
	.cfi_endproc
.LFE16:
	.size	push_front, .-push_front
	.globl	push_back
	.type	push_back, @function
push_back:
.LFB17:
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
	movq	$0, 8(%rax)
	movq	8(%rbx), %rdx
	movq	%rdx, 16(%rax)
	testq	%rdx, %rdx
	je	.L23
	movq	%rax, 8(%rdx)
.L23:
	movq	%rax, 8(%rbx)
	cmpq	$0, (%rbx)
	je	.L26
.L22:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L26:
	.cfi_restore_state
	movq	%rax, (%rbx)
	jmp	.L22
	.cfi_endproc
.LFE17:
	.size	push_back, .-push_back
	.globl	pop_front
	.type	pop_front, @function
pop_front:
.LFB18:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	(%rdi), %rax
	testq	%rax, %rax
	je	.L31
	movl	(%rax), %ebx
	movq	8(%rax), %rdx
	movq	%rdx, (%rdi)
	testq	%rdx, %rdx
	je	.L29
	movq	$0, 16(%rdx)
.L30:
	movq	%rax, %rdi
	call	free@PLT
.L27:
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L29:
	.cfi_restore_state
	movq	$0, 8(%rdi)
	jmp	.L30
.L31:
	movl	$-1, %ebx
	jmp	.L27
	.cfi_endproc
.LFE18:
	.size	pop_front, .-pop_front
	.globl	pop_back
	.type	pop_back, @function
pop_back:
.LFB19:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	8(%rdi), %rax
	testq	%rax, %rax
	je	.L37
	movl	(%rax), %ebx
	movq	16(%rax), %rdx
	movq	%rdx, 8(%rdi)
	testq	%rdx, %rdx
	je	.L35
	movq	$0, 8(%rdx)
.L36:
	movq	%rax, %rdi
	call	free@PLT
.L33:
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L35:
	.cfi_restore_state
	movq	$0, (%rdi)
	jmp	.L36
.L37:
	movl	$-1, %ebx
	jmp	.L33
	.cfi_endproc
.LFE19:
	.size	pop_back, .-pop_back
	.globl	free_deque
	.type	free_deque, @function
free_deque:
.LFB20:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	(%rdi), %rdi
	call	free_doubly@PLT
	movq	%rbx, %rdi
	call	free@PLT
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE20:
	.size	free_deque, .-free_deque
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
