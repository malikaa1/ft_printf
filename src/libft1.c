#include "ft_printf.h"

int		ft_strlen(const char *str)
{
	const char	*ptr;
	int			i;

	ptr = str;
	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
    int i;

    i = 0;
    if (s == NULL)
        return;
    while (s[i] != '\0')
    {
        write(1, &s[i], 1);
        i++;
    }
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
int		ft_count(long long n, char *base)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n / ft_strlen(base) != 0)
	{
		i++;
		n = n / ft_strlen(base);
	}
	return (i + 1);
}

// int		check_base(char *base)
// {
// 	int	i;
// 	int j;

// 	i = 0;
// 	j = i + 1;
// 	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
// 		return (-1);
// 	while (base[i] != '\0')
// 	{
// 		while (base[j] != '\0')
// 		{
// 			if (base[i] == base[j])
// 				return (-1);
// 			j++;
// 		}
// 		if (base[i] == '+' || base[i] == '-')
// 			return (-1);
// 		i++;
// 	}
// 	return (1);
// }
// char	*ft_itoa(long long nbr, char *base)
// {
// 	char	*str;
// 	int		length;
// 	int		tmp;

// 	length = ft_count(nbr, base);
// 	tmp = length;
// 	str = malloc(sizeof(char) * (length + 1));
// 	if (str != NULL && check_base(base) == 1)
// 	{
// 		if (nbr < 0)
// 		{
// 			str[0] = '-';
// 			nbr = nbr * -1;
// 		}
// 		while (nbr / ft_strlen(base) != 0 && length >= 0)
// 		{
// 			str[length - 1] = base[nbr % ft_strlen(base)];
// 			nbr = nbr / ft_strlen(base);
// 			length--;
// 		}
// 		str[length - 1] = base[nbr];
// 		str[tmp] = '\0';
// 	}
// 	return (str);
// }


int	ft_double_str(char *str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		j = i + 1;
		while(str[j])
		{	if (str[i] == str[j])
				return (1);
		j++;
		}
	i++;
	}
	return (0);
}

int ft_signe_is_exist(char *str, char c)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
	i++;
	}
	return (0);
}

int	ft_count_base(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
void	ft_putnbr_base(int nbr, char *base)
{
	int count_base; 

	count_base = ft_count_base(base);
	if (count_base <= 1 || ft_double_str(base) == 1 || ft_signe_is_exist(base, '-') == 1 || ft_signe_is_exist(base, '+') == 1)
		return;

	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base((nbr * -1), base);
	}
	else if (nbr >= count_base)
	{
		ft_putnbr_base((nbr / count_base), base);
	}
	ft_putchar(base[(nbr % count_base)]);
}