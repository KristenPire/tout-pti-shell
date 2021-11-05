#include "option_csdi.h"

// For the temporary handle_integer
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//TEMP : Need my_put_nbr;
#define ENOUGH ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)
char *handle_decimal(va_list *argp) // 'd'
{
  char *str;
  int int_to_print = va_arg(*argp, int);

  str = malloc(ENOUGH * sizeof(int));
  sprintf(str, "%d", int_to_print);
  return (str);
}

char *handle_string(va_list *argp) // 's'
{
  return (va_arg(*argp, char *));
}
