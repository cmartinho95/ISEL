#include <stdio.h>

// the structure
struct packed_date {
	unsigned int day : 5;				/* 1..31 */
	unsigned int month : 4;				/* 1..12 */
	unsigned int year : 23;				/* 0 .. 2^23 - 1 */
};

// using a typedef
typedef struct packed_date PackedDate;

void print_date(struct packed_date date)
{
	static const char *month_names[] = {
		"Unknown", "January", "February", "March", "April", "May", "June", "July",
		"August", "September", "October", "November", "December" };
		
	printf("%d %s, %d\n",
		 	date.day,
		    (date.month >= 1 && date.month <= 12) ? month_names[date.month] : month_names[0],
			date.year);
}

int main()
{
	struct packed_date now = {.day = 3, .month = 4, .year = 2017 };
	
	print_date(now);
	return 0;
}



