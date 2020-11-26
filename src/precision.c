#include "ft_printf.h"
void output_precision(char *str, int size, int width)
{
    int i;

    i = 0;
    if (width < size)
    {
        while (width > i)
        {
            ft_putchar(str[i]);
            i++;
        }
    }
    else
        ft_putstr(str);
}

void output_int_precision(int i, int size, int width)
{
    int j;

    
    if (width > size)
    {
        j = width - size;
        while (j > 0)
        {
            ft_putchar('0');
            j--;
        }
        ft_putnbr(i);
    }
    else
        ft_putnbr(i);
}
void output_d_precision(va_list *parms_arry, format_parser *parser)
{
    int i;
    int size;

    if (parser->is_dynamic_precision == 0)
    {
        i = va_arg(*parms_arry, int);
        size = ft_strlen(ft_itoa(i, "0123456789"));
        output_int_precision(i, size, parser->precision);
    }
    if (parser->is_dynamic_precision == 1)
    {
        parser->precision = va_arg(*parms_arry, int);
        i = va_arg(*parms_arry, int);
        size = ft_strlen(ft_itoa(i, "0123456789"));
        output_int_precision(i, size, parser->precision);
    }
}

// void output_s_precision(va_list *parms_arry, format_parser *parser)
// {
//     char *arg;
//     int size;

//     if (parser->is_dynamic_precision == 0)
//     {
//         arg = va_arg(*parms_arry, char *);
//         size = ft_strlen(arg);
//         output_precision(arg, size, parser->precision);
//     }
//     else if (parser->is_dynamic_precision == 1)
//     {
//         parser->precision = va_arg(*parms_arry, int);
//         arg = va_arg(*parms_arry, char *);
//         size = ft_strlen(arg);
//         output_precision(arg, size, parser->precision);
//     }
// }