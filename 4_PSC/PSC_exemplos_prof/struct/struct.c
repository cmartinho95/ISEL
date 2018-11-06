#include <stdio.h>

struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

struct rect r1 = {{0, 0}, {100, 100}};

struct rect r2 = { .pt1 = {.x = 0, .y = 0}, .pt2 = {.x = 100, .y = 100} };

struct point make_point(int x, int y)
{
	struct point tmp;
	tmp.x = x;
	tmp.y = y;
	printf("{%d, %d}\n", tmp.x, tmp.y);
	return tmp;
}
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

#define min(a,b)	((a) < (b) ? (a) : (b))
#define max(a,b)	((a) > (b) ? (a) : (b))

struct rect canonrect(struct rect r)
{
	struct rect tmp;
	tmp.pt1.x = min(r.pt1.x, r.pt2.x);
	tmp.pt1.y = min(r.pt1.y, r.pt2.y);
	tmp.pt2.x = max(r.pt1.x, r.pt2.x);
	tmp.pt2.y = max(r.pt1.y, r.pt2.y);
	return tmp;
}

int main()
{
	struct rect r2 = {{0, 0}, {200, 200}};
	
	make_point(22, 44);
	printf("{{%d, %d}, {%d, %d}}\n", r2.pt1.x, r2.pt1.y, r2.pt2.x, r2.pt2.y);
	return 0;
}