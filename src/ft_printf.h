#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct flags
{
    char type;
} flags;

int		ft_strlen(const char *str);
void	ft_putchar(char c);
void ft_putstr(char *s);
void	ft_putnbr(int nb);
//char	*ft_itoa(long long nbr, char *base);
void	ft_putnbr_base(int nbr, char *base);

void char_args(va_list *parms_arry, flags flag);
int ft_printf(char *args, ...);

#endif