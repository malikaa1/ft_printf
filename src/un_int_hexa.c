#include "ft_printf.h"
void write_str_x(char *str, int precision)
{
    while (precision > 0)
    {
        ft_putchar('0');
        precision--;
    }
    ft_putstr(str);
}
void output_x_flags(format_parser *parser, char *str, int precision, int width)
{
    if (width < 0)
        return;
    if (parser->flag == '-')
    {
        write_str_x(str, precision);
        write_flags(' ', str, ft_strlen(str), precision);
    }
    else if (parser->flag == '0')
    {
        write_flags('0', str, ft_strlen(str), precision);
        write_str_x(str, precision);
    }
    else if (parser->flag == ' ')
    {
        write_flags(' ', str, ft_strlen(str), precision);
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
    if (precision > ft_strlen(arg_x))
        precision = precision - ft_strlen(arg_x);
    else if (precision <= ft_strlen(arg_x) || precision < 0)
        precision = 0;
    output_x_flags(parser, arg_x, precision, width - precision);
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
    if (precision > ft_strlen(arg_x))
        precision = precision - ft_strlen(arg_x);
    else if (precision <= ft_strlen(arg_x) || precision < 0)
        precision = 0;
    output_x_flags(parser, arg_x, precision, width - precision);
}
