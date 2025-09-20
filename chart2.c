#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int fahrenheit;
    double celsius;
    int lowerlimit = 0;
    int upperlimit = 300;
    int step = 20;

    printf("Fahrenheit-Celsius \n");
    for (fahrenheit = lowerlimit; fahrenheit <= upperlimit; fahrenheit += step) {
        celsius = 5.0 * (fahrenheit - 32) / 9.0;  // floating-point math
        printf("%5d%10.1f\n", fahrenheit, celsius);
    }
    return 0;
}
