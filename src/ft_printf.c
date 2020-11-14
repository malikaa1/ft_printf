#include "ft_printf.h"

void char_args(va_list *parms_arry, flags flag)
{
    if (flag.type == 'c')
        return (ft_putchar(va_arg(*parms_arry, int)));
    if (flag.type == 's')
        return (ft_putstr(va_arg(*parms_arry, char *)));
    if (flag.type == 'd' || flag.type == 'i')
        return (ft_putnbr(va_arg(*parms_arry, int)));
    if (flag.type == 'u')
        return (ft_putnbr(va_arg(*parms_arry, unsigned int)));
    if (flag.type == 'x')
        return (ft_putnbr_base(va_arg(*parms_arry, unsigned int), "0123456789abcdef"));
}
int ft_printf(char *args, ...)
{
    int i = 0;
    va_list parms_arry;
    va_start(parms_arry, args);

    flags flag;
    while (args[i] != '\0')
    {
        if (args[i] == '%')
        {
            flag.type = args[i + 1];
            char_args(&parms_arry, flag);
            i++;
        }
        else
            ft_putchar(args[i]);
        i++;
    }
    return 0;
    va_end(parms_arry);
}

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
    char *str = "salut";
    int k = 20;
    unsigned int l = 2020;
    char c = 'c';
    unsigned int s = 123;


    // printf("=== mon printf====\n");
    // ft_printf("==> %s %d %u %c %x\n", str, k, l, c, s);
    // printf("=== printf====\n");
    // printf("==> %s %d %u %c %x\n", str, k, l, c, s);
    // printf("le p de str est :%p", str);
    printf("1234 %-9s %d", str, k);

    return 0;
}
