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
void write_nb(int nb, int precision, char flag)
{
    int lenght_nb;

    lenght_nb = ft_strlen(ft_itoa(nb, "0123456789"));
    if (nb < 0 && precision > lenght_nb && flag == '0')
        lenght_nb = lenght_nb - 1;
    if (nb == 0 && precision == 0)
        return;
    if (nb < 0 && (flag == ' ' || flag == '-'))
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
    if (nb < 0)
    {
        if (output_char == '0' && flag != ' ' && flag != '-')
            ft_putchar('-');
    }
    while (sizeof_flag > 0)
    {
        ft_putchar(output_char);
        sizeof_flag--;
    }
    if (nb < 0)
    {
        if (output_char == ' ' && flag != ' ' && flag != '-')
            ft_putchar('-');
    }
}
void output_int_flag(int nb, int width, int precision, char flag)
{
    if (flag == '-')
        write_nb(nb, precision, flag);
    write_flag(nb, width, flag, precision);
    if (flag == '0' || flag == ' ')
        write_nb(nb, precision, flag);
}

void output_d_specifier(va_list *parms_arry, format_parser *parser)
{
    int d;
    int width;
    int precision;
    //char *result;

    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;
    d = va_arg(*parms_arry, int);
     if (width < -1)
    {
        width = width * -1;
        parser->flag = '-';
    }
    output_int_flag(d, width, precision, parser->flag);
}
