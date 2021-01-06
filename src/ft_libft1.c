/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:21:04 by mrahmani          #+#    #+#             */
/*   Updated: 2021/01/05 17:26:32 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strlen(const char *str)
{
	const char	*ptr;
	int			i;

	if (str == NULL)
		return (0);
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

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(long long nb)
{
	int		i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i = i * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

t_format	init_parser()
{
	t_format s;
	s.flag = ' '; 
	s.precision = -1; 
	s.specifier = ' '; 
	s.width = -1; 
	s.is_dynamic_precision = 0; 
	s.is_dynamic_wdith = 0;
	return (s);
}