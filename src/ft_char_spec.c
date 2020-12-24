#include "ft_printf.h"
int ft_print_c_speci(char flag, char c, int width)
{
    int i;
    int count;

    count = 0;
    i = width - 1;
    if (flag == '-' || (flag == ' ' && width == 0))
        count += write_char(c);
    while (i > 0)
    {
        count += write_char(' ');
        i--;
    }
    if (flag == ' ' && width != 0)
        count += write_char(c);
    return (count);
}
int output_c_specifier(va_list *parms_arry, format_parser *parser)
{
    char c;
    int width;

    if (parser->is_dynamic_wdith == 1)
    {
        width = va_arg(*parms_arry, int);
        if (width < 0)
        {
            width = width * -1;
            parser->flag = '-';
        }
    }
    else
        width = parser->width;
    c = va_arg(*parms_arry, int);
    return (ft_print_c_speci(parser->flag, c, width));
}