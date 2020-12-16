#include "ft_printf.h"

int write_string(char *str)
{
    ft_putstr(str);
    return ft_strlen(str);
}

int write_char(char c)
{
    ft_putchar(c);
    return 1;
}

int write_number(long long nb)
{
    int length = ft_strlen(ft_itoa(nb, "0123456789"));
    ft_putnbr(nb);
    return length;
}

int output(va_list *parms_arry, format_parser *parser)
{
    if (parser->specifier == '%')
        return write_char('%');
    if (parser->specifier == ' ')
        return 0;
    if (parser->specifier == 'd' || parser->specifier == 'i')
        return output_d_specifier(parms_arry, parser);
    if (parser->specifier == 's')
        return output_s_specifier(parms_arry, parser);
    if (parser->specifier == 'c')
        return output_c_specifier(parms_arry, parser);
    if (parser->specifier == 'u')
        return output_u_specifier(parms_arry, parser);
    if (parser->specifier == 'x')
        return output_x_specifier(parms_arry, parser);
    if (parser->specifier == 'X')
        return output_x_upp_specifier(parms_arry, parser);
    if (parser->specifier == 'p')
        return output_p_specifier(parms_arry, parser);
    return 0;
}

int ft_printf(char *args, ...)
{
    int i;
    int count;

    i = 0;
    count = 0;
    va_list parms_arry;
    va_start(parms_arry, args);

    while (args[i] != '\0')
    {
        if (args[i] == '%')
        {
            INIT_PARSER(parser);
            i++;
            parse_flags(&i, args, &parser);
            parse_width(&i, args, &parser);
            parse_precision(&i, args, &parser);
            parse_specifier(&i, args, &parser);
            count += output(&parms_arry, &parser);
        }
        else
            count += write_char(args[i++]);
    }
    va_end(parms_arry);
    return count;
}



