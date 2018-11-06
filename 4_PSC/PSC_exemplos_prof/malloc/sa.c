/**
 *
 *  ISEL; LEIC, Computacional Systems Programming (PSC)
 *
 *  A simple next-fit storage allocator
 *
 *  Dynamic Memory Allocation: CS-APP, Section 9.9
 *
 *  Bibliografia: The C Programming Language, Section 8.7 - A storage allocator
 * 
 *  Carlos Martins, November 2016
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* comment in order to use malloc() instead of sbrk */

#define USE_SBRK

typedef __int128 Align;		/* for alignment to 16 byte boundary  */

/* block header */
typedef union header {
	struct {
		union header *next;		/* next block if on free list */
		size_t size; 			/* size of this block */
	} s;
	Align x;				/* force alignment of blocks to a 16 byte boundary */
} Header;

static Header base;				/* empty list to get started */
static Header *freep = NULL; 	/* start of free list */

/* forward functions */
static Header *morecore(size_t);
void free_(void *);

/* malloc: general-purpose storage allocator */
void *malloc_(size_t nbytes)
{
	Header *p, *prevp;
	size_t nunits;
	
	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
	if ((prevp = freep) == NULL) { /* no free list yet */
		base.s.next = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp->s.next; ; prevp = p, p = p->s.next) {
		if (p->s.size >= nunits) {	/* big enough */
			if (p->s.size == nunits)	/* exactly */
				prevp->s.next = p->s.next;
			else {		/* allocate at tail end */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p + 1);
		}
		if (p == freep)		/* wrapped around free list */
			if ((p = morecore(nunits)) == NULL)
				return NULL;	/* none left */
	} 
}

#define NALLOC	4096	/* minimum #units to request */

/* morecore: ask system for more memory */

static Header *morecore(size_t nunits)
{
	char *cp;
	Header *up;
	void _free(void *);
	
	if (nunits < NALLOC)
		nunits = NALLOC;
#ifdef USE_SBRK
	if ((cp = (char *)sbrk(nunits * sizeof(Header))) == (char *)-1)
#else
	if ((cp = (char *)malloc(nunits * sizeof(Header))) == NULL)
#endif
		return NULL;		/* no space at all */
	up = (Header *)cp;
	up->s.size = nunits;
	free_((void *)(up + 1));
	return freep;
}

/* free: put block ap in free list */
void free_(void *ap)
{
	Header *bp, *p;
	
	bp = (Header *)ap - 1;		/* point to block header */
	for (p = freep; !(bp > p && bp < p->s.next); p = p->s.next)
		if (p >= p->s.next && (bp > p || bp < p->s.next))
			break;	/* freed block at start or end of arena */
	
	if (bp + bp->s.size == p->s.next) {		/* join to upper number */
		bp->s.size += p->s.next->s.size;
		bp->s.next = p->s.next->s.next;
	} else
		bp->s.next = p->s.next;
	if (p + p->s.size == bp) {	/* join to lower number */
		p->s.size += bp->s.size;
		p->s.next = bp->s.next;
	} else
		p->s.next = bp;
	freep = p;
}

/* print_free_blocks: prints the free block list */
static void print_free_blocks()
{
	Header *p = freep;
	
	do {
		printf("[block at: %p, size: %zd units]\n", p, p->s.size);
	} while ((p = p->s.next) != freep);	
}
  
#define NBLOCKS		10000
#define MIN_SIZE	8
#define MAX_SIZE	(1024 * 4)

void *blocks[NBLOCKS];

int main()
{
	int i;
	
	srand(clock());
	
	for (i = 0; i < NBLOCKS; i++) {
		blocks[i] = malloc_(rand() % MAX_SIZE + MIN_SIZE);
		if (blocks[i] == NULL)
			break;
	}
	printf("--after allocation:\n");
	print_free_blocks();
	for (--i; i >= 0; i--)
		free_(blocks[i]);
	printf("\n--before freeing\n");
	print_free_blocks();
	
	return 0;
}







