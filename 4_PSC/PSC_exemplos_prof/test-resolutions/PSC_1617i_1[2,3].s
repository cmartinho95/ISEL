/*
 * Teste de 1ª Época do Semestre de Inverno de 2016/17
 */


/***
 2.

typedef struct data_item {
	const char *label;
	short value;
} DataItem;

const char *find_by_value(DataItem *pitems[], short val) {
  for (size_t i = 0; pitems[i] != NULL; i++)
    if (pitems[i]->value == val)
		return pitems[i]->label;
  return NULL;
}

***/

/*
 * Arguments and local variables
 
 - pitems is held in %rdi
 - val is held in %rsi (%siw)
 - i is held in %rcx
 
*/

/*
 * Structure offsets
 */
 
data_item_label_off = 0
data_item_value_off = 8

	.text
	.globl	find_by_value, _find_by_value

find_by_value: _find_by_value:

	movq	$0, %rcx
	jmp		3f
1:
	movq	(%rdi, %rcx, 8), %rdx
	movw	data_item_value_off(%rdx), %ax
	cmpw	%ax, %si
	jne		2f
	movq	data_item_label_off(%rdx), %rax
	ret
2:
	addq	$1, %rcx

3:
	cmpq	$0, (%rdi, %rcx, 8)
	jne		1b
	xorq	%rax, %rax
	ret

/***
3a.

size_t select_if_(void *items[], size_t nelems, int (*select)(const void *)) {
	size_t selected;
	void **src, **dst, **last = &items[nelems - 1];
	
	for (selected = 0, src = dst = items; src <= last; src++)
		if ((*select)(*src) != 0) {
			*dst = *src;
			selected++;
			dst++;
		}
	return selected;				 
}

***/

/*
 * Arguments and local variables
 
 - items is passed in %rdi
 - nelems is passed in %rsi
 - select is passed in %rdx and held in %r12
 - selected is held in %r13
 - src is held in %r14
 - dst is held in %r15
 - last is held in %rbx
*/	

	.text
	.global	select_if, _select_if

select_if: _select_if:

	pushq	%r12
	pushq	%r13
	pushq	%r14
	pushq	%r15
	pushq	%rbx

# save select function pointer in %r12
	movq	%rdx, %r12
	
# for init-expr: selected = 0, src = dst = items

	movq	$0, %r13					# selected
	movq	%rdi, %r14					# src
	movq	%rdi, %r15					# dst
	leaq	-8(%rdi, %rsi, 8), %rbx		# last
	jmp		3f
	
# for body-statement: 
1:	
	movq	(%r14), %rdi
	call	*%r12
	orl		%eax, %eax
	jz		2f
	movq	(%r14), %rax
	movq	%rax, (%r15)
	addq	$1, %r13
	addq	$8, %r15

2:
# for update-expr : src++
	addq	$8, %r14

# for test-expr: src <= last

3:
	cmpq	%rbx, %r14
	jbe		1b

# return copied

	movq	%r13, %rax

# pops and return
	
	popq	%rbx
	popq	%r15
	popq	%r14
	popq	%r13
	popq	%r12
	ret
	
