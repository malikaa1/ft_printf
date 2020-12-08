#include "ft_printf.h"
int ft_sizeof_flag(int nb, int width, int precision)
{
    int sizeof_nb;
    int result;

    sizeof_nb = ft_strlen(ft_itoa(nb, "0123456789"));
    if (width >= sizeof_nb && precision < width)
    {
        if (precision == 0 || precision == -1 || precision < sizeof_nb)
            result = (nb == 0 && precision == 0) ? width : width - sizeof_nb;
        else if (precision >= sizeof_nb)
            result = nb < 0 ? (width - precision - 1) : (width - precision);
    }
    else if (width <= sizeof_nb && precision <= sizeof_nb)
        result = 0;
    else
        result = width - precision;

    return result;
}
void write_nb(int nb, int precision)
{
    int lenght_nb;

    lenght_nb = ft_strlen(ft_itoa(nb, "0123456789"));
    if (nb == 0 && precision == 0)
        return;
    if (nb < 0)
    {
        ft_putchar('-');
        lenght_nb--;
    }
    while (precision > lenght_nb)
    {
        ft_putchar('0');
        precision--;
    }
    ft_putnbr(nb);
}
void write_flag(int nb, int width, char flag, int precision)
{
    int sizeof_flag;
    char output_char;

    sizeof_flag = ft_sizeof_flag(nb, width, precision);
    if (flag == '-' || flag == ' ' || (flag == '0' && precision >= 0))
        output_char = ' ';
    if (flag == '0' && precision == -1)
        output_char = '0';
    while (sizeof_flag > 0)
    {
        ft_putchar(output_char);
        sizeof_flag--;
    }
}
void output_int_flag(int nb, int width, int precision, char flag)
{
    if (flag == '-')
        write_nb(nb, precision);
    write_flag(nb, width, flag, precision);
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
