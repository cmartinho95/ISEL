/***

void *bsearch_(const void *key, const void *base, size_t nel, size_t width,
               int (*compar) (const void *, const void *))
{
	size_t low = 0, high = nel - 1;
	while (low <= high) {
		size_t mid = (low + high) / 2;
		char *midp = (char *)base + mid * width;
		int cond;
		if ((cond = (*compar)(midp, key)) < 0)
			low = mid + 1;
		else if (cond > 0)
			high = mid - 1;
		else
			return midp;
	}
	return NULL;
}

Arguments and locals:
- "key" is passed in %rdi and held at (%rsp)
- "base" is passed in %rsi and held at 8(%rsp)
- "nel" is held in %rdx
- "width" is passed in %rcx and held in %r15
- "compar" is passed in %r8 and held in %r14
- "low" is held in %r13
- "high" is held in %r12 
- "mid" is held in %rbx
- "midp" is held in %rbp

***/
	.globl	bsearch_, _bsearch_

bsearch_: _bsearch_:

# save all callee saved registers

	pushq	%rbx
	pushq	%rbp
	pushq	%r12
	pushq	%r13
	pushq	%r14
	pushq	%r15

# make room to locals "key" and "base", and align %rsp to an address multiple of 16 byte

	subq	$24, %rsp

# copy arguments to its final locations

	movq	%rdi, (%rsp)		# key at (%rsp)
	movq	%rsi, 8(%rsp)		# base at 8(%rsp)
	movq	%rcx, %r15			# width in %r15 
	movq	%r8, %r14			# compar in %r14 
	leaq	-1(%rdx), %r12		# high in %r12 = nel - 1
	movl	$0, %r13d			# low in %r13 = 0
	jmp		3f					# compute test-expr
1:
	leaq	(%r13, %r12), %rbx	# body statement
	shrq	%rbx				# %rbx : mid = (low + high) / 2
	movq	%rbx, %rbp			
	imulq	%r15, %rbp
	addq	8(%rsp), %rbp		# %rbp : midp
	movq	(%rsp), %rsi
	movq	%rbp, %rdi
	call	*%r14
	cmpl	$0, %eax
	jge		2f
	leaq	1(%rbx), %r13		# low = mid + 1
	jmp		3f
2:
	je		4f
	leaq	-1(%rbx), %r12		# high = mid - 1
3:
	cmpq	%r12, %r13
	jbe		1b
	movl	$0, %eax			# return NULL
	jmp		5f
4:
	movq	%rbp, %rax			# return midp
5:
	addq	$24, %rsp			# discard locals
	popq	%r15
	popq	%r14
	popq	%r13
	popq	%r12
	popq	%rbp
	popq	%rbx
	ret
