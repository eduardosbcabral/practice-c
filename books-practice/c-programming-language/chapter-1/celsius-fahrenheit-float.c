#include <stdio.h>

// print Celsius-Fahrenheit table - Exercise 1-4
// for fahr = 0, 20, ..., 300 floating-point version

// #define is a symbolic constant, not variables
#define LOWER   -17
#define UPPER   100
#define STEP    1

int main()
{
    float fahr, celsius;

    printf("Celsius\tFahrenheit\n"); // Exercise 1-3
    
    for(celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP) {
        printf("%3.0f %6.1f\n", celsius, (celsius * 9/5) + 32);
    }
}

// %d print as decimal integer
// %6d print as decimal integer, at least 6 characters wide
// %f print as floating point
// %6f print as floating point, at least 6 characters wide
// %.2f print as floating point, 2 characters after decimal point
// %6.2f print as floating point, at least 6 wide and 2 after decimal point