#include "ft_printf.h"

void parse_specifier(int *i, char *str, format_parser *parser)
{
    parser->specifier = str[*i];
    // if (parser->specifier == 'c')
    //     return (ft_putchar(va_arg(*parms_arry, int)));
    // if (parser->specifier == 's')
    //     return (ft_putstr(va_arg(*parms_arry, char *)));
    // if (parser->specifier == 'd' || parser->specifier == 'i')
    //     return (ft_putnbr(va_arg(*parms_arry, int)));
    // if (parser->specifier == 'u')
    //     return (ft_putnbr(va_arg(*parms_arry, unsigned int)));
    // if (parser->specifier == 'x')
    //     return (ft_putnbr_base(va_arg(*parms_arry, unsigned int), "0123456789abcdef"));
}

void output_int_flag(int nb, int width, int length, char flag)
{
    char output_char;
    if (flag == '-' || flag == ' ')
        output_char = ' ';
    if (flag == '0')
        output_char = '0';

    int j;
    j = width - length;
    if (flag == '-')
        ft_putnbr(nb);
    while (j > 0)
    {
        ft_putchar(output_char);
        j--;
    }
    if (flag == '0' || flag == ' ')
        ft_putnbr(nb);
}

void output_d_specifier(va_list *parms_arry, format_parser *parser)
{
    int d = 0;
    int length;
    d = va_arg(*parms_arry, int);
    length = ft_strlen(ft_itoa(d, "0123456789"));
    if (parser->width > length)
        output_int_flag(d, parser->width, length, parser->flag);
}

void output(va_list *parms_arry, format_parser *parser)
{
    if (parser->specifier == 'd')
        output_d_specifier(parms_arry, parser);
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
    count = 0;
    int j;
    j = *i;
    if (str[j] == '*')
    {
        parser->is_dynamic_wdith = 1;
        return;
    }
    while (ft_isdigit(str[j]))
    {
        j++;
        count++;
    }
    j = 0;
    char *width = malloc(count * sizeof(char) + 1);
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
    if (str[*i] != '.')
        return;
    *i = *i + 1;
    int j = *i;
    int k;
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

// int is_identifiers(char s)
// {
//         if (s != 's' || s != 'x' || s != 'd' || s != 'X' || s != 'p')
//             return (1);
//     return 0;
// }
// char *flags(char *str)
// {
//     int i = 0;
//     int z = 0;
//     int count = 1;
//     char *ptr;

//     while (str[i] != '\0')
//     {
//         if (str[i] == '%')
//         {
//             while (str[i + count] != 's')
//             {
//                 if (str[i + count] == '-' || str[i + count] == '0' || str[i + count] == '*' || str[i + count] == '.')
//                 {
//                     ptr[z] = str[i + count];
//                     z++;
//                 }
//                 count++;
//             }
//             return ptr;
//         }
//         i++;
//     }
//     return NULL;
// }

int main()
{
    //char *str = "salut";
    // int k = 20;
    // unsigned int l = 2020;
    // char c = 'c';
    // unsigned int s = 123;

    // printf("=== mon printf====\n");
    // ft_printf("==> %s %d %u %c %x\n", str, k, l, c, s);
    // printf("=== printf====\n");
    // printf("==> %s %d %u %c %x\n", str, k, l, c, s);

    // float nb = 3.1234567;
    // printf("%-*flol %-*flol", 100, nb, 100, nb);
    // printf("%.12f lol", nb);

    // ft_printf("abc %s %.2d %u %-10d \n", str, k, l, c, s);
    ft_printf("abc %7d t\n", 1000);
    printf("abc %7d t\n", 1000);
    //printf("abc %s %d %u %c %x\n", str, k, l, c, s);

    // printf("%10d !\n", 100);  // =>        100 !
    // printf("%-10d !\n", 100); // =>100        !
    // printf("%010d !\n", 100); //=> 0000000100 !
    // printf("%-d!", 100);      //=> 0000000100 !
    return 0;
}
