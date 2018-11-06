/*
 * Teste de 2ª Época do Semestre de Inverno de 2016/17
 */


/***
2.

typedef struct item {
	int code;
	int *prices;
} Item;

int get_price(Item items[], size_t nitems, int code, int quantity) {
	for (size_t i = 0; i < nitems; ++i)
		if (items[i].code == code)
			return items[i].prices[quantity];
	return -1;
}

***/

/*
 * Arguments and local variables
 
- items is held in %rdi
- nitems is held in %rsi
- code is held in %edx
- quantity is held in %ecx
- i is held in %r8
*/

/*
 * Structure offsets
 */
 
item_code_off = 0
item_prices_off = 8
item_size = 16			# 4 byte padding to align the pointer field ("prices")

	.text
	.globl	get_price, _get_price

get_price: _get_price:
	
# for init-expr: i = 0

	movq	$0, %r8
	jmp		3f
1:
	movq	%r8, %r9
	imulq	$item_size, %r9
	cmpl	%edx, item_code_off(%rdi, %r9)
	jne		2f
	movq	item_prices_off(%rdi, %r9), %r9
	movl	%ecx, %ecx				# zero the 32 high-order bits (quantity is an int)
	movl	(%r9, %rcx, 4), %eax	# eax = items[i].prices[quantity]
	ret
2:
	addq	$1, %r8

3:
	cmpq	%rsi, %r8
	jb		1b
	movl	$-1, %eax
	ret

/***
3.

typedef struct list_node {
	struct list_node *next;
	void *data;
} ListNode;

ListNode *list_search(const ListNode *list, int (*compar)(const void *, const void *),
                      const void *context) {
  for (ListNode *p = list->next; p != NULL; p = p->next)
    if ((*compar)(p->data, context) == 0)
      return p;
  return NULL;
}

***/

/*
 * Arguments and local variables
 
 . list is passed in %rdi
 . compar is passed in %rsi and held in %r12
 . context is passed in %rdx and held in %r13
 . p is held in %r14
*/	

ListNode_next_off = 0
ListNode_data_off = 8

	.text
	.global	list_search, _list_search

list_search: _list_search:

	pushq	%r12
	pushq	%r13
	pushq	%r14

# save compar function pointer in %r12 and context in %r13
	movq	%rsi, %r12
	movq	%rdx, %r13
	
# for init-expr: p = list->next

	movq	ListNode_next_off(%rdi), %r14			# p
	jmp		3f
	
# for body-statement: 
1:	
	movq	ListNode_data_off(%r14), %rdi
	movq	%r13, %rsi
	call	*%r12
	orl		%eax, %eax
	jnz		2f
	movq	%r14, %rax
	jmp		4f
2:
# for update-expr : p = p->next

	movq	ListNode_next_off(%r14), %r14

# for test-expr: p != NULL
3:
	orq		%r14, %r14
	jnz		1b
	
# return NULL

	movq	$0, %rax

# pops and return

4:
	popq	%r14
	popq	%r13
	popq	%r12
	ret

