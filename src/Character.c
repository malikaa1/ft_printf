#include "ft_printf.h"

void output_c_specifier(va_list *parms_arry, format_parser *parser)
{
    char c;
    int width;
    int i;

    width = parser->is_dynamic_wdith == 1? va_arg(*parms_arry, int) : parser->width;
    i = width - 1;
    c = va_arg(*parms_arry, int);
    if (parser->flag == '-' || (parser->flag == ' ' && parser->width == 0))
        ft_putchar(c);
    while (i > 0)
    {
        ft_putchar(' ');
        i--;
    }
    if (parser->flag == ' ' && parser->width != 0)
        ft_putchar(c);
}

