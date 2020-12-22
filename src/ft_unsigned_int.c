#include "ft_printf.h"
int ft_sizeof_flag_u(unsigned long nb, int width, int precision)
{
    int sizeof_nb;
    int result;

    sizeof_nb = ft_strlen(ft_itoa(nb, "0123456789"));
    if (width >= sizeof_nb && precision < width)
    {
        if (precision == 0 || precision == -1 || precision < sizeof_nb)
            result = (nb == 0 && precision == 0) ? width : width - sizeof_nb;
        else if (precision >= sizeof_nb)
            result = (width - precision);
    }
    else if (width <= sizeof_nb && precision <= sizeof_nb)
        result = 0;
    else
        result = width - precision;

    return (result);
}

int write_nb_u(long long nb, int precision)
{
    int lenght_nb;
    int count;

    count = 0;
    lenght_nb = ft_strlen(ft_itoa(nb, "0123456789"));
    if (nb == 0 && precision == 0)
        return 0;
    while (precision > lenght_nb)
    {
        count += write_char('0');
        precision--;
    }
    count += write_number(nb);
    return (count);
}

int write_flag_u(unsigned long nb, int width, char flag, int precision)
{
    int sizeof_flag;
    char output_char;
    int count;

    count = 0;
    if (width == -1)
        return 0;
    sizeof_flag = ft_sizeof_flag_u(nb, width, precision);
    if (flag == '-' || flag == ' ' || (flag == '0' && precision >= 0))
        output_char = ' ';
    if (flag == '0' && precision == -1)
        output_char = '0';
    while (sizeof_flag > 0)
    {
        count += write_char(output_char);
        sizeof_flag--;
    }
    return (count);
}
int output_u_flag(unsigned long nb, int width, int precision, char flag)
{
    int count;

    count = 0;
    if (flag == '-')
        count += write_nb_u(nb, precision);
    count += write_flag_u(nb, width, flag, precision);
    if (flag == '0' || flag == ' ')
        count += write_nb_u(nb, precision);
    return (count);
}
int output_u_specifier(va_list *parms_arry, format_parser *parser)
{
    long long un_int;
    int precision;
    int width;
    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    precision = parser->is_dynamic_precision == 1 ? va_arg(*parms_arry, int) : parser->precision;
    un_int = va_arg(*parms_arry, unsigned long);
    if (width < -1)
    {
        width = width * -1;
        parser->flag = '-';
    }
    return (output_u_flag(un_int, width, precision, parser->flag));
}