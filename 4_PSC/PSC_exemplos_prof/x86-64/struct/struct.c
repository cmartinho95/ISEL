/**
 * ISEL, LEIC, Computacional Systems Programming (PSC)
 *
 * Accessing structures in assembly x86-64.
 *
 * Carlos Martins, November 2016
 *
 **/


#include <stdio.h>

/*
 * 3. first final exam, Summer 2015/16
 */

typedef struct dblock {
	const char *label;
	size_t length;
	short values[8];
} DBlock;

typedef struct dblock_node {
	struct dblock_node *next;
	DBlock *data;
} DBlockNode;

const char *find_dblock_(DBlockNode *dblist, short value) {
	for(; dblist != NULL; dblist = dblist->next) {
		size_t i;
		DBlock *db = dblist->data;
		for(i = 0; i < db->length; i++)
			if(db->values[i] == value)
				return db->label;
	}
	return NULL;
}

/* assembly version */
const char *find_dblock(DBlockNode *dblist, short value);

/* test data */

DBlock db1 = { .label = "first", .length = 1, .values  = {1} };
DBlock db2 = { .label = "second", .length = 2, .values  = {2, 3} };
DBlock db3 = { .label = "third", .length = 3, .values  = {3, 4, 5} };
DBlock db4 = { .label = "fourth", .length = 4, .values  = {4, 5, 6, 7} };
DBlock db5 = { .label = "fifth", .length = 5, .values  = {5, 6, 7, 8, 9} };
DBlock db6 = { .label = "sixth", .length = 6, .values  = {6, 7, 8, 9, 10, 11} };
DBlock db7 = { .label = "sixth", .length = 7, .values  = {7, 8, 9, 10, 11, 12, 13} };
DBlock db8 = { .label = "eighth", .length = 8, .values  = {8, 9, 10, 11, 12, 13, 14, 15} };

DBlockNode dbn8 = { .next = NULL,  .data = &db8 };
DBlockNode dbn7 = { .next = &dbn8, .data = &db7 };
DBlockNode dbn6 = { .next = &dbn7, .data = &db6 };
DBlockNode dbn5 = { .next = &dbn6, .data = &db5 };
DBlockNode dbn4 = { .next = &dbn5, .data = &db4 };
DBlockNode dbn3 = { .next = &dbn4, .data = &db3 };
DBlockNode dbn2 = { .next = &dbn3, .data = &db2 };
DBlockNode dbn1 = { .next = &dbn2, .data = &db1 };

/* used version */

#define __find_dblock	find_dblock

void test_struct_field_access()
{
	int i;
	const char *label;
	
	for (i = 1; i <= 8; i++) {
		label = __find_dblock(&dbn1, i);
		printf("--[%d]: %s\n", i, label ? label : "not found");
	}
	label = __find_dblock(&dbn1, 0);
	printf("--[%d]: %s\n", 0, label ? label : "not found");
}

/**
 * passing structures by value
 **/

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

/* make_point: make a point from x and y components */
struct point make_point(int x, int y)
{
	struct point result;
	
	result.x = x;
	result.y = y;
	return result;
}

/* make_rect: make a point from pt1 and pt2 components */
struct rect make_rect(struct point pt1, struct point pt2)
{
	struct rect result;
	
	result.pt1 = pt1;
	result.pt2 = pt2;
	return result;
}

/* make_color_rect: make a point from pt1, pt2 and color components */
struct colored_rect make_colored_rect(struct point pt1, struct point pt2, int color)
{
	struct colored_rect result;
	
	result.pt1 = pt1;
	result.pt2 = pt2;
	result.color = color;
	return result;
}

/* shift_rect: ... */
struct rect shift_rect(struct rect rt, int deltax, int deltay)
{
	struct rect result;
	
	result.pt1.x = rt.pt1.x + deltax;
	result.pt1.y = rt.pt1.y + deltay;
	result.pt2.x = rt.pt2.x + deltax;
	result.pt2.y = rt.pt2.x + deltay;
	return result;
}

/* shift_color_rect: ... */
struct colored_rect shift_color_rect(struct colored_rect rt, int deltax, int deltay)
{
	struct colored_rect result;
	
	result.pt1.x = rt.pt1.x + deltax;
	result.pt1.y = rt.pt1.y + deltay;
	result.pt2.x = rt.pt2.x + deltax;
	result.pt2.y = rt.pt2.x + deltay;
	return result;
}

/* print_point: print x and y components of a point */
void print_point(struct point pt)
{
	printf("(%d, %d)\n", pt.x, pt.y);
}

/* print_rect: print pt1 and pt2 components of a point */
void print_rect(struct rect rt)
{
	printf("{(%d, %d); (%d, %d)}\n", rt.pt1.x, rt.pt1.y, rt.pt2.x, rt.pt2.y);
}

/* print_rect: print pt1 and pt2 components of a point */
void print_color_rect(struct colored_rect rt)
{
	printf("{%d, [(%d, %d); (%d, %d)]}\n", rt.color, rt.pt1.x, rt.pt1.y, rt.pt2.x, rt.pt2.y);
}

/* add_points: add two points */
struct point add_points(struct point pt1, struct point pt2)
{
	pt1.x += pt2.x;
	pt1.y += pt2.y;
	return pt1;
}

/*point_in_rect: return 1 if p in r, 0 if not */
int point_in_rect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b)	((a) < (b) ? (a) : (b))
#define max(a, b)	((a) > (b) ? (a) : (b))

/* canon_rect: canonicalize coordinates of rectangle */
struct rect canon_rect(struct rect r)
{
	struct rect result;
	
	result.pt1.x = min(r.pt1.x, r.pt2.x);
	result.pt1.y = 	min(r.pt1.y, r.pt2.y);
	result.pt2.x = max(r.pt1.x, r.pt2.x);
	result.pt2.y = max(r.pt1.y, r.pt2.y);
	return result;
}



/**
 * main
 **/

int main()
{
	test_struct_field_access();

	/***
	struct point pt1, pt2, pt3;
	struct rect rt, rt2;
	struct colored_rect crt;
	
	pt1 = make_point(100, 0);
	//print_point(pt1);
	pt2 = make_point(0, 100);
	/*
	print_point(pt2);
	pt3 = add_points(pt1, pt2);
	print_point(pt3);
	
	rt = make_rect(pt1, pt2);
	rt2 = shift_rect(rt, 10, 10);
	print_rect(rt2);

	/*
	crt = make_color_rect(pt1, pt2, 55);
	crt = shift_color_rect(crt, 10, 10);
	print_color_rect(crt);
	***/
	return 0;
}
