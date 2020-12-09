#include "ft_printf.h"

void write_flag_p(int size)
{
    while (size > 0)
    {
        ft_putchar(' ');
        size--;
    }
}
void output_pointer_flag(unsigned int ptr, int width, int precision, char flag)
{
    int length;

    length = ft_strlen(ft_itoa(ptr, "0123456789abcdef"));
    width = width > length ? (width - precision - length - 2) : 0;
    if (flag == ' ' || flag == '0')
    {
        write_flag_p(width);
        ft_putstr("0x");
        while ((precision - length) > 0)
        {
            ft_putchar('0');
            precision--;
        }
        ft_putstr(ft_itoa(ptr, "0123456789abcdef"));
    }
    if (flag == '-')
    {
        ft_putstr("0x");
        ft_putstr(ft_itoa(ptr, "0123456789abcdef"));
        write_flag_p(width);
    }
}
void output_p_specifier(va_list *parms_arry, format_parser *parser)
{
    int ptr;
    int width;
    int length;
    int precision;

    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    ptr = va_arg(*parms_arry, int);
    length = ft_strlen(ft_itoa(ptr, "0123456789abcdef"));
    precision = parser->precision < length || parser->precision == -1 ? 0 : parser->precision;

    if (ptr == 0)
        ft_putstr("(nil)");
    else
        output_pointer_flag(ptr, width, precision, parser->flag);
}
