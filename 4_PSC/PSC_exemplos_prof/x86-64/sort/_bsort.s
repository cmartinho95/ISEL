
/* bubble_sort: sorts the integer array in ascending order */
/***
void bubble_sort_(int items[], size_t length)
{
	size_t i;
	int swapped;
	
	do {
		swapped = 0;
		for (i = 0; i < length - 1; i++)
			if (items[i] > items[i + 1]) {
				int tmp = items[i];
				items[i] = items[i + 1];
				items[i + 1] = tmp;
				swapped = 1;
			}
		length -= 1;
	} while (swapped);
}

Arguments and locals:
- items is held in %rdi
- length is held in %rdi
-  i is held in %rax
- swapped is held in %r8d

***/

	.globl	bubble_sort, _bubble_sort
	.text

sizeof_int = 4

bubble_sort: _bubble_sort:

1:
	movl	$0, %r8d				# swapped = 0;
	movq	$0, %rax				# i = 0
	jmp		4f

2:
	movl	(%rdi, %rax, 4), %ecx		# test-expr = items[i] > items[i + 1]
	cmpl	sizeof_int(%rdi, %rax, sizeof_int), %ecx      # tmp: %ecx = items[i]
	jle		3f
	movl	sizeof_int(%rdi, %rax, sizeof_int), %edx
	movl	%edx, (%rdi, %rax, sizeof_int)
	movl	%ecx, sizeof_int(%rdi, %rax, sizeof_int)
	movl	$1, %r8d					# swapped = 1
3:
	leaq	1(%rax), %rax				# i++
	
4:	leaq	-1(%rsi), %rdx				# test-expr = i < length - 1
	cmpq	%rdx, %rax
	jb		2b
	testl	$1, %r8d
	jnz		1b
	ret
	
	
	
	

