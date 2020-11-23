#include "ft_printf.h"

void pointer_flag(int lenght)
{
    int j;
    if (lenght < 8)
    {
        j = 8 - lenght;
        while (j > 0)
        {
            ft_putchar('0');
            j--;
        }
    }
}
void output_pointer_flag(unsigned int ptr, int width, int lenght, char flag)
{
    int i;

    i = width - lenght - (8 - lenght);
    if (flag == '-')
    {
        pointer_flag(lenght);
        ft_putstr(ft_itoa(ptr, "0123456789ABCDEF"));
    }
    while (i > 0)
    {
        ft_putchar(' ');
        i--;
    }
    if (flag == '0' || flag == ' ')
    {
        pointer_flag(lenght);
        ft_putstr(ft_itoa(ptr, "0123456789ABCDEF"));
    }
}
void output_p_specifier(va_list *parms_arry, format_parser *parser)
{
    int ptr;
    int width;
    int lenght;

    if (parser->is_dynamic_wdith == 0)
    {
        ptr = va_arg(*parms_arry, int);
        width = parser->width;
    }
    else if (parser->is_dynamic_wdith == 1)
    {
        width = va_arg(*parms_arry, int);
        ptr = va_arg(*parms_arry, int);
    }
    lenght = ft_strlen(ft_itoa(ptr, "0123456789ABCDEF"));
    output_pointer_flag(ptr, width, lenght, parser->flag);
}
