###
#
# ISEL, LEIC, Computer Systems Programming (PSC)
#
# Implementation in Assembly x86-64 of some string utility functions: assembly versions
#
# Carlos Martins, April 2017
#
###

##
#	/* _strncmp: compare strings (array version) */ 
#	int _strncmp_(const char s1[], const char s2[], size_t n)
#	{
#		size_t i;
#
#		for (i = 0; i < n && s1[i] == s2[i]; i++)
#			if (s1[i] == '\0')
#				return 0;
#		return s1[i] - s2[i];
#	}
#	Arguments and locals:
#	- s1 is held in %rdi
#	- s2 is held in %rsi
#	- n is held in %rdx
#	- i is held in %rcx
##

	.text
	.globl	_strncmp
	
_strncmp:
	xorq	%rcx, %rcx			# i = 0
	jmp		3f

1:
	cmpb	$0, (%rdi, %rcx)	# ? s1[i] == '\0'
	jne		2f
	xorl	%eax, %eax			# return 0
	ret

2:
	addq	$1, %rcx			# i++

3:
	cmpq	%rdx, %rcx			# ? i < n
	jae		3f
	movb	(%rdi, %rcx), %al	# si[i] == s2[i]
	cmpb	%al, (%rsi, %rcx)
	je		1b

3:
	movb	(%rdi, %rcx), %al	# return s1[i] - s2[i]
	subb	(%rsi, %rcx), %al
	movsbl	%al, %eax
	ret

##
#	/* _strncmp: compare strings (pointer version) */ 
#	int _strncmp2(const char *s1, const char *s2, size_t n)
#	{
#		for (; n > 0 && *s1 == *s2; s1++, s2++, n--)
#			if (*s1 == '\0')
#				return 0;
#		return *s1 - *s2;
#	}
#
#	Arguments and locals:
#	- s1 is held in %rdi
#	- s2 is held in %rsi
#	- n is held in %rdx
##

	.text
	.globl	_strncmp2
	
_strncmp2:

	jmp		3f
1:
	cmpb	$0, (%rdi)		# ? (*s1 == '\0)  
	jne		2f
	xorl	%eax, %eax		# return 0
	ret
2:
	addq	$1, %rdi		# s1++
	addq	$1, %rsi		# s2++
	subq	$1, %rdx		# n--
3:
	cmpq	$0, %rdx		# ? n > 0
	jbe		4f
	movb	(%rdi), %al		# && *s1 == *s2
	cmpb	(%rsi), %al
	je		1b
4:
	movsbl	(%rdi), %eax	# return *s1 - *s2
	movsbl	(%rsi), %ecx
	subl	%ecx, %eax
	ret

##	/* _strcat: concatenate strings (array version)*/ 
#	char *_strcat_(char dst[], const char src[])
#	{
#		size_t i, j;
#
#		for (i = 0; dst[i] != '\0'; i++)
#			;
#		for (j = 0; (dst[i] = src[j]) != '\0'; i++, j++)
#			;
#		return ret;
#	}
#
#	Arguments and locals:
#	- dst is held in %rdi
#	- src is hel in %rsi
#	- i is held in %rdx
#	- j is held in %rcx
##

	.text
	.globl	_strcat
	
_strcat:

	xorq	%rdx, %rdx		# i = 0
	jmp		2f

1:
	addq	$1, %rdx
	
2:
	cmpb	$0, (%rdi, %rdx)	# ? dst[i] != '\0'
	jne		1b

	xorq	%rcx, %rcx			# j = 0
	jmp		4f

3:
	addq	$1, %rdx			# i++
	addq	$1, %rcx			# j++
4:
	movb	(%rsi, %rcx), %al
	movb	%al, (%rdi, %rdx)
	orb		%al, %al
	jnz		3b

	movq	%rdi, %rax
	ret							# return ret

	
##
#	/* _strcat: concatenate strings (pointer version)*/
#	char *_strcat(char *dst, const char *src)
#	{
#		char *ret = dst;
#		while (*dst != '\0')
#			dst++;
#		while ((*dst++ = *src++) != '\0')
#			;
#		return ret;
#	}
#
#	Arguments and locals:
#	- dst is held in %rdi
#	- src is hel in %rsi
#	- ret is held in %rax
##

	.text
	.globl	_strcat2
	
