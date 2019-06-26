#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int maximumLength;      // maximum length seen so far
char line[MAXLINE];     // current input line
char longest[MAXLINE];  // longest line saved here

int getLine(void);
void copy(void);

// print longest input line

int main()
{
    int lineLength;         // current line length
    extern int maximumLength;
    extern char longest[];

    maximumLength = 0;

    while ((lineLength = getLine()) > 0) {
        if (lineLength > maximumLength) {
            maximumLength = lineLength;
            copy();
        }

    }

    if (maximumLength > 0) {    // there was a line
        printf("%s", longest);
    }

    return 0;
}

// getLine: read a line into s, return length
int getLine(void) 
{
    
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

// copy: copy 'from' into 'to'; assume to is big enough
void copy(void) 
{
    int i;
    extern char line[], longest[];

    i = 0;

    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}