#include <stdio.h>

// standard headers containing symbolic constants for types sizes
#include <limits.h>
#include <float.h>

int main() {

    // Char ranges
    printf("Min size signed char: %d\n", CHAR_MIN);
    printf("Max size signed char: %d\n", CHAR_MAX);

    printf("Min size unsigned char: %d\n", 0); // 0 = always the minimum size of unsigned variables
    printf("Max size unsigned char: %d\n", UCHAR_MAX);

    // Short ranges
    printf("Min size signed short: %d\n", SHRT_MIN);
    printf("Max size signed short: %d\n", SHRT_MAX);

    printf("Min size unsigned short: %d\n", 0); // 0 = always the minimum size of unsigned variables
    printf("Max size unsigned short: %d\n", USHRT_MAX);
    
    // Integer ranges
    printf("Min size signed integer: %d\n", INT_MIN);
    printf("Max size signed integer: %d\n", INT_MAX);

    printf("Min size unsigned integer: %d\n", 0); // 0 = always the minimum size of unsigned variables
    printf("Max size unsigned integer: %u\n", UINT_MAX); // u = unsigned int decimal number

    // Long ranges
    printf("Min size signed long: %d\n", LONG_MIN);
    printf("Max size signed long: %d\n", LONG_MAX);

    printf("Min size unsigned long: %d\n", 0); // 0 = always the minimum size of unsigned variables
    printf("Max size unsigned long: %u\n", ULONG_MAX);

    // Floating precision types does not have unsigned
    // Float ranges
    printf("Min size signed float: %E\n", FLT_MIN);
    printf("Max size signed float: %E\n", FLT_MAX);

    // Double ranges
    printf("Min size signed double: %E\n", DBL_MIN);
    printf("Max size signed double: %E\n", DBL_MAX);

}