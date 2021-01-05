/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:18 by mrahmani          #+#    #+#             */
/*   Updated: 2021/01/05 20:53:37 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		write_flag_p(int size)
{
	int		count;

	count = 0;
	while (size > 0)
	{
		ft_putchar(' ');
		count++;
		size--;
	}
	return (count);
}

int		null_pointer(char *ptr, int width, int precision, char flag)
{
	int		count;

	count = 0;
	if (width > ft_strlen(ptr))
		width = width - ft_strlen(ptr);
	else
		width = 0;
	if (flag == ' ' || flag == '0')
	{
		count += write_flag_p(width);
		count += write_string(ptr);
	}
	if (flag == '-')
	{
		count += write_string(ptr);
		count += write_flag_p(width);
	}
	if (precision > 3)
	{
		while ((precision--) - 1 > 0)
			count += write_char('0');
	}
	return (count);
}

int		ft_count_ch(long long int ptr, int width, int precision, char flag)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(ptr, "0123456789abcdef");
	if (flag == ' ' || flag == '0')
	{
		count += write_flag_p(width);
		count += write_string("0x");
		while ((precision - ft_strlen(str)) > 0)
		{
			count += write_char('0');
			precision--;
		}
		count += write_string(str);
	}
	if (flag == '-')
	{
		count += write_string("0x");
		count += write_string(str);
		count += write_flag_p(width);
	}
	free(str);
	return (count);
}

int		ft_output(long long int ptr, int width, int precision, char flag)
{
	int		length;
	char	*str;

	str = ft_itoa(ptr, "0123456789abcdef");
	length = ft_strlen(str);
	free(str);
	if (precision == -1)
		precision = 0;
	if (width > length)
		width = width - length - 2;
	else
		width = 0;
	return (ft_count_ch(ptr, width, precision, flag));
}

int		output_p_specifier(va_list *parms_arry, format_parser *parser)
{
	long long int	ptr;
	int				precision;

	if (parser->is_dynamic_wdith == 1)
	{
		parser->width = va_arg(*parms_arry, int);
		if (parser->width < 0)
		{
			parser->width = parser->width * -1;
			parser->flag = '-';
		}
	}
	ptr = va_arg(*parms_arry, long long int);
	precision = parser->precision;
	if (ptr == 0 && precision == 0)
		return (null_pointer("0x", parser->width, precision, parser->flag));
	else if (ptr == 0 && precision != 0)
		return (null_pointer("0x0", parser->width, precision, parser->flag));
	else
		return (ft_output(ptr, parser->width, precision, parser->flag));
}
