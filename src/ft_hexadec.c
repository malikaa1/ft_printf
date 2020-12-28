#include "ft_printf.h"

int write_str_x(char *str, int precision)
{
    int size;
    int count;

    count = 0;
    if (ft_strcmp(str, "(null)") == 0 && precision < 6 && precision != -1)
        return 0;
    if (precision == 0)
        return 0;
    if (precision > ft_strlen(str))
    {
        size = precision - ft_strlen(str);
        while (size > 0)
        {
            count += write_char('0');
            size--;
        }
    }
    count += write_string(str);
    return (count);
}

int write_flag_x(char flag, char *str, int width, int precision)
{
    int size;
    int length;
    int count;

    count = 0;
    if (width == -1)
        return 0;
    length = ft_strlen(str);
    flag = flag == '0' && precision >= 0 ? ' ' : flag;
    precision = precision > width ? width : precision;
    if ((precision >= length && width > precision) || width == precision)
        size = width - precision;
    else if ((precision == 0 && width > precision) || width < precision)
        size = width;
    else if (precision == -1 || (width > precision && length >= precision))
        size = width - length;
    while (size > 0)
    {
        count += write_char(flag);
        size--;
    }
    return (count);
}

int output_x_flags(format_parser *parser, char *str, int precision, int width)
{
    int count;

    count = 0;
    if (parser->flag == '-')
    {
        count += write_str_x(str, precision);
        count += write_flag_x(' ', str, width, precision);
    }
    else if (parser->flag == '0')
    {
        count += write_flag_x('0', str, width, precision);
        count += write_str_x(str, precision);
    }
    else if (parser->flag == ' ')
    {
        count += write_flag_x(' ', str, width, precision);
        count += write_str_x(str, precision);
    }
    return (count);
}

int output_x_specifier(va_list *parms_arry, format_parser *parser, char *base)
{
    char *arg_x;
    int precision;
    int width;
    unsigned int int_hexa_upp;

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
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;
    int_hexa_upp = va_arg(*parms_arry, unsigned int);
    arg_x = ft_itoa(int_hexa_upp, base);
    if (int_hexa_upp > 0 && precision == 0)
        precision = ft_strlen(arg_x);
    return (output_x_flags(parser, arg_x, precision, width));
}

int output_x_low_specifier(va_list *parms_arry, format_parser *parser)
{
    return output_x_specifier(parms_arry, parser, "0123456789abcdef");
}

int output_x_upp_specifier(va_list *parms_arry, format_parser *parser)
{
    return output_x_specifier(parms_arry, parser, "0123456789ABCDEF");
}
