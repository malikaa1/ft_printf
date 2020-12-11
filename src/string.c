#include "ft_printf.h"

void write_str(char *str, int precision)
{
    int i = 0;
    if (ft_strcmp(str, "(null)") == 0 && precision < 6 && precision != -1)
        return;
    precision = precision == -1 || precision > ft_strlen(str) ? ft_strlen(str) : precision;
    while (str[i] != '\0' && i < precision)
    {
        ft_putchar(str[i]);
        i++;
    }
}
void write_flags(char c, char *str, int width, int precision)
{
    int size;
    int length;
    if (width == -1)
        return;
    length = ft_strlen(str);
    precision = precision > width ? width : precision;
    if (precision >= length && width > precision)
    {
        //precision = 0;
        size = width - length;
    }
    else if (ft_strcmp(str, "(null)") == 0 && precision > 0 && width >= 6 )
       size = width;
    else if (ft_strcmp(str, "(null)") == 0 && precision > 0 && width < 6 && width > precision )
       size = width;
    else if (precision == -1)
        size = width - length;
    
    else if (width > precision && length < width)
        size = width - precision;
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

void output_s_flags(format_parser *parser, char *str, int precision, int width)
{
    if (parser->flag == '-')
    {
        write_str(str, precision);
        write_flags(' ', str, width, precision);
    }
    else if (parser->flag == '0')
    {
        write_flags(' ', str, width, precision);
        write_str(str, precision);
    }
    else if (parser->flag == ' ')
    {
        write_flags(' ', str, width, precision);
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
    arg = arg == NULL ? "(null)" : arg;

    output_s_flags(parser, arg, precision, width);
}
