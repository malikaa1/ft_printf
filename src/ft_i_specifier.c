/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:04:13 by mrahmani          #+#    #+#             */
/*   Updated: 2021/01/05 13:25:19 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_sizeof_flag(int nb, int width, int precision)
{
	int		sizeof_nb;
	int		result;
	char	*ptr;

	result = 0;
	ptr = ft_itoa(nb, "0123456789");
	sizeof_nb = ft_strlen(ptr);
	free(ptr);
	if (width >= sizeof_nb && precision < width)
	{
		if (precision == 0 || precision == -1 || precision < sizeof_nb)
			result = (nb == 0 && precision == 0) ? width : width - sizeof_nb;
		else if (precision >= sizeof_nb)
			result = nb < 0 ? (width - precision - 1) : (width - precision);
	}
	else if (width <= sizeof_nb && precision <= sizeof_nb)
		result = 0;
	else
		result = width - precision;
	return (result);
}

int		write_nb(int nb, int precision, char flag)
{
	int		lenght_nb;
	int		count;
	char	*ptr;

	count = 0;
	ptr = ft_itoa(nb, "0123456789");
	lenght_nb = ft_strlen(ptr);
	free(ptr);
	if (nb < 0 && precision >= lenght_nb && flag == '0')
		lenght_nb = lenght_nb - 1;
	if (nb == 0 && precision == 0)
		return (0);
	if (nb < 0 && (flag == ' ' || flag == '-'))
	{
		count += write_char('-');
		lenght_nb--;
	}
	while (precision > lenght_nb)
	{
		count += write_char('0');
		precision--;
	}
	count += write_number(nb);
	return (count);
}

int		write_flag(int nb, int width, char flag, int precision)
{
	int		sizeof_flag;
	char	output_char;
	int		count;

	count = 0;
	sizeof_flag = ft_sizeof_flag(nb, width, precision);
	if (flag == '-' || flag == ' ' || (flag == '0' && precision >= 0))
		output_char = ' ';
	if (flag == '0' && precision == -1)
		output_char = '0';
	if (nb < 0)
	{
		if (output_char == '0' && flag != ' ' && flag != '-')
			count += write_char('-');
	}
	while (sizeof_flag-- > 0)
		count += write_char(output_char);
	if (nb < 0)
	{
		if (output_char == ' ' && flag != ' ' && flag != '-')
			count += write_char('-');
	}
	return (count);
}

int		output_int_flag(int nb, int width, int precision, char flag)
{
	int		count;

	count = 0;
	if (flag == '-')
		count += write_nb(nb, precision, flag);
	count += write_flag(nb, width, flag, precision);
	if (flag == '0' || flag == ' ')
		count += write_nb(nb, precision, flag);
	if (nb < 0)
		count = count - 1;
	return (count);
}

int		output_d_specifier(va_list *parms_arry, format_parser *parser)
{
	int		d;
	int		width;
	int		precision;

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
	precision = precision < -1 ? -1 : precision;
	d = va_arg(*parms_arry, int);
	return (output_int_flag(d, width, precision, parser->flag));
}
