#include "ft_printf.h"


void ft_writeD(int d)
{
    char *str;
    //int   i;

    str = ft_itoa(d);
    /* while (str[i])
    {
        write(1, str[i], 1);
        i++;
    }

    */
}
void    ft_writeS(char *str)
{
    //ft_putstr(str);
}
void switch_parameter(const char c, const char *str) //varg peut etre un int nn ? pourquoi pas use un size_t?
{
    int i;

    i = 0;
    if (c = 'd')
        ft_writeD(str);
    if (c = 's')
        ft_writeS(str);

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
            i++; /* pq pas write direct ? genre imaginons le bail cest "salut %s !", il ecrit "salut" et des quil voit un %
            il fait la passe a un autre truc qui va ecrire le % puis on i+2 et go ecrire " !"
    }
}