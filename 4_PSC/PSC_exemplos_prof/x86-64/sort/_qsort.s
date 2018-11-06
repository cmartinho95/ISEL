/* memswap: swap the contents of two blocks of memory */
/***
void memswap(void *one, void *other, size_t width) {
	char tmp[width];
	memcpy(tmp, one, width);
	memcpy(one, other, width);
	memcpy(other, tmp, width);
}

Arguments and locals
- "one" is passed in %rdi and held in %rbx
- "other" passed in %rsi and held %r12 
- "witdth" is passed in %rdx and held %r13

%rbp is used as stack frame pointer
***/

	.text
	
memswap:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	pushq	%r12
	pushq	%r13
	subq	$8, %rsp			# alingn the %rsp at a 16 byte boundary
	
	movq	%rdi, %rbx 
	movq	%rsi, %r12
	movq	%rdx, %r13

# reserve enough stack space
	
	leaq	15(%rdx), %rax
	andq	$-16, %rax
	subq	%rax, %rsp

# memcpy(tmp, one, width);
	
	movq	%rdi, %rsi
	movq	%rsp, %rdi
#	call	memcpy
	call	_memcpy

# memcpy(one, other, width);

	movq	%r13, %rdx
	movq	%r12, %rsi
	movq	%rbx, %rdi
#	call	memcpy
	call	_memcpy

# memcpy(other, tmp, width);

	movq	%r13, %rdx
	movq	%rsp, %rsi
	movq	%r12, %rdi
#	call	memcpy
	call	_memcpy

# discard stack space and restore saved registers

	leaq	-24(%rbp), %rsp
	popq	%r13
	popq	%r12
	popq	%rbx
	popq	%rbp
	ret

/***
void quick_sort(void *data, size_t nel, size_t width, int (*compar)(const void *, const void *))
{
 	char *limit, *last, *ptr;

    if (nel < 2)
        return;
	limit = (char *)data + (nel * width);
	memswap_(data, (char *)data + (nel >> 1) * width, width);
	for (last = data, ptr = (char *)data + width; ptr < limit; ptr += width)
		if ((*compar)(ptr, data) < 0) {
			last += width;			
			memswap_(ptr, last, width);
		}
	memswap_(data, last, width);
	quick_sort(data, (last - (char *)data) / width, width, compar);
	quick_sort(last + width, ((limit - last) / width) - 1, width, compar);
}

Arguments and locals
- "data" is passed in %rdi and held in %rbx
- "nel" is passed in %rsi
- "width" is passed in %rdx and held in %rbp
- "compar" is passed in %rcx and held in %r12
- "limit" is held in %r13
- "last" is held in %r14
- "ptr" is held in %r15
***/

	.globl	quick_sort, _quick_sort
	
quick_sort:
_quick_sort:

# return if nel less than 2

	cmpq	$2, %rsi
	jae		1f
	ret
	
# save callee sabed registers and align %rsp
1:
	pushq	%rbx
	pushq	%rbp
	pushq	%r12
	pushq	%r13
	pushq	%r14
	pushq	%r15
	subq	$8, %rsp					# align %rsp to an address multiple of 16 byte 
	
# copy arguments to new registers
	movq	%rdi, %rbx					# %rbx = data
	movq	%rdx, %rbp					# %rbp = width
	movq	%rcx, %r12					# %r12 = compar
	
#	limit = (char *)data + (nel * width);
	
	movq	%rsi, %rax
	imulq	%rbp, %rax
	leaq	(%rbx, %rax), %r13			# %r13 = limit
	
#	memswap(data, (char *)data + (nel >> 1) * width, width);

	movq	%rbp, %rdx
	shrq	$1, %rsi
	imul	%rbp, %rsi
	addq	%rbx, %rsi
	movq	%rbx, %rdi
	call	memswap
/*
	for (last = data, ptr = (char *)data + width; ptr < limit; ptr += width)
		if ((*compar)(ptr, data) < 0) {
			last += width;			
			memswap(ptr, last, width);
		}
*/	
	movq	%rbx, %r14				# last = data
	leaq	(%rbx, %rbp), %r15		# ptr = (char *)data + width;
 	jmp		4f

2:
	movq	%rbx, %rsi
	movq	%r15, %rdi
	call	*%r12
	cmpl	$0, %eax
	jge		3f
	addq	%rbp, %r14			# last += width
	movq	%rbp, %rdx
	movq	%r14, %rsi
	movq	%r15, %rdi
	call	memswap
3:	
	addq	%rbp, %r15
	
4:
	cmpq	%r13, %r15
	jb		2b
	
#	memswap_(data, last, width);

	movq	%rbp, %rdx
	movq	%r14, %rsi
	movq	%rbx, %rdi
	call	memswap
	
#	quick_sort(data, (last - (char *)data) / width, width, compar);

	movq	%r12, %rcx

	movq	%r14, %rax
	subq	%rbx, %rax
	xorq	%rdx, %rdx		# %rax zero-extended into %rdx, %rax
	divq	%rbp
	movq	%rax, %rsi
	
	movq	%rbp, %rdx	
	movq	%rbx, %rdi
	call	quick_sort

#	quick_sort(last + width, ((limit - last) / width) - 1, width, compar);

	movq	%r12, %rcx

	movq	%r13, %rax
	subq	%r14, %rax
	xorq	%rdx, %rdx 		# %rax zero-extended into %rdx, %rax
	divq	%rbp
	leaq	-1(%rax), %rsi
	movq	%rbp, %rdx
	leaq	(%r14, %rbp), %rdi
	call	quick_sort
	
# restore saved registers and return

	addq	$8, %rsp
	popq	%r15
	popq	%r14
	popq	%r13
	popq	%r12
	popq	%rbp	
	popq	%rbx
	ret

