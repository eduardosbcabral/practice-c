#include <stdio.h>

int main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc) 
        ;   // Null statement
    
    printf("%.0f\n", nc);
}