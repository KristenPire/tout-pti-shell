#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "wordtab.h"
#include "helper.h"
#include "option_csdi.h"

int ft_printf(const char *, ...);

typedef void(*functionPtr)(va_list *);

typedef struct s_Map
{
  char key;
  functionPtr func;
} t_Map;

#endif /* FT_PRINTF_H */
