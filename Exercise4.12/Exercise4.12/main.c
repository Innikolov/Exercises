#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int itoa(int n, char s[]);


int main() {

    int i = -154;
    int n = 0;
    char s[10];
    itoa(i, s);

    printf("%s", s);
}


int itoa(int n, char s[])
{
    int i = 0;

    if (n / 10)
        i = itoa(n / 10, s);
    else if (n < 0)
        s[i++] = '-';

    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';

    return i;
}