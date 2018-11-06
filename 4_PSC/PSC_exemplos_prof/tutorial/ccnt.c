//
//  ccnt.c
//  
//
//  Created by Carlos Martins on 25/09/14.
//
//

#include <stdio.h>

#if 1
int main()
{
    long nc = 0;
    
    while (getchar() != EOF)
        ++nc;
    printf("\n%ld\n", nc);
    return 0;
}
#endif
#if 0
int main()
{
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("\n%.0f\n", nc);
    return 0;
}
#endif

