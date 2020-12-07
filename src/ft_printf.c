#include "ft_printf.h"

void output_percent(char *arg)
{
    int lenght;

    lenght = ft_strlen(arg);

    if (arg[lenght - 1] == '%' && ft_isalpha(arg[1]) == 0)
        ft_putchar('%');
    return;
}

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
        if (parser->precision <= 0)
            parser->errors_count += 1;
    }
    else
    {
        while (!ft_isdigit(str[*i]) && !is_valid_specifier(str[*i]))
            *i = *i + 1;
        parser->errors_count += 1;
    }
}

void parse_specifier(int *i, char *str, format_parser *parser)
{
    if (is_valid_specifier(str[*i]))
        parser->specifier = str[*i];
    else
        parser->errors_count += 1;
    *i = *i + 1;
}

void output(va_list *parms_arry, format_parser *parser)
{
    if (parser->errors_count > 0)
    {
        if (*parms_arry != NULL)
            va_arg(*parms_arry, int);
        return;
    }
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

    while (args[i] != '\0')
    {
        if (args[i] == '%')
        {
            INIT_PARSER(parser);
            i++;
            output_percent(args);
            parse_flags(&i, args, &parser);
            parse_width(&i, args, &parser);
            parse_precision(&i, args, &parser);
            parse_specifier(&i, args, &parser);
            output(&parms_arry, &parser);
        }
        else
        {
            ft_putchar(args[i]);
            i++;
        }
    }
    return 0;
    va_end(parms_arry);
}

int is_valid_specifier(char c)
{
    return c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'c' || c == 's' || c == 'p' || c == 'n' ? 1 : 0;
}

// %[flags][width][.precision][length]specifier

// int main()
// {
//     //ft_printf("=>%.03s\n", NULL);
//     //ft_printf("=>%s\n", NULL);
//     char *s_hidden = "tototototo";
//     printf("%3.s", s_hidden);
//     // ft_printf("%10.9s", "lol");
//     //printf("=>%s\n", NULL);
//     //ft_printf("%.03s", NULL);
//     return 0;
// }
