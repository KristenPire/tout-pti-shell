#include "option_csdi.h"

#include <stdio.h>

void handle_decimal(va_list *argp) // 'd'
{
  int int_to_print = va_arg(*argp, int);
  printf("%d", int_to_print);
  fflush(stdout);
}

void handle_string(va_list *argp) // 's'
{
  ft_putstr(va_arg(*argp, char *));
}

void handle_char(va_list *argp)
{
  char c;

  c = va_arg(*argp, int);
  write(1, &c, 1);
}
