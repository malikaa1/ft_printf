#include "ft_printf.h"
void write_nb(int nb, int precision)
{
    int lenght_nb;

    if (nb < 0)
        nb = nb * -1;
    lenght_nb = ft_strlen(ft_itoa(nb, "0123456789"));
    while (precision > lenght_nb)
    {
        ft_putchar('0');
        precision--;
    }
    ft_putnbr(nb);
}
void output_int_flag(int nb, int width, int precision, char flag)
{
    char output_char;
    int length;

    length = precision > ft_strlen(ft_itoa(nb, "0123456789")) ? width - precision : width - ft_strlen(ft_itoa(nb, "0123456789"));
    if (nb < 0 && precision > ft_strlen(ft_itoa(nb, "0123456789")))
        length--;
    if (flag == '-' || flag == ' ')
        output_char = ' ';
    if (flag == '0' && precision <= ft_strlen(ft_itoa(nb, "0123456789")))
        output_char = '0';
     if (flag == '0' && precision > ft_strlen(ft_itoa(nb, "0123456789")))
        output_char = ' ';
    if (nb < 0 && (flag == '-' || flag == '0'))
        ft_putchar('-');
    if (flag == '-')
        write_nb(nb, precision);
    while (length > 0)
    {
        ft_putchar(output_char);
        length--; 
    }
    if (nb < 0 && flag == ' ')
        ft_putchar('-');
    if (flag == '0' || flag == ' ')
        write_nb(nb, precision);
}
void output_d_specifier(va_list *parms_arry, format_parser *parser)
{
    int d;
    int width;
    int precision;

    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;
    d = va_arg(*parms_arry, int);
    output_int_flag(d, width, precision, parser->flag);
}
void output_u_specifier(va_list *parms_arry, format_parser *parser)
{
    int un_int;
    int precision;
    int width;

    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;
    un_int = va_arg(*parms_arry, int);
    if (un_int < 0)
        return;
    output_int_flag(un_int, width, precision, parser->flag);
}