_strcat2:

	movq	%rdi, %rax		# ret = dst
	jmp		2f
1:
	addq	$1, %rdi		# dst++
2:
	cmpb	$0, (%rdi)		# ? *dst != '\0'
	jne		1b
3:
	movb	(%rsi), %cl		# ? (*dst++ = *src++) != '\0'
	movb	%cl, (%rdi)
	leaq	1(%rsi), %rsi
	leaq	1(%rdi), %rdi
	testb	%cl, %cl
	jnz		3b
	ret						# return ret

##
#	/* strncpy: copy strings at most len characters */
#	char *_strncpy(char *dst, const char *src, size_t len)
#	{
#		size_t n;
#		char *p;
#
#		for (p = dst, n = 0; n < len && (*p++ = *src++) != '\0'; n++)
#			;
#		for (; n < len; n++)
#			*p++ = '\0';
#		return dst;
#	}
#
#	Arguments and locals:
#	- dst is held in %rdi
#	- src is held in %rsi
#	- len is held in %rdx
#	- n is held in %rcx
#	- p is held in %r8
##

	.text
	.globl	_strncpy

_strncpy:
	
	movq	%rdi, %r8		# p = dst
	xorq	%rcx, %rcx		# n = 0
	jmp		2f
1:
	addq	$1, %rcx		# n++	
2:
	cmpq	%rdx, %rcx		# ? n < len
	jae		5f
	movb	(%rsi), %al		# && (*p++ = *src++) != '\0'
	movb	%al, (%r8)
	leaq	1(%r8), %r8
	leaq	1(%rsi), %rsi
	testb	%al, %al
	jnz		1b
3:
	jmp		5f
4:
	movb	$0, (%r8)		# *p++ = '\0'
	leaq	1(%r8), %r8
	addq	$1, %rcx		# n++
5:
	cmpq	%rdx, %rcx		# ? n < len
	jb		4b
	movq	%rdi, %rax		# ret dst
	ret

##
#	/* _strstr: locate the first occurrence of a substring in a string */
#	char *_strstr(const char *big, const char *little)
#	{
#		size_t i;
#
#		for (; *big != '\0'; big++) {
#			if (*big == *little) {
#				for (i = 1; little[i] != '\0' && big[i] == little[i]; i++)
#					;
#				if (little[i] == '\0')
#					return (char *)big;
#			}
#		}
#		return NULL;
#	}
#
#	Arguments and locals
#	- big is held in %rdi
#	- little is held in %rsi
#	- i is held in %rdx
##

	.text
	.globl	_strstr
	
_strstr:
	jmp		6f
1:								
	movb	(%rdi), %al
	cmpb	(%rsi), %al
	jne		5f	
	movl	$1, %edx			# i = 1
	jmp		3f
2:
	addq	$1, %rdx			# i++
3:
	movb	(%rsi, %rdx), %al	# ? little[i] != 0
	testb	%al, %al
	jz		4f
	cmpb	%al, (%rdi, %rdx)	# && big[i] == little[i]
	je		2b
4:
	testb	%al, %al			# ? little[i] == '\0'
	jne		5f
	movq	%rdi, %rax			# return (char *)big
	ret
5:
	addq	$1, %rdi			# big++
6:
	cmpb	$0, (%rdi)			# ? *big != '\0'
	jne		1b
	xorq	%rax, %rax			# return NULL
	ret

##
#	/* _strrstr: locate the last occurrence of a substring in a string */
#
#	char *_strrstr(const char *big, const char *little)
#	{
#		size_t i;
#		char *last = NULL;
#
#		for (; *big != '\0'; ++big) {
#			if (*big == *little) {
#				for (i = 1; little[i] != '\0' && big[i] == little[i]; i++)
#					;
#				if (little[i] == '\0') {
#					last = (char *)big;
#					big += i;
#				}
#			}
#		}
#		return last;
#	}
#
#	Arguments and locals:
#	- big is held in %rdi
#	- little is held in %rsi
#	- i is held in %rdx
#	- last is held in %rax
##

	.text
	.globl	_strrstr
	
