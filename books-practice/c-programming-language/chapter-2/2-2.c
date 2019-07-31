#include <stdio.h>

int main() {

    char s[10];

    char c;
    int i;

    for (i = 0; i < 10 - 1; i++) {
        c = getchar();

        if (c == EOF)
            break;

        if (c == '\n')
            break;

        s[i] = c;
    }

    printf("%s ", s);
    
    return 0;
}