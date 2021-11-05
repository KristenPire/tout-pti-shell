#include "helper.h"

int ft_strlen(const char *str)
{
  int i;

  i = 0;
  while(str[i++]);
  return (i);
}

int ft_putstr(char *str)
{
  return write(1, str, ft_strlen(str));
}

void print_wordtab(char **wordtab)
{
  int i;

  i = 0;
  while(wordtab[i])
    {
      ft_putstr(wordtab[i]);
      i++;
    }
}

void fill_buffer(char *buffer, char c, int size)
{
  int i;

  i = 0;
  while(i < size)
    buffer[i++] = c;
  return;
}
