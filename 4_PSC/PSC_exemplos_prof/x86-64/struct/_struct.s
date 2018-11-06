/**
 * ISEL, LEIC, Computacional Systems Programming (PSC)
 *
 * Accessing structures in assembly x86-64.
 *
 * Carlos Martins, November 2016
 *
 **/

/*
 * 3. first final exam, Summer 2015/16
 */

/*
typedef struct dblock {
	const char *label;
	size_t length;
	short values[8];
} DBlock;
*/

# offsets of struct dblock's fields and structure size

/*
	.struct	0
label_off:
	.struct label_off + 8
length_off:
	.struct length_off + 8
values_off:
	.struct	values_off + 2 * 8
DBlock_size: 
*/

/* or */

label_off = 0
length_off = label_off + 8
values_off = length_off + 8
DBlock_size = values_off + 2 * 8 

/*	
typedef struct dblock_node {
	struct dblock_node *next;
	DBlock *data;
} DBlockNode;
*/

# offsets of struct dblock_node's fields and structure size
/*
	.struct	0
next_off:
	.struct next_off + 8
data_off:
	.struct data_off + 8
DBlockNode_size: 
*/

/* or */
next_off = 0
data_off = next_off + 8
DBlockNode_size = data_off + 8 

/***
const char *find_dblock(DBlockNode *dblist, short value) {
	for(; dblist != NULL; dblist = dblist->next) {
		size_t i;
		DBlock *db = dblist->data;
		for(i = 0; i < db->length; i++)
			if(db->values[i] == value)
				return db->label;
	}
	return NULL;
}

Arguments and locals:
- dblist is at %rdi
- value is at %si
- db is held in %rdx
- i is held in %rax
***/

	.globl	find_dblock, _find_dblock
	.text
	
find_dblock: _find_dblock:

	jmp		5f

1:
	movq	data_off(%rdi), %rdx
	movl	$0, %eax
	jmp		4f

2:
	cmpw	%si, values_off(%rdx, %rax, 2)
	jne		3f
	movq	label_off(%rdx), %rax
	ret

3:
	addq	$1, %rax
	
4:
	cmpq	length_off(%rdx), %rax
	jb		2b
	
	movq	next_off(%rdi), %rdi

5:
	testq	%rdi, %rdi
	jnz		1b
	movq	$0, %rax
	ret
	
	
/***
struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

struct colored_rect {
	struct point pt1;
	struct point pt2;
	int color;
};
***/

# offsets of struct point
x_off = 0
y_off = x_off + 4
point_size = y_off + 4
 
# offsets of struct rect
pt1_off = 0
pt2_off = pt1_off + 8
rect_size = pt2_off + 8

# offsets of struct colored_rect
pt1_off = 0
pt2_off = pt1_off + 8
color_off = pt2_off + 8
colored_rect_size = color_off + 4

/* make_point: make a point from x and y components */
/***
struct point make_point(int x, int y)
{
	struct point result;
	
	result.x = x;
	result.y = y;
	return result;
}
Arguments and return value:
- x in held in %edi
- y in held in %esi
- return value %rax (hsdw: y; lsdw: x)
***/
	.globl	_make_point
	.text

_make_point:
	sall	$32, %esi		# move y to the hsdw
	movl	%edi, %eax
	orq		%rsi, %rax		# combine x and y
	ret

/* make_rect: make a point from pt1 and pt2 components */
/***
struct rect make_rect(struct point pt1, struct point pt2)
{
	struct rect result;
	
	result.pt1 = pt1;
	result.pt2 = pt2;
	return result;
}
Arguments and return value:
- pt1 in held in %rdi
- pt2 in held in %rsi
- return value %rax, %rdx (rect.pt1: %rax; rect.pt2: %rdx)
***/

	.globl	_make_rect
	.text

_make_rect:
	movq	%rdi, %rax
	movq	%rsi, %rdx
	ret

/* make_color_rect: make a point from pt1, pt2 and color components */
/***
struct colored_rect make_colored_rect(struct point pt1, struct point pt2, int color)
{
	struct colored_rect result;
	
	result.pt1 = pt1;
	result.pt2 = pt2;
	result.color = color;
	return result;
}

Arguments and return value:
- %rdi hidden parameter to return structure
- pt1 is held in %rsi
- pt2 in held in %rdx
- color in held in %ecx
- return value is passed via hidden parameter, %rax equal to the hidden parameter
***/

	.globl	_make_colored_rect
	.text

_make_colored_rect:
	movq	%rdi, %rax
	movq	%rsi, pt1_off(%rdi)
	movq	%rdx, pt2_off(%rdi)
	movl	%ecx, color_off(%rdi)
	ret


/* shift_rect: ... */
/***
struct rect shift_rect(struct rect rt, int deltax, int deltay)
{
	struct rect result;
	
	result.pt1.x = rt.pt1.x + deltax;
	result.pt1.y = rt.pt1.y + deltay;
	result.pt2.x = rt.pt2.x + deltax;
	result.pt2.y = rt.pt2.x + deltay;
	return result;
}

Arguments and return value:
- rt is held in %rdi and %rsi
- deltax in held in %edx
- deltay in held in %ecx
- return value is passed in %rax, %rdx

***/
	.globl	_shift_rect
	.text

_shift_rect:
	movq	%rdi, %rax
	sarq	$32, %rax
	leal	(%rcx,%rax), %eax
	salq	$32, %rax
	leal	(%rdx,%rdi), %edi
	orq	%rdi, %rax
	leal	(%rcx,%rsi), %ecx
	salq	$32, %rcx
	leal	(%rdx,%rsi), %edx
	orq	%rcx, %rdx
	ret

/* shift_color_rect: ... */
/***
struct colored_rect shift_color_rect(struct colored_rect rt, int deltax, int deltay)
{
	struct colored_rect result;
	
	result.pt1.x = rt.pt1.x + deltax;
	result.pt1.y = rt.pt1.y + deltay;
	result.pt2.x = rt.pt2.x + deltax;
	result.pt2.y = rt.pt2.x + deltay;
	result.color = rt.color;
	return result;
}

Arguments and return value:
- %rdi is the hidden argument that points to the result
- rt is held at 8(%rsp)
- deltax in held in %esi
- deltay in held in %edx
- return value is passed through %rdi and %rax
***/

	.globl	_shift_colored_rect
	.text

_shift_colored_rect:

	movq	%rdi, %rax			# %rax = %rdi = hidden argument
	movl	%esi, %ecx
	addl	8(%rsp), %ecx
	movl	%ecx, (%rdi)
	movl	%edx, %ecx
	addl	12(%rsp), %ecx
	movl	%ecx, 4(%rdi)
	movl	16(%rsp), %ecx
	addl	%ecx, %esi
	movl	%esi, 8(%rdi)
	addl	%edx, %ecx
	movl	%ecx, 12(%rdi)
	ret
