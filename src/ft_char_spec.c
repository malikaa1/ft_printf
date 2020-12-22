#include "ft_printf.h"

int output_c_specifier(va_list *parms_arry, format_parser *parser)
{
    char c;
    int width;
    int i;
    int count;

    count = 0;
    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    ;
    c = va_arg(*parms_arry, int);
    if (width < -1)
    {
        width = width * -1;
        parser->flag = '-';
    }
    i = width - 1;
    if (parser->flag == '-' || (parser->flag == ' ' && parser->width == 0))
        count += write_char(c);
    while (i > 0)
    {
        count += write_char(' ');
        i--;
    }
    if (parser->flag == ' ' && parser->width != 0)
        count += write_char(c);
    return count;
}
