#include "ft_printf.h"

void parse_flags(int *i, char *str, format_parser *parser)
{
    if (str[*i] == '\0')
        return;

    if (str[*i] == '-')
    {
        parser->flag = '-';
        *i = *i + 1;
    }
    else if (str[*i] == '0')
    {
        parser->flag = '0';
        *i = *i + 1;
        if (str[*i] == '-')
        {
            parser->flag = '-';
            *i = *i + 1;
        }
    }
}

void parse_width(int *i, char *str, format_parser *parser)
{
    int count;
    char *width;

    count = 0;
    if (str[*i] == '\0')
        return;
    if (str[*i] == '*')
    {
        parser->is_dynamic_wdith = 1;
        *i = *i + 1;
        return;
    }
    while (ft_isdigit(str[*i]))
    {
        *i = *i + 1;
        count++;
    }
    if (count == 0)
        return;
    width = ft_substr(str, *i - count, count + 1);
    parser->width = ft_atoi(width);
    free(width);
}

void parse_precision(int *i, char *str, format_parser *parser)
{
    char *result;
    int count;
    if (str[*i] == '\0')
        return;

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
        free(result);
    }
    else if (is_valid_specifier(str[*i]))
        parser->precision = 0;
    else if (!ft_isdigit(str[*i]) && !is_valid_specifier(str[*i]))
    {
        while (!ft_isdigit(str[*i]) && !is_valid_specifier(str[*i]))
            *i = *i + 1;
    }
}

void parse_specifier(int *i, char *str, format_parser *parser)
{
    if (str[*i] == '\0')
        return;

    if (is_valid_specifier(str[*i]) || str[*i] == '%')
    {
        parser->specifier = str[*i];
        *i = *i + 1;
    }
    else if (is_valid_specifier(str[*i]) == 0)
    {
        *i = *i + 1;
        if (is_valid_specifier(str[*i]))
        {
            parser->specifier = str[*i];
            *i = *i + 1;
        }
    }
}
