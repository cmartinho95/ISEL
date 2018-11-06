	.file	"bitwise.c"
	.text
	.globl	getbits
	.type	getbits, @function
getbits:
.LFB23:
	.cfi_startproc
	subl	%edx, %esi
	leal	1(%rsi), %ecx
	movl	%edi, %eax
	shrl	%cl, %eax
	movl	$-1, %esi
	movl	%edx, %ecx
	sall	%cl, %esi
	notl	%esi
	andl	%esi, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	getbits, .-getbits
	.globl	getbits2
	.type	getbits2, @function
getbits2:
.LFB24:
	.cfi_startproc
	movl	$31, %ecx
	subl	%esi, %ecx
	sall	%cl, %edi
	movl	$32, %ecx
	subl	%edx, %ecx
	movl	%edi, %eax
	shrl	%cl, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	getbits2, .-getbits2
	.globl	setbits
	.type	setbits, @function
setbits:
.LFB25:
	.cfi_startproc
	movl	%ecx, %r8d
	movl	$-1, %r9d
	movl	%edx, %ecx
	sall	%cl, %r9d
	notl	%r9d
	subl	%edx, %esi
	leal	1(%rsi), %ecx
	movl	%r9d, %eax
	sall	%cl, %eax
	notl	%eax
	andl	%edi, %eax
	movl	%r9d, %edx
	andl	%r8d, %edx
	sall	%cl, %edx
	orl	%edx, %eax
	ret
	.cfi_endproc
.LFE25:
	.size	setbits, .-setbits
	.globl	invert
	.type	invert, @function
invert:
.LFB26:
	.cfi_startproc
	movl	$-1, %r8d
	movl	%edx, %ecx
	sall	%cl, %r8d
	notl	%r8d
	subl	%edx, %esi
	leal	1(%rsi), %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	xorl	%edi, %eax
	ret
	.cfi_endproc
.LFE26:
	.size	invert, .-invert
	.globl	rightrot
	.type	rightrot, @function
rightrot:
.LFB27:
	.cfi_startproc
	movl	%edi, %eax
	jmp	.L6
.L8:
	shrl	%eax
	testb	$1, %dil
	je	.L7
	orl	$-2147483648, %eax
.L7:
	shrl	%edi
	subl	$1, %esi
.L6:
	testl	%esi, %esi
	jg	.L8
	rep ret
	.cfi_endproc
.LFE27:
	.size	rightrot, .-rightrot
	.globl	rightrot2
	.type	rightrot2, @function
rightrot2:
.LFB28:
	.cfi_startproc
	movl	%edi, %eax
	movl	%esi, %ecx
	rorl	%cl, %eax
	ret
	.cfi_endproc
.LFE28:
	.size	rightrot2, .-rightrot2
	.globl	reverse
	.type	reverse, @function
reverse:
.LFB29:
	.cfi_startproc
	movl	$0, %esi
	movl	$-2147483648, %ecx
	movl	$1, %edx
	movl	$0, %eax
	jmp	.L11
.L14:
	testl	%edi, %edx
	je	.L12
	orl	%ecx, %eax
.L12:
	testl	%edi, %ecx
	je	.L13
	orl	%edx, %eax
.L13:
	addl	%edx, %edx
	shrl	%ecx
	addl	$1, %esi
.L11:
	cmpl	$15, %esi
	jbe	.L14
	rep ret
	.cfi_endproc
.LFE29:
	.size	reverse, .-reverse
	.globl	reverse2
	.type	reverse2, @function
reverse2:
.LFB30:
	.cfi_startproc
	movl	$0, %edx
	movl	$0, %eax
	jmp	.L16
.L19:
	movl	$1, %esi
	movl	%edx, %ecx
	sall	%cl, %esi
	testl	%edi, %esi
	je	.L17
	movl	$31, %ecx
	subl	%r8d, %ecx
	movl	$1, %r9d
	sall	%cl, %r9d
	orl	%r9d, %eax
.L17:
	movl	$31, %ecx
	subl	%r8d, %ecx
	movl	$1, %r8d
	sall	%cl, %r8d
	testl	%edi, %r8d
	je	.L18
	orl	%esi, %eax
.L18:
	addl	$1, %edx
.L16:
	movl	%edx, %r8d
	cmpl	$15, %edx
	jbe	.L19
	rep ret
	.cfi_endproc
.LFE30:
	.size	reverse2, .-reverse2
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"getbits(0xff000000, 27, 4): 0x%08x\n"
	.align 8
.LC1:
	.string	"getbits2(0xff000000, 27, 4): 0x%08x\n"
	.align 8
.LC2:
	.string	"setbits(0x33333333, 31, 8, 0xff): 0x%08x\n"
	.align 8
.LC3:
	.string	"invert(0xaa333333, 31, 8): 0x%08x\n"
	.align 8
.LC4:
	.string	"rightrot(0x55000000, 8): 0x%08x\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC5:
	.string	"reverse(0xaa0000aa): 0x%08x\n"
.LC6:
	.string	"reverse2(0xaa0000aa): 0x%08x\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB31:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$4, %edx
	movl	$27, %esi
	movl	$-16777216, %edi
	call	getbits
	movl	%eax, %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$4, %edx
	movl	$27, %esi
	movl	$-16777216, %edi
	call	getbits2
	movl	%eax, %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$255, %ecx
	movl	$8, %edx
	movl	$31, %esi
	movl	$858993459, %edi
	call	setbits
	movl	%eax, %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$8, %edx
	movl	$31, %esi
	movl	$-1439485133, %edi
	call	invert
	movl	%eax, %edx
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$8, %esi
	movl	$1426063360, %edi
	call	rightrot2
	movl	%eax, %edx
	movl	$.LC4, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$-1442840406, %edi
	call	reverse
	movl	%eax, %edx
	movl	$.LC5, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$-1442840406, %edi
	call	reverse2
	movl	%eax, %edx
	movl	$.LC6, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE31:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
