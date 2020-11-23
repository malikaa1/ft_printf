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
    int j;
    int k;

    if (str[*i] != '.')
        return;
    *i = *i + 1;
    j = *i;
    k = 0;
    parser->precision = malloc(2 * sizeof(char));
    if (str[*i] == '*')
    {
        parser->precision[0] = '*';
        parser->precision[1] = '\0';
    }
    else
    {
        while (ft_isdigit(str[j]))
            j++;
        parser->precision = malloc((j - *i) + 1 * sizeof(char));
        while (ft_isdigit(str[*i]) == 1)
        {
            parser->precision[k] = str[*i];
            *i = *i + 1;
            k++;
        }
        parser->precision[k] = '\0';
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
            parser.flag = ' ', parser.precision = "", parser.specifier = ' ', parser.width = 0, parser.is_dynamic_wdith = 0;
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
    char *s = "lol";
  //  printf("pointeronly %p\n", s);
    ft_printf("pointeronly %p\n", s);

   // printf("pointeronly %x\n", s);
    ft_printf("pointeronly %x\n", s);
    ft_printf("pointeronly %X\n", s);
    ft_printf("pointeronly %s\n", s);
    ft_printf("pointeronly %d\n", 10);
    ft_printf("pointeronly %i\n", 20);
    ft_printf("pointeronly %u\n",100);

    return 0;
}
