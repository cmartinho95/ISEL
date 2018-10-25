#include <stdio.h>

int main()
{
    int c, charcount = 0, linecount = 0;

    while((c = getchar()) != EOF){
        ++charcount;
        /*if (c == '\n'){ ++linecount;}*/
    }
    printf("Number of chars in file: %i\nNumber of lines in file: %d\n", charcount, linecount);
    return 0;
}
/*
./count -- comeca-se a escrever e qd CTRL+D termina o ciclo
./count <ola.rtf -- conta chars e linhas do ficheiro e apresenta resultados
*/
