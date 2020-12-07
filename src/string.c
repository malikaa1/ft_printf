#include "ft_printf.h"

void write_str(char *str, int precision)
{
    int i = 0;
    if (str == NULL)
    {
        if (precision < 6 && precision != 0)
            return;
        str = "(null)";
        precision = precision > 0 ? precision : 6;
    }
    precision = precision > ft_strlen(str) || precision <= 0 ? ft_strlen(str) : precision;
    while (str[i] != '\0' && i < precision)
    {
        ft_putchar(str[i]);
        i++;
    }
}
void write_flags(char c, int width, int length, int precision)
{
    int size;

    if (width <= (length - precision))
        return;
    if (length > precision)
        size = width - precision;
    else
        size = width - length;
    if (width > length && precision == 0)
        size = size - length;
    while (size > 0)
    {
        ft_putchar(c);
        size--;
    }
}

void output_s_flags(format_parser *parser, char *str, int precision, int width)
{
    int length;

    length = str == NULL ? 6 : ft_strlen(str);
    if (parser->flag == '-')
    {
        write_str(str, precision);
        write_flags(' ', width, length, precision);
    }
    else if (parser->flag == '0')
    {
        write_flags('0', width, length, precision);
        write_str(str, precision);
    }
    else if (parser->flag == ' ')
    {
        write_flags(' ', width, length, precision);
        write_str(str, precision);
    }
}

void output_s_specifier(va_list *parms_arry, format_parser *parser)
{
    char *arg;
    int precision;
    int width;

    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;

    arg = va_arg(*parms_arry, char *);

    // if (precision > ft_strlen(arg) || precision <= 0)
    //     precision = ft_strlen(arg);

    output_s_flags(parser, arg, precision, width);
}
