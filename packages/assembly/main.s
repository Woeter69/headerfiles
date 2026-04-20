	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d "
	.text
	.globl	print_array
	.type	print_array, @function
print_array:
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
	testl	%esi, %esi
	jle	.L2
	movq	%rdi, %rbx
	movslq	%esi, %rsi
	leaq	(%rdi,%rsi,4), %r12
	leaq	.LC0(%rip), %rbp
.L3:
	movl	(%rbx), %esi
	movq	%rbp, %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$4, %rbx
	cmpq	%r12, %rbx
	jne	.L3
.L2:
	movl	$10, %edi
	call	putchar@PLT
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	print_array, .-print_array
	.section	.rodata.str1.1
.LC1:
	.string	"--- Testing LinkedList ---"
.LC2:
	.string	"--- Testing Stack ---"
.LC3:
	.string	"Popped: %d\n"
.LC4:
	.string	"--- Testing Queue ---"
.LC5:
	.string	"Dequeued: %d\n"
.LC6:
	.string	"--- Testing Deque ---"
.LC7:
	.string	"Pop Front: %d\n"
.LC8:
	.string	"--- Testing Heap ---"
.LC9:
	.string	"Extracted: %d\n"
.LC10:
	.string	"--- Testing PriorityQueue ---"
.LC11:
	.string	"PQ Pop: %d\n"
.LC12:
	.string	"--- Testing Tree ---"
.LC13:
	.string	"--- Testing Graph ---"
.LC14:
	.string	"--- Testing Sorting ---"
.LC15:
	.string	"--- Testing Search ---"
.LC16:
	.string	"Found 4 at index: %d\n"
.LC17:
	.string	"All tests passed!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	$10, %esi
	movl	$0, %edi
	call	insert_singly@PLT
	movq	%rax, %rdi
	movl	$20, %esi
	call	insert_singly@PLT
	movq	%rax, %rbx
	movq	%rax, %rdi
	call	print_singly@PLT
	movq	%rbx, %rdi
	call	free_singly@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	call	create_stack@PLT
	movq	%rax, %rbx
	movl	$1, %esi
	movq	%rax, %rdi
	call	push@PLT
	movl	$2, %esi
	movq	%rbx, %rdi
	call	push@PLT
	movq	%rbx, %rdi
	call	pop@PLT
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_stack@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	call	create_queue@PLT
	movq	%rax, %rbx
	movl	$1, %esi
	movq	%rax, %rdi
	call	enqueue@PLT
	movl	$2, %esi
	movq	%rbx, %rdi
	call	enqueue@PLT
	movq	%rbx, %rdi
	call	dequeue@PLT
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_queue@PLT
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
	call	create_deque@PLT
	movq	%rax, %rbx
	movl	$1, %esi
	movq	%rax, %rdi
	call	push_front@PLT
	movl	$2, %esi
	movq	%rbx, %rdi
	call	push_back@PLT
	movq	%rbx, %rdi
	call	pop_front@PLT
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_deque@PLT
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	movl	$1, %esi
	movl	$10, %edi
	call	create_heap@PLT
	movq	%rax, %rbx
	movl	$5, %esi
	movq	%rax, %rdi
	call	insert_heap@PLT
	movl	$2, %esi
	movq	%rbx, %rdi
	call	insert_heap@PLT
	movl	$8, %esi
	movq	%rbx, %rdi
	call	insert_heap@PLT
	movq	%rbx, %rdi
	call	extract_heap@PLT
	movl	%eax, %esi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_heap@PLT
	leaq	.LC10(%rip), %rdi
	call	puts@PLT
	movl	$10, %edi
	call	create_pq@PLT
	movq	%rax, %rbx
	movl	$10, %esi
	movq	%rax, %rdi
	call	pq_push@PLT
	movl	$5, %esi
	movq	%rbx, %rdi
	call	pq_push@PLT
	movq	%rbx, %rdi
	call	pq_pop@PLT
	movl	%eax, %esi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_pq@PLT
	leaq	.LC12(%rip), %rdi
	call	puts@PLT
	movl	$5, %esi
	movl	$0, %edi
	call	bst_insert@PLT
	movq	%rax, %rbx
	movl	$3, %esi
	movq	%rax, %rdi
	call	bst_insert@PLT
	movl	$7, %esi
	movq	%rbx, %rdi
	call	bst_insert@PLT
	movq	%rbx, %rdi
	call	bst_inorder@PLT
	movl	$10, %edi
	call	putchar@PLT
	movq	%rbx, %rdi
	call	bst_free@PLT
	leaq	.LC13(%rip), %rdi
	call	puts@PLT
	movl	$4, %edi
	call	create_graph@PLT
	movq	%rax, %rbx
	movl	$10, %ecx
	movl	$1, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	add_edge@PLT
	movl	$6, %ecx
	movl	$2, %edx
	movl	$0, %esi
	movq	%rbx, %rdi
	call	add_edge@PLT
	movl	$5, %ecx
	movl	$3, %edx
	movl	$0, %esi
	movq	%rbx, %rdi
	call	add_edge@PLT
	movl	$15, %ecx
	movl	$3, %edx
	movl	$1, %esi
	movq	%rbx, %rdi
	call	add_edge@PLT
	movl	$4, %ecx
	movl	$3, %edx
	movl	$2, %esi
	movq	%rbx, %rdi
	call	add_edge@PLT
	movl	$0, %esi
	movq	%rbx, %rdi
	call	bfs@PLT
	movl	$0, %esi
	movq	%rbx, %rdi
	call	dfs@PLT
	movq	%rbx, %rdi
	call	kruskal_mst@PLT
	movq	%rbx, %rdi
	call	free_graph@PLT
	leaq	.LC14(%rip), %rdi
	call	puts@PLT
	movl	$4, (%rsp)
	movl	$2, 4(%rsp)
	movl	$5, 8(%rsp)
	movl	$1, 12(%rsp)
	movl	$3, 16(%rsp)
	movl	$5, %esi
	movq	%rsp, %rdi
	call	heap_sort@PLT
	movl	$5, %esi
	movq	%rsp, %rdi
	call	print_array
	leaq	.LC15(%rip), %rdi
	call	puts@PLT
	movl	$4, %edx
	movl	$5, %esi
	movq	%rsp, %rdi
	call	binary_search@PLT
	movl	%eax, %esi
	leaq	.LC16(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	movq	24(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L9
	movl	$0, %eax
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L9:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
