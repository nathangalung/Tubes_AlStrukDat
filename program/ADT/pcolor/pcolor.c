#include <stdio.h>
#include "pcolor.h"

char *c[500];

void print_red(char *c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        printf("%s%c", RED, c[i]);
        i++;
    }
    printf("%s", NORMAL);
}

void print_green(char *c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        printf("%s%c", GREEN, c[i]);
        i++;
    }
    printf("%s", NORMAL);
}

void print_yellow(char *c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        printf("%s%c", YELLOW, c[i]);
        i++;
    }
    printf("%s", NORMAL);
}