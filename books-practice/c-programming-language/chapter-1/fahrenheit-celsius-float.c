#include <stdio.h>

// print Fahrenheit-Celsius table
// for fahr = 0, 20, ..., 300 floating-point version

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;                                  // lower limit of temperature table
    upper = 300;                                // upper limit
    step = 20;                                  // step size

    fahr = lower;
    
    printf("Fahrenheit\tCelsius\n"); // Exercise 1-3
    
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%5.0f %16.1f\n", fahr, celsius); // %3.0f floating-point number will be printed at least three characters wide with no decimal point and no franction digits
        fahr = fahr + step;                     // %6.1f will print with at least 6 characteres wide with 1 digi after the decimal point.
    }
}

// %d print as decimal integer
// %6d print as decimal integer, at least 6 characters wide
// %f print as floating point
// %6f print as floating point, at least 6 characters wide
// %.2f print as floating point, 2 characters after decimal point
// %6.2f print as floating point, at least 6 wide and 2 after decimal point