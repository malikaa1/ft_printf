#include "ft_printf.h"

void output_int_flag(int nb, int width, int length, char flag)
{
    char output_char;
    int j;

    // if (width < length)
    //     return;
    if (flag == '-' || flag == ' ')
        output_char = ' ';
    if (flag == '0')
        output_char = '0';

    j = width - length;
    if (flag == '-')
        ft_putnbr(nb);
    while (j > 0)
    {
        ft_putchar(output_char);
        j--;
    }
    if (flag == '0' || flag == ' ')
        ft_putnbr(nb);
}
void output_d_specifier(va_list *parms_arry, format_parser *parser)
{
    int d;
    int length;
    int width;

    if (parser->is_dynamic_wdith == 0)
    {
        d = va_arg(*parms_arry, int);
        width = parser->width;
    }
    else if (parser->is_dynamic_wdith == 1)
    {
        width = va_arg(*parms_arry, int);
        d = va_arg(*parms_arry, int);
    }
    length = ft_strlen(ft_itoa(d, "0123456789"));
    output_int_flag(d, width, length, parser->flag);
}
void output_u_specifier(va_list *parms_arry, format_parser *parser)
{
    int unsigned_int;
    int length;
    int width;
    if (parser->is_dynamic_wdith == 0)
    {
        width = parser->width;
        unsigned_int = va_arg(*parms_arry, unsigned int);
    }
    if (parser->is_dynamic_wdith == 1)
    {
        width = va_arg(*parms_arry, unsigned int);
        unsigned_int = va_arg(*parms_arry, unsigned int);
    }
    length = ft_strlen(ft_itoa(unsigned_int, "0123456789"));
    output_int_flag(unsigned_int, width, length, parser->flag);
}
