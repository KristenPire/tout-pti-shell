#include "ft_printf.h"

#include <stdio.h>

char *handle_integer(va_list *argp)
{
  int int_to_print = va_arg(*argp, int);

  printf("%d", int_to_print);
  return ("3");
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

int ft_printf(const char *str, ...)
{
  va_list argp;
  int parameter;

  va_start(argp, str);
  while (*str != '\0') // s
    {
      parameter = check_parameter(*str);
      if (parameter == 1)
        {
          str++;
          char *result = switch_parameter(*str, &argp);
          printf("%s", result);
        }
      if (parameter == 2)
        str += 2;
      else
        str++;
    }

  va_end(argp);
  return (0);
}
