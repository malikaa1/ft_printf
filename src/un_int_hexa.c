#include "ft_printf.h"
void write_str_x(char *str, int precision)
{
    int size;
    if (ft_strcmp(str, "(null)") == 0 && precision < 6 && precision != -1)
        return;
    if (precision == 0)
        return;
    //precision = precision == -1 || precision > ft_strlen(str) ? ft_strlen(str) : precision;
    if (precision > ft_strlen(str))
    {
        size = precision - ft_strlen(str);

        while (size > 0)
        {
            ft_putchar('0');
            size--;
        }
    }
    ft_putstr(str);
}
void write_flag_x(char c, char *str, int width, int precision)
{
    int size;
    int length;

    if (width == -1)
        return;
    length = ft_strlen(str);
    c = c == '0' && precision > 0 ? ' ' : c;
    precision = precision > width ? width : precision;
    if (precision >= length && width > precision)
        size = width - precision;
    else if (precision == 0 && width > precision)
        size = width;
    else if (precision == -1)
        size = width - length;
    else if (width > precision && length >= precision)
        size = width - length;
    else if (width > precision)
        size = width - precision;
    else if (width == precision)
        size = width - length;
    else if (width < precision)
        size = width;
    while (size > 0)
    {
        ft_putchar(c);
        size--;
    }
}

void output_x_flags(format_parser *parser, char *str, int precision, int width)
{
    if (parser->flag == '-')
    {
        write_str_x(str, precision);
        write_flag_x(' ', str, width, precision);
    }
    else if (parser->flag == '0')
    {
        write_flag_x('0', str, width, precision);
        write_str_x(str, precision);
    }
    else if (parser->flag == ' ')
    {
        write_flag_x(' ', str, width, precision);
        write_str_x(str, precision);
    }
}
void output_x_specifier(va_list *parms_arry, format_parser *parser)
{
    char *arg_x;
    int precision;
    int width;
    unsigned int int_hexa_upp;

    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;
    int_hexa_upp = va_arg(*parms_arry, unsigned int);
    arg_x = ft_itoa(int_hexa_upp, "0123456789abcdef");
    output_x_flags(parser, arg_x, precision, width);
}

void output_X_specifier(va_list *parms_arry, format_parser *parser)
{
    char *arg_x;
    int precision;
    int width;
    unsigned int int_hexa_upp;

    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;
    int_hexa_upp = va_arg(*parms_arry, unsigned int);
    arg_x = ft_itoa(int_hexa_upp, "0123456789ABCDEF");
    output_x_flags(parser, arg_x, precision, width);
}
