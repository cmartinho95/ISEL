#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
#define NOME "Fahrenheit to Celcius"

int main()
{

    int fahr, celcius;
    /*int upper, lower, step;/*
    /*lower = 0;
    upper = 300;
    step = 20;*/
    fahr = lower;
    printf(NOME);
    while(fahr <= UPPER){
        celcius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celcius);
        fahr = fahr + STEP;
    }
    return 0;
}
