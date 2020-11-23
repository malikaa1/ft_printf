#include "ft_printf.h"
void output_char_flag(char *str, int width, int lenght, char flag)
{
    int i;

    i = width - lenght;
    if (flag == '-')
        ft_putstr(str);
    while (i > 0)
    {
        ft_putchar(' ');
        i--;
    }
    if (flag == ' ')
        ft_putstr(str);
}

void output_s_specifier(va_list *parms_arry, format_parser *parser)
{
    char *arg;
    int length;

    arg = va_arg(*parms_arry, char *);
    length = ft_strlen(arg);
    output_char_flag(arg, parser->width, length, parser->flag);
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
