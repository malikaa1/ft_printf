#include "ft_printf.h"

int write_str(char *str, int precision)
{
    int i;

    i = 0;
    if (ft_strcmp(str, "(null)") == 0 && precision < 6 && precision != -1)
        return 0;
    precision = precision == -1 || precision > ft_strlen(str) ? ft_strlen(str) : precision;
    while (str[i] != '\0' && i < precision)
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}

int ft_isnull(int precision, int width)
{
    int size;

    size = 0;
    if (precision == -1 || (precision >= 6) || (precision == width && width >= 6))
        size = width - 6;
    else if (precision > width && precision > 0 && width < 6 && precision < 6)
        size = width;
    else if (precision == 0 || (precision > 0 && precision < width) || width == precision)
        size = width;
    return (size);
}

int write_flags(char c, char *str, int width, int precision)
{
    int size = 0;
    int length;
    int count = 0;

    if (width == -1)
        return 0;
    if (ft_strcmp(str, "(null)") == 0)
        size = ft_isnull(precision, width);
    else
    {
        length = ft_strlen(str);
        precision = precision > width ? width : precision;
        if (precision >= length && width > precision)
            size = width - length;
        else if (precision == -1 || width == precision)
            size = width - length;
        else if ((width > precision && length < width) || width > precision)
            size = width - precision;
    }
    while (size > 0)
    {
        count += write_char(c);
        size--;
    }
    return (count);
}

int output_s_flags(format_parser *parser, char *str, int precision, int width)
{
    int count;

    count = 0;
    if (width < -1)
    {
        parser->flag = '-';
        width = width * -1;
    }
    if (parser->flag == '-')
    {
        count += write_str(str, precision);
        count += write_flags(' ', str, width, precision);
    }
    else if (parser->flag == '0')
    {
        count += write_flags(' ', str, width, precision);
        count += write_str(str, precision);
    }
    else if (parser->flag == ' ')
    {
        count += write_flags(' ', str, width, precision);
        count += write_str(str, precision);
    }
    return (count);
}

int output_s_specifier(va_list *parms_arry, format_parser *parser)
{
    char *arg;
    int precision;
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
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;
    arg = va_arg(*parms_arry, char *);
    arg = arg == NULL ? "(null)" : arg;
    precision = precision < -1 ? ft_strlen(arg) : precision;
    return (output_s_flags(parser, arg, precision, width));
}