_strrstr:
	xorq	%rax, %rax			# last = NULL
	jmp		6f
1:
	movb	(%rdi), %cl			# ? *big == *little
	cmpb	(%rsi), %cl
	jne		5f
	movq	$1, %rdx			# i = 1
	jmp		3f
2:
	addq	$1, %rdx			# i++
3:
	movb	(%rsi, %rdx), %cl	# ? little[i] != '\0'
	testb	%cl, %cl
	jz		4f
	cmpb	%cl, (%rdi, %rdx)	# && big[i] == little[i]
	je		2b
4:
	testb	%cl, %cl			# ? little[i] == '\0'
	jnz		5f
	movq	%rdi, %rax			# last = (char *)big
	addq	%rdx, %rdi			# big += i
5:
	addq	$1, %rdi
6:
	cmpb	$0, (%rdi)			# ? *big != '\0'
	jne		1b
7:
	ret							# return last

##	
#	/* _strend: check if a string ends with another string */
#
#	int _strend(const char *s, const char *t)
#	{
#		size_t slen = strlen(s);
#		size_t tlen = strlen(t);
#		const char *p;
#
#		if (tlen > slen)
#			return 0;
#		for (p = s + slen - tlen; *t != '\0' && *t == *p; p++, t++)
#			;
#		return *t == '\0';
#	}
#
#	Arguments and locals:
#	- s is passed in %rdi and held in %r12
#	- t is passed in %rsi and held in %rbp
#	- slen is held in %rbx
#	- tlen is held in %rax
#	- p is held in %rax
##

	.text
	.globl	_strend
	
_strend:

	pushq	%r12				# save callee saved registers
	pushq	%rbp
	pushq	%rbx				# this sequence leaves %rsp aligned to a 16 byte boundary 
	movq	%rdi, %r12			# save s in %r12
	movq	%rsi, %rbp			# save t in %rbp
	call	strlen				# slen = strlen(s)
	movq	%rax, %rbx
	movq	%rbp, %rdi			# tlen = strlen(t);
	call	strlen
	cmpq	%rbx, %rax			# ? tlen > slen
	jae		4f
	subq	%rax, %rbx			# p = s + slen - tlen
	leaq	(%r12, %rbx), %rax
	jmp		2f
1:
	leaq	1(%rax), %rax		# p++
	leaq	1(%rbp), %rbp		# t++
2:
	movb	(%rbp), %dl			# ? *t != '\0'
	testb	%dl, %dl
	jz		3f
	cmpb	%dl, (%rax)			# && *t == *p
	je		1b
3:
	testb	%dl, %dl			# return *t == '\0'
	setz	%al
	movzbl	%al, %eax
	jmp		5f
4:
	xorl	%eax, %eax			# return 0
5:
	popq	%rbx				# restore callee saved registers
	popq	%rbp
	popq	%r12
	ret
	
##
#	/* _strend2: check if a string ends with another string */
#	int _strend2_(const char *s, const char *t)
#	{
#		char *p = _strrstr(s, t);
#		return p == NULL ? 0 : strcmp(p, t) == 0;
#	}
#
#	Arguments and locals:
#	- s is held in %rdi
#	- t is passed in %rsi and held in %r12
#	- p is held in %rax
##

	.text
	.globl	_strend2
	
_strend2:
	pushq	%r12			# save callee saved register ensuring %rsp alignment
	movq	%rsi, %r12		# save t in %r12
	call	_strrstr		# p = _strrstr(s, t) /* s and t are already in %rdi e %rsi
	orq		%rax, %rax
	jnz		1f
	jmp		2f				# return 0
1:
	movq	%rax, %rdi		# return strcmp(p, t) == 0
	movq	%r12, %rsi
	call	strcmp
	orl		%eax, %eax		# return 1 if strcmp returns 0 otherwise return 0
	setz	%al
	movzbl	%al, %eax
2:
	popq	%r12
	ret



	