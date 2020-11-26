#include "ft_printf.h"

// %[flags][width][.precision][length]specifier

void write_str(char *str, int size)
{
    int i = 0;
    while (str[i] != '\0' && i < size)
    {
        ft_putchar(str[i]);
        i++;
    }
}
void write_char(char c, int width, int lenght, int precision)
{
    int size;

    if (lenght > precision)
        size = width - precision;
    else
        size = width - lenght;
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
        write_char(' ', width, ft_strlen(str), precision);
    }
    else if (parser->flag == '0')
    {
        write_char('0', width, ft_strlen(str), precision);
        write_str(str, precision);
    }
    else if (parser->flag == ' ')
    {
        write_char(' ', width, ft_strlen(str), precision);
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

    if (precision > ft_strlen(arg) || precision <= 0)
        precision = ft_strlen(arg);

    output_s_flags(parser, arg, precision, width);
}

void output_x_specifier(va_list *parms_arry, format_parser *parser)
{
    int int_x;
    int lenght;
    int width;
    char *str;

    if (parser->is_dynamic_wdith == 0)
    {
        width = parser->width;
        int_x = va_arg(*parms_arry, unsigned int);
    }
    else if (parser->is_dynamic_wdith == 1)
    {
        width = va_arg(*parms_arry, unsigned int);
        int_x = va_arg(*parms_arry, unsigned int);
    }
    str = ft_itoa(int_x, "0123456789abcdef");
    lenght = ft_strlen(str);
    output_char_flag(str, width, lenght, parser->flag);
}
void output_X_specifier(va_list *parms_arry, format_parser *parser)
{
    int int_X;
    int lenght;
    int width;
    char *str;

    if (parser->is_dynamic_wdith == 0)
    {
        width = parser->width;
        int_X = va_arg(*parms_arry, unsigned int);
    }
    else if (parser->is_dynamic_wdith == 1)
    {
        width = va_arg(*parms_arry, unsigned int);
        int_X = va_arg(*parms_arry, unsigned int);
    }
    str = ft_itoa(int_X, "0123456789ABCDEF");
    lenght = ft_strlen(str);
    output_char_flag(str, width, lenght, parser->flag);
}

// void output_s_specifier(va_list *parms_arry, format_parser *parser)
// {
//     char *arg;
//     int length;

//     if (parser->is_dynamic_precision == 0)
//     {
//         arg = va_arg(*parms_arry, char *);
//         length = ft_strlen(arg);
//     }
//     else if (parser->is_dynamic_precision == 1)
//     {
//         length = va_arg(*parms_arry, int);
//         arg = va_arg(*parms_arry, char *);
//     }

//     output_precision(arg, length, parser->precision);
//     output_char_flag(arg, parser->width, length, parser->flag);
// }