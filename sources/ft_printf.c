#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

//TEMP : Need my_put_nbr;
#define ENOUGH ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)

char *handle_integer(va_list *argp)
{
  char *str;
  int int_to_print = va_arg(*argp, int);

  str = malloc(ENOUGH * sizeof(int));
  sprintf(str, "%d", int_to_print);
  return (str);
}

char *handle_string(va_list *argp)
{
  return (va_arg(*argp, char *));
}

char *switch_parameter(const char c, va_list *argp)
{
  t_Map switchMap[] = {
    {'d', handle_integer},
    {'s', handle_string}
  };

  t_Map *ptr;
  ptr = switchMap;

  while (ptr)
    {
      if (ptr->key == c)
        return ptr->func(argp);
      ptr++;
    }
  return ("");
}

int check_parameter(const char c)
{
    if (c == '%')
        return(1);
    else if (c == '\\')
        return(2);
    else
        return (0);
}

void build_string(const char *str, va_list *argp, char **final_wordtab)
{
  int parameter;
  int word_counter;

  word_counter = 0;
  while (*str != '\0') // s
    {
      parameter = check_parameter(*str);
      if (parameter == 1) // '%'
          final_wordtab[word_counter++] = switch_parameter(*(++str), argp);
      if (parameter == 2) // '\'
        str += 2;
      else
        str++;
    }
}

int ft_printf(const char *str, ...)
{
  va_list argp;
  char **final_wordtab;

  final_wordtab = wordtab(str);
  va_start(argp, str);
  build_string(str, &argp, final_wordtab);
  print_wordtab(final_wordtab);
  va_end(argp);
  return (0);
}
