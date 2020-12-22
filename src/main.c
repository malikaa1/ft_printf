#include "ft_printf.h"

int main()
{

    // ft_printf("lE%-1.4sYgkgg\n", NULL);
    // printf("lE%-1.4sYgkgg\n", NULL);

    // ft_printf("60Y%%%-12s6U1olE%-1.4sYgkgg", "lf4cezZG97sYZDZY62CqOtccHIW2pcQMB1idy1at3K  StscStC27SoPWpPqCWSBAXf0C1USZL2x8ypB", NULL);
    // printf("\n");
    // printf("60Y%%%-12s6U1olE%-1.4sYgkgg", "lf4cezZG97sYZDZY62CqOtccHIW2pcQMB1idy1at3K  StscStC27SoPWpPqCWSBAXf0C1USZL2x8ypB", NULL);
    // printf("\n");

    ft_printf("-- %d --\n", ft_printf("%-1.4sYgkgg", NULL));
    printf("-- %d --\n", printf("%-1.4sYgkgg", NULL));
    //printf("-- %d --\n", printf("60Y%%%-12s6U1olE%-1.4sYgkgg", "lf4cezZG97sYZDZY62CqOtccHIW2pcQMB1idy1at3K  StscStC27SoPWpPqCWSBAXf0C1USZL2x8ypB", NULL));
    //  printf("-- %d --\n", printf("60Y%%%-12s6U1olE%-1.4sYgkgg", "lf4cezZG97sYZDZY62CqOtccHIW2pcQMB1idy1at3K  StscStC27SoPWpPqCWSBAXf0C1USZL2x8ypB", NULL));

    // printf("%3.6s", NULL);
    // printf("\n");
    // ft_printf("%3.6s", NULL);

    return 0;
}