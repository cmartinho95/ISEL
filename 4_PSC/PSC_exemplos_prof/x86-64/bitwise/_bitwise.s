###
#
# ISEL, LEIC, Computer Systems Programming (PSC)
#
# Implementation in Assembly x86-64 of some bitwise utility functions: assembly versions
#
# Carlos Martins, October 2017
#
###

##
#	/* getbits: returns n bits of x from the position p */
#	unsigned getbits_(unsigned x, int p, int n)
#	{
#		return (x >> (p + 1 - n)) & ~(~0 << n);
#	}
#
#	Arguments and locals:
#	- x is held in %edi
#	- p is held in %esi
#	- n is held in %edx
##


 	.text

 	.text
	.globl	getbits

getbits:
	leal	1(%rsi), %ecx	# %eax = (x >> (p + 1 - n))
	subl	%edx, %ecx
	movl	%edi, %eax
	shrl	%cl, %eax
	movl	$-1, %esi		# %esi = ~(~0 << n)
	movl	%edx, %ecx
	shll	%cl, %esi
	not		%esi
	andl	%esi, %eax		# return, %eax, (x >> (p + 1 - n)) & ~(~0 << n)
	ret

##
#	/* setbits: sets the n bits of x from position p with the n lower bits of y */
#	unsigned setbits(unsigned x, int p, int n, unsigned y)
#	{
#		unsigned mask = ~((~(~0 << n)) << (p + 1 - n));
#   
#	    return (mask & x) | ((y & ~(~0 << n)) << (p + 1 - n));
#	}
#
#	Arguments and locals:
#	- x is held in %edi
#	- p is held in %esi
#	- n is held in %edx
#	- y is held in %ecx
##

 	.text
	.globl	setbits

setbits:

# mask, %eax = ~((~(~0 << n)) << (p + 1 - n))
	
	movl	%ecx, %r8d		# save y in order to use %ecx
	movl	$-1, %r9d
	movl	%edx, %ecx
	sall	%cl, %r9d
	notl	%r9d				# r9d = mask			
	leal	1(%rsi), %ecx
	subl	%edx, %ecx
	movl	%r9d, %eax
	sall	%cl, %eax			# %ecx = p + 1 - n
	notl	%eax

# return %eax = (mask & x) | ((y & ~(~0 << n)) << (p + 1 - n));

	andl	%edi, %eax		# %eax = mask & x		
	andl	%r9d, %r8d		# %r8d = (y & ~(~0 << n))
	sall	%cl, %r8d		# %r8d = ((y & ~(~0 << n)) << (p + 1 - n))
	orl		%r8d, %eax		# eax  = (mask & x) | ((y & ~(~0 << n)) << (p + 1 - n))
	ret
	
##
#	/* invert: invert n bits in x from position p */
#	unsigned invert_(unsigned x, int p, int n)
#	{
#		unsigned mask = (~(~0 << n)) << (p + 1 - n);
#	    return x ^ mask;
#	}
#
#	Arguments and locals: 
#	- x is held in %edi
#	- p is held in %esi
#	- n is held in %edx
##

	.text
	.globl	invert

invert:
	
# mask, %eax = 	(~(~0 << n)) << (p + 1 - n)

	movl	$-1, %eax
	movl	%edx, %ecx
	shll	%cl, %eax
	notl	%eax
	leal	1(%rsi), %ecx
	subl	%edx, %ecx
	shll	%cl, %eax
	
# return x ^ mask

	xorl	%edi, %eax
	ret

##
#	/* rightrot: returns x right rotated n bits */
#
#	#define UINT_BIT		((sizeof(unsigned) * CHAR_BIT))
#	#define HIGH_UINT_BIT	(1 << (UINT_BIT - 1))
#
#	unsigned rightrot(unsigned x, int n)
#	{
#		int i;
#
#		for (i = 0; i < n; i++) {
#			if (x & 1)
#				x = (x >> 1) | HIGH_UINT_BIT;
#			else
#				x >>= 1;
#		}
#		return x;
#	}
#
#	Arguments and locals:
#	- x is passed in %edi and held in %eax (return value)
#	- n is held in %esi
#	- i is held in %edx
##

	.text
	.globl	rightrot

# constantes

UINT_BIT = 32
HIGH_UINT_BIT = 1 << (UINT_BIT - 1)

	.text
	.globl	rightrot

rightrot:

	movl	%edi, %eax
	movl	$0, %edx				# i = 0
	jmp		4f
1:
	testb	$1, %al					# ? x & 1
	jz		2f
	shrl	$1, %eax				# x = (x << 1) | HIGH_UINT_BIT 
	orl		$HIGH_UINT_BIT, %eax
	jmp		3f
2:
	shrl	$1, %eax				# x >>= 1
3:
	addl	$1, %edx				# i++
4:
	cmpl	%esi, %edx				# ? i < n
	jl		1b
	ret								# ret x
	
##
#	/* rightrot2:  returns x right rotated n bits */
#	unsigned rightrot2_(unsigned x, int n)
#	{
#		unsigned y = x << UINT_BIT - n;
#		return (x >> n) | y;
#	}
#
#	Arguments and locals:
#	- x is held in %edi
#	- n is held in %esi
##

	.text
	.globl	rightrot2

rightrot2:

	movl	%edi, %eax
	movl	%esi, %ecx
	rorl	%cl, %eax
	ret

