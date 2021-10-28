#include "ft_printf.h"

void switch_parameter(const char c, const char *str)
{

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


int ft_printf(const char* str, ...)
{
    int i;
    int parameter;

    while (str[i])
    {
        parameter = check_parameter(str[i]);
        if (parameter == 1)
        {
            switch_parameter(str[i+1], "varg");
            i += 2;
        }
        if (parameter == 2)
            i += 2;
        else
            i++;
    }


}