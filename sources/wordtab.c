#include "wordtab.h"

char    **wordtab(const char *str)
{
  char  **dst;
  int   i;
  int   j;

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
  dst = malloc(sizeof(char*) * j + 1);
  dst[j] = NULL;
  return (dst);
}
