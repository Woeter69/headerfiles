	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"--- Testing LinkedList ---"
.LC1:
	.string	"Reversed: "
.LC2:
	.string	"Has Cycle: %d\n"
.LC3:
	.string	"\n--- Testing Stack ---"
.LC4:
	.string	"Popped: %d\n"
.LC5:
	.string	"{[()]}"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC6:
	.string	"isValidParentheses(\"{[()]}\"): %d\n"
	.section	.rodata.str1.1
.LC7:
	.string	"{[(])}"
	.section	.rodata.str1.8
	.align 8
.LC8:
	.string	"isValidParentheses(\"{[(])}\"): %d\n"
	.section	.rodata.str1.1
.LC9:
	.string	"\n--- Testing Queue ---"
.LC10:
	.string	"Dequeued: %d\n"
	.section	.rodata.str1.8
	.align 8
.LC11:
	.string	"\n--- Testing Circular Queue ---"
	.section	.rodata.str1.1
.LC12:
	.string	"Is Full: %d\n"
.LC13:
	.string	"\n--- Testing Heap ---"
.LC14:
	.string	"Extracted: %d\n"
	.section	.rodata.str1.8
	.align 8
.LC15:
	.string	"\n--- Testing PriorityQueue ---"
	.section	.rodata.str1.1
.LC16:
	.string	"PQ Pop: %d\n"
.LC17:
	.string	"\n--- Testing Tree ---"
.LC18:
	.string	"\n--- Testing AVL Tree ---"
.LC19:
	.string	"\n--- Testing Trie ---"
.LC20:
	.string	"apple"
.LC21:
	.string	"Search 'apple': %d\n"
.LC22:
	.string	"app"
.LC23:
	.string	"Search 'app': %d\n"
.LC24:
	.string	"\n--- Testing Graph ---"
.LC25:
	.string	"BFS: "
.LC26:
	.string	"DFS: "
.LC27:
	.string	"\n--- Testing Sorting ---"
.LC28:
	.string	"Bubble Sort: "
.LC29:
	.string	"%d "
.LC30:
	.string	"Quick Sort: "
.LC31:
	.string	"Merge Sort: "
.LC32:
	.string	"\n--- Testing Search ---"
	.section	.rodata.str1.8
	.align 8
.LC33:
	.string	"Linear Search 4: Found at index %d\n"
	.align 8
.LC34:
	.string	"Binary Search 4: Found at index %d\n"
	.section	.rodata.str1.1
.LC35:
	.string	"\nAll C tests passed!"
	.text
	.globl	main
	.type	main, @function
