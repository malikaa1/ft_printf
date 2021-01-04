#include "../includes/ft_printf.h"

int main()
{
    ft_printf("%6.*X %x\n",33, 1234, 4569);
    printf("%6.*X %x\n",33, 1234, 4569);

    return 0;
}