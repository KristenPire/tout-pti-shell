#include "ft_printf.h"

void switch_parameter(const char c, va_list *argp)
{
  t_Map *ptr;
  t_Map switchMap[] = {
    {'d', handle_decimal},
    {'s', handle_string},
    {'c', handle_char}
  };

  ptr = switchMap;
  while (ptr)
    {
      if (ptr->key == c)
        {
          ptr->func(argp);
          return;
        }
      ptr++;
    }
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

void build_string(const char *str, va_list *argp)
{
  int parameter;
  int word_counter;

  word_counter = 0;
  while (*str != '\0')
    {
      parameter = check_parameter(*str);
      if (parameter == 1) // '%'
        {
          switch_parameter(*(++str), argp);
          str++;
        }
      if (parameter == 2) // '\'
          str += 2;
      else // anything else
        write(1, str++, 1);
    }
}

int ft_printf(const char *str, ...)
{
  va_list argp;

  va_start(argp, str);
  build_string(str, &argp);
  va_end(argp);
  return (0);
}
