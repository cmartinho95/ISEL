#include <stdio.h>

int main()
{
    int c;
    c = getchar();
    /*while(c != EOF){
        putchar(c);
        c = getchar();
    }*/
    while((c = getchar()) != EOF){
        putchar(c);
    }
    return 0;
}

/* codigo para correr de varias formas
./cpfile -- recebe input do teclado e imprime na consola a seguir
./cpfile <ola.rtf>copy.txt -- copia ola.rtf para copy.txt
./cpfile <ola.rtf -- copia ola.rtf para consola
*/
