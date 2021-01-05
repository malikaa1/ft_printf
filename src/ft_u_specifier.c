/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:03:34 by mrahmani          #+#    #+#             */
/*   Updated: 2021/01/05 17:15:19 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_sizeof_flag_u(unsigned int nb, int width, int precision)
{
	int		sizeof_nb;
	int		result;
	char	*ptr;

	ptr = ft_itoa(nb, "0123456789");
	result = 0;
	sizeof_nb = ft_strlen(ptr);
	free(ptr);
	if (width >= sizeof_nb && precision < width)
	{
		if (precision == 0 || precision == -1 || precision < sizeof_nb)
			result = (nb == 0 && precision == 0) ? width : width - sizeof_nb;
		else if (precision >= sizeof_nb)
			result = (width - precision);
	}
	else if (width <= sizeof_nb && precision <= sizeof_nb)
		result = 0;
	else
		result = width - precision;
	return (result);
}

int		write_nb_u(unsigned int nb, int precision)
{
	int		lenght_nb;
	int		count;
	char	*ptr;

	count = 0;
	ptr = ft_itoa(nb, "0123456789");
	lenght_nb = ft_strlen(ptr);
	free(ptr);
	if (nb == 0 && precision == 0)
		return (0);
	while (precision > lenght_nb)
	{
		count += write_char('0');
		precision--;
	}
	count += write_number(nb);
	return (count);
}

int		write_flag_u(unsigned int nb, int width, char flag, int precision)
{
	int		sizeof_flag;
	char	output_char;
	int		count;

	count = 0;
	if (width == -1)
		return (0);
	sizeof_flag = ft_sizeof_flag_u(nb, width, precision);
	if (flag == '-' || flag == ' ' || (flag == '0' && precision >= 0))
		output_char = ' ';
	else if (flag == '0' && precision <= -1)
		output_char = '0';
	while (sizeof_flag > 0)
	{
		count += write_char(output_char);
		sizeof_flag--;
	}
	return (count);
}

int		output_u_flag(unsigned int nb, int width, int precision, char flag)
{
	int		count;

	count = 0;
	if (flag == '-')
		count += write_nb_u(nb, precision);
	count += write_flag_u(nb, width, flag, precision);
	if (flag == '0' || flag == ' ')
		count += write_nb_u(nb, precision);
	return (count);
}

int		output_u_specifier(va_list *parms_arry, format_parser *parser)
{
	unsigned int	un_int;
	int				precision;
	int				width;

	if (parser->is_dynamic_wdith == 1)
	{
		width = va_arg(*parms_arry, int);
		if (width < 0)
		{
			width = width * -1;
			parser->flag = '-';
		}
	}
	else
		width = parser->width;
	if (parser->is_dynamic_precision == 1)
		precision = va_arg(*parms_arry, int);
	else
		precision = parser->precision;
	un_int = va_arg(*parms_arry, unsigned int);
	return (output_u_flag(un_int, width, precision, parser->flag));
}
