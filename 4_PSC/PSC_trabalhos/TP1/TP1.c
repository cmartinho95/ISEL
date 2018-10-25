#include <stdio.h>

void string_right_rotate(char * s);

int main()
{
    char a[] = "xpto";
    printf("%s\n",a);
    string_right_rotate(a);
    printf("%s\n",a);
    return 0;
}

void string_right_rotate(char * s)
{
    int i = 0;
    int aux;
    for (i = 0; s[i] != '\0'; i++){
        aux = s[i];
        s[i] = s[0];
        s[0] = aux;
    }
}
