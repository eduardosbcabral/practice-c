#include <stdio.h>

int main()
{
    int c;

    printf("%d", EOF); // Exercise 1-7

    while((c = getchar()) != EOF) {       // EOF: end of file constant (-1) - CTRL+Z represents it
        putchar(c);         // print char
    }
}