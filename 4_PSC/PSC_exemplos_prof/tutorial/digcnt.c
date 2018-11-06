//
//  digcnt.c
//  
//
//  Created by Carlos Martins on 02/10/14.
//
//

#include <stdio.h>
#include <assert.h>

/* count digits, white space, others */

int main()
{
    int c, i, nwhite, nother, nc, ncc;
    int ndigit[10];
    
    nwhite = nother = nc = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }
    ncc = nother + nwhite;
    printf("digits = ");
    for (i = 0; i < 10; ++i)
    	printf(" %d", (ncc += ndigit[i], ndigit[i]));
    printf("\nwhite space = %d, other = %d, all = %d, allc: %d\n", nwhite, nother, nc, ncc);
    return 0;
}
