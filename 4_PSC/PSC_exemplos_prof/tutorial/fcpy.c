//
//  fcpy.c
//  
//
//  Created by Carlos Martins on 25/09/14.
//
//

#include <stdio.h>

#if 0
int main()
{
    int c;
    
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    return 0;
}
#endif

int main()
{
    int c;
//    printf("%d\n", EOF);
    while ((c = getchar()) != EOF)
        putchar(c);
    return 0;
}
