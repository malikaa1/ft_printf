#include "ft_printf.h"

int write_flag_p(int size)
{
    int count;
    
    count = 0;
    while (size > 0)
    {
        ft_putchar(' ');
        count++;
        size--;
    }
    return count;
}
int output_pointer_flag(long long int ptr, int width, int precision, char flag)
{
    int length;
    int count;
    
    count = 0;
    length = ft_strlen(ft_itoa(ptr, "0123456789abcdef"));
    width = width > length ? (width - precision - length - 2) : 0;
    if (flag == ' ' || flag == '0')
    {
        count += write_flag_p(width);
        count += write_string("0x");
        while ((precision - length) > 0)
        {
            count += write_char('0');
            precision--;
        }
        count += write_string(ft_itoa(ptr, "0123456789abcdef"));
    }
    if (flag == '-')
    {
        count += write_string("0x");
        count += write_string(ft_itoa(ptr, "0123456789abcdef"));
        count += write_flag_p(width);
    }
    return count;
}
int output_p_specifier(va_list *parms_arry, format_parser *parser)
{
    long long int ptr;
    int width;
    int length;
    int precision;

    width = parser->is_dynamic_wdith == 1 ? va_arg(*parms_arry, int) : parser->width;
    ptr = va_arg(*parms_arry, long long int);
    length = ft_strlen(ft_itoa(ptr, "0123456789abcdef"));
    precision = parser->precision < length || parser->precision == -1 ? 0 : parser->precision;
    if (ptr == 0)
        return write_string("(nil)");
    else
        return output_pointer_flag(ptr, width, precision, parser->flag);
}
