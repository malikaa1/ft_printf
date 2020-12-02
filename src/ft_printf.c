#include "ft_printf.h"

void parse_flags(int *i, char *str, format_parser *parser)
{
    if (str[*i] == '-')
    {
        parser->flag = '-';
        *i = *i + 1;
    }
    else if (str[*i] == '0')
    {
        parser->flag = '0';
        *i = *i + 1;
    }
    else
    {
        parser->flag = ' ';
    }
}

void parse_width(int *i, char *str, format_parser *parser)
{
    int count;
    int j;
    char *width;

    count = 0;
    j = *i;
    // if (str[*i - 1] == '.') //todo
    //     return;
    if (str[j] == '*')
    {
        parser->is_dynamic_wdith = 1;
        *i = *i + 1;
        return;
    }
    while (ft_isdigit(str[j]))
    {
        j++;
        count++;
    }
    j = 0;
    width = malloc(count * sizeof(char) + 1);
    while (j < count)
    {
        width[j] = str[*i];
        *i = *i + 1;
        j++;
    }
    width[j] = '\0';
    parser->width = ft_atoi(width);
    free(width);
}

void parse_precision(int *i, char *str, format_parser *parser)
{
    char *result;
    int count;

    count = 0;
    if (str[*i] != '.')
        return;
    *i = *i + 1;
    if (str[*i] == '*')
    {
        parser->is_dynamic_precision = 1;
        *i = *i + 1;
    }

    else if (ft_isdigit(str[*i]) == 1)
    {
        while (ft_isdigit(str[*i]))
        {
            *i = *i + 1;
            count++;
        }
        result = ft_substr(str, *i - count, count);
        parser->precision = ft_atoi(result);
    }
}

void parse_specifier(int *i, char *str, format_parser *parser)
{
    parser->specifier = str[*i];
}

void output(va_list *parms_arry, format_parser *parser)
{
    if (parser->specifier == 'd' || parser->specifier == 'i')
        output_d_specifier(parms_arry, parser);
    if (parser->specifier == 's')
        output_s_specifier(parms_arry, parser);
    if (parser->specifier == 'c')
        output_c_specifier(parms_arry, parser);
    if (parser->specifier == 'u')
        output_u_specifier(parms_arry, parser);
    if (parser->specifier == 'x')
        output_x_specifier(parms_arry, parser);
    if (parser->specifier == 'X')
        output_X_specifier(parms_arry, parser);
    if (parser->specifier == 'p')
        output_p_specifier(parms_arry, parser);
}

int ft_printf(char *args, ...)
{
    int i = 0;
    va_list parms_arry;
    va_start(parms_arry, args);
    format_parser parser;

    while (args[i] != '\0')
    {
        if (args[i] == '%')
        {
            parser.flag = ' ', parser.precision = 0, parser.specifier = ' ', parser.width = 0, parser.is_dynamic_precision = 0,
            parser.is_dynamic_wdith = 0;
            i++;
            parse_flags(&i, args, &parser);
            parse_width(&i, args, &parser);
            parse_precision(&i, args, &parser);
            parse_specifier(&i, args, &parser);
            output(&parms_arry, &parser);
        }
        else
            ft_putchar(args[i]);
        i++;
    }
    return 0;
    va_end(parms_arry);
}

// %[flags][width][.precision][length]specifier

int main()
{
    // int i = 3;
    // unsigned int u = 2200;
    // int x = 2200000;
    // int X = 2200000;
    // char c = 'a';
    // char *s = "lol";

    // printf("%i %u %x %X %c %s %p\n", i, u, x, X, c, s, s);
    // ft_printf("%i %u %x %X %c %s %p", i, u, x, X, c, s, s);

    printf("%6.4d!\n", -12);
    ft_printf("%6.4d!\n", -12);

    printf("%-6.4d!\n", -12);
    ft_printf("%-6.4d!\n", -12);

    printf("%*.4d!\n", 10, -12);
    ft_printf("%*.4d!\n", 10, -12);

    printf("%*.*d!\n", 6, 4, -12);
    ft_printf("%*.*d!\n", 6, 4, -12);

    // printf("%-6.4d!\n", 12);
    // ft_printf("%-6.4d!\n", 12);

    return 0;
}