main:
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
	addq	$-128, %rsp
	.cfi_def_cfa_offset 160
	movq	%fs:40, %rax
	movq	%rax, 120(%rsp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdi
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
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	reverse@PLT
	movq	%rax, %rbx
	movq	%rax, %rdi
	call	print_singly@PLT
	movq	%rbx, %rdi
	call	has_cycle@PLT
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC3(%rip), %rdi
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
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC5(%rip), %rdi
	call	is_valid_parentheses@PLT
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC7(%rip), %rdi
	call	is_valid_parentheses@PLT
	movl	%eax, %esi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_stack@PLT
	leaq	.LC9(%rip), %rdi
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
	leaq	.LC10(%rip), %rbp
	movq	%rbp, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_queue@PLT
	leaq	.LC11(%rip), %rdi
	call	puts@PLT
	movl	$3, %edi
	call	create_circular_queue@PLT
	movq	%rax, %rbx
	movl	$1, %esi
	movq	%rax, %rdi
	call	cq_enqueue@PLT
	movl	$2, %esi
	movq	%rbx, %rdi
	call	cq_enqueue@PLT
	movl	$3, %esi
	movq	%rbx, %rdi
	call	cq_enqueue@PLT
	movq	%rbx, %rdi
	call	cq_is_full@PLT
	movl	%eax, %esi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	cq_dequeue@PLT
	movl	%eax, %esi
	movq	%rbp, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$4, %esi
	movq	%rbx, %rdi
	call	cq_enqueue@PLT
	movq	%rbx, %rdi
	call	free_circular_queue@PLT
	leaq	.LC13(%rip), %rdi
	call	puts@PLT
	movl	$1, %esi
	movl	$10, %edi
	call	create_heap@PLT
	movq	%rax, %rbx
	movl	$3, %esi
	movq	%rax, %rdi
	call	insert_heap@PLT
	movl	$1, %esi
	movq	%rbx, %rdi
	call	insert_heap@PLT
	movl	$2, %esi
	movq	%rbx, %rdi
	call	insert_heap@PLT
	movq	%rbx, %rdi
	call	extract_heap@PLT
	movl	%eax, %esi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_heap@PLT
	leaq	.LC15(%rip), %rdi
	call	puts@PLT
	movl	$10, %edi
	call	create_pq@PLT
	movq	%rax, %rbx
	movl	$5, %esi
	movq	%rax, %rdi
	call	pq_push@PLT
	movl	$10, %esi
	movq	%rbx, %rdi
	call	pq_push@PLT
	movq	%rbx, %rdi
	call	pq_pop@PLT
	movl	%eax, %esi
	leaq	.LC16(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	free_pq@PLT
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	movl	$5, %esi
	movl	$0, %edi
	call	bst_insert@PLT
	movq	%rax, %rdi
	movl	$3, %esi
	call	bst_insert@PLT
	movq	%rax, %rdi
	movl	$7, %esi
	call	bst_insert@PLT
	movq	%rax, %rbx
	movq	%rax, %rdi
	call	bst_inorder@PLT
	movl	$10, %edi
	call	putchar@PLT
	movq	%rbx, %rdi
	call	bst_free@PLT
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
	movl	$10, %esi
	movl	$0, %edi
	call	avl_insert@PLT
	movq	%rax, %rdi
	movl	$20, %esi
	call	avl_insert@PLT
	movq	%rax, %rdi
	movl	$30, %esi
	call	avl_insert@PLT
	movq	%rax, %rbx
	movq	%rax, %rdi
	call	avl_inorder@PLT
	movl	$10, %edi
	call	putchar@PLT
	movq	%rbx, %rdi
	call	avl_free@PLT
	leaq	.LC19(%rip), %rdi
	call	puts@PLT
	call	trie_create@PLT
	movq	%rax, %rbx
	leaq	.LC20(%rip), %rbp
	movq	%rbp, %rsi
	movq	%rax, %rdi
	call	trie_insert@PLT
	movq	%rbp, %rsi
	movq	%rbx, %rdi
	call	trie_search@PLT
	movl	%eax, %esi
	leaq	.LC21(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC22(%rip), %rsi
	movq	%rbx, %rdi
	call	trie_search@PLT
	movl	%eax, %esi
	leaq	.LC23(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	%rbx, %rdi
	call	trie_free@PLT
	leaq	.LC24(%rip), %rdi
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
	leaq	.LC25(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %esi
	movq	%rbx, %rdi
	call	bfs@PLT
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC26(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %esi
	movq	%rbx, %rdi
	call	dfs@PLT
	movl	$10, %edi
	call	putchar@PLT
	movq	%rbx, %rdi
	call	kruskal_mst@PLT
	movq	%rbx, %rdi
	call	free_graph@PLT
	leaq	.LC27(%rip), %rdi
	call	puts@PLT
	movl	$5, (%rsp)
	movl	$2, 4(%rsp)
	movl	$4, 8(%rsp)
	movl	$1, 12(%rsp)
	movl	$3, 16(%rsp)
	movq	%rsp, %rbx
	movl	$5, %esi
	movq	%rsp, %rdi
	call	bubble_sort@PLT
	leaq	.LC28(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	20(%rsp), %r12
	leaq	.LC29(%rip), %rbp
.L2:
	movl	(%rbx), %esi
	movq	%rbp, %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$4, %rbx
	cmpq	%r12, %rbx
	jne	.L2
	movl	$10, %edi
	call	putchar@PLT
	movl	$5, 32(%rsp)
	movl	$2, 36(%rsp)
	movl	$4, 40(%rsp)
	movl	$1, 44(%rsp)
	movl	$3, 48(%rsp)
	leaq	32(%rsp), %rbx
	movl	$4, %edx
	movl	$0, %esi
	movq	%rbx, %rdi
	call	quick_sort@PLT
	leaq	.LC30(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	52(%rsp), %r12
	leaq	.LC29(%rip), %rbp
.L3:
	movl	(%rbx), %esi
	movq	%rbp, %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$4, %rbx
	cmpq	%r12, %rbx
	jne	.L3
	movl	$10, %edi
	call	putchar@PLT
	movl	$5, 64(%rsp)
	movl	$2, 68(%rsp)
	movl	$4, 72(%rsp)
	movl	$1, 76(%rsp)
	movl	$3, 80(%rsp)
	leaq	64(%rsp), %rbx
	movl	$4, %edx
	movl	$0, %esi
	movq	%rbx, %rdi
	call	merge_sort@PLT
	leaq	.LC31(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	84(%rsp), %r12
	leaq	.LC29(%rip), %rbp
.L4:
	movl	(%rbx), %esi
	movq	%rbp, %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$4, %rbx
	cmpq	%r12, %rbx
	jne	.L4
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC32(%rip), %rdi
	call	puts@PLT
	movl	$1, 96(%rsp)
	movl	$2, 100(%rsp)
	movl	$3, 104(%rsp)
	movl	$4, 108(%rsp)
	movl	$5, 112(%rsp)
	leaq	96(%rsp), %rbx
	movl	$4, %edx
	movl	$5, %esi
	movq	%rbx, %rdi
	call	linear_search@PLT
	movl	%eax, %esi
	leaq	.LC33(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$4, %edx
	movl	$5, %esi
	movq	%rbx, %rdi
	call	binary_search@PLT
	movl	%eax, %esi
	leaq	.LC34(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC35(%rip), %rdi
	call	puts@PLT
	movq	120(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L10
	movl	$0, %eax
	subq	$-128, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L10:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
