//#include "wordtab.h"
#include <stdio.h>
#include <stdlib.h>

char **wordtab(const char *str)
{
    int i;
    int j;
    char **dst;

    i = 0;
    j = 0;
    if (str[i] && str[i] != '%')
        j++;
    while (str[i])
    {
        if (str[i] == '%')
            j++;
        if (str[i] == '%' && str[i+2] && str[i+2] != '%')
            j++;
        i++;
    }
    printf("j = %d\n",j);
    dst = malloc(sizeof(char*) * j + 1);
    dst[j] = '\0';
    return (dst);
}

int main()
{
    char **lol;
    int     i;

    i = 5;
    lol = wordtab("salut %dl");
    printf("salut %%dl", i);
    return 0;
}