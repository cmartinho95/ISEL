#include <stdio.h>

typedef struct weather {
    float temperature;
    float wind;
    float humidity;
};

void weather_average(struct weather *average, const struct weather weathers[], size_t nweathers);
void string_right_rotate(char * s);

int main()
{
    /*char a[] = "xpto";
    printf("%s\n",a);
    string_right_rotate(a);
    printf("%s\n",a);
    return 0;*/


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

void weather_average(struct weather *average, const struct weather weathers[], size_t nweathers){
    int i = 0;
    float tempav = 0;
    float windav = 0;
    float humidav = 0;

    for(i = 0; i < nweathers; i++){
        tempav += weathers[i].temperature;
        windav += weathers[i].wind;
        humidav += weathers[i].humidity;
    }

    average->temperature = tempav / i;
    average->wind = windav / i;
    average->humidity = humidav / i;
}
