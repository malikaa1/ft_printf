/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:53:17 by mrahmani          #+#    #+#             */
/*   Updated: 2021/01/04 18:10:28 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		write_str_x(char *str, int precision)
{
	int size;
	int count;

	count = 0;
	if (ft_strcmp(str, "(null)") == 0 && precision < 6 && precision != -1)
		return (0);
	if (precision == 0)
		return (0);
	if (precision > ft_strlen(str))
	{
		size = precision - ft_strlen(str);
		while (size > 0)
		{
			count += write_char('0');
			size--;
		}
	}
	count += write_string(str);
	return (count);
}

int		write_flag_x(char flag, char *str, int width, int precision)
{
	int		size;
	int		length;
	int		count;

	count = 0;
	size = 0;
	if (width == -1)
		return (0);
	length = ft_strlen(str);
	if (flag == '0' && precision >= 0)
		flag = ' ';
	if (precision > width)
		precision = width;
	if ((precision >= length && width > precision) || width == precision)
		size = width - precision;
	else if ((precision == 0 && width > precision) || width < precision)
		size = width;
	else if (precision == -1 || (width > precision && length >= precision))
		size = width - length;
	while (size > 0)
	{
		count += write_char(flag);
		size--;
	}
	return (count);
}

int		output_x_flags(format_parser *parser, char *s, int preci, int width)
{
	int		count;

	count = 0;
	if (parser->flag == '-')
	{
		count += write_str_x(s, preci);
		count += write_flag_x(' ', s, width, preci);
	}
	else if (parser->flag == '0')
	{
		count += write_flag_x('0', s, width, preci);
		count += write_str_x(s, preci);
	}
	else if (parser->flag == ' ')
	{
		count += write_flag_x(' ', s, width, preci);
		count += write_str_x(s, preci);
	}
	free(s);
	return (count);
}

int		output_x_low_specifier(va_list *parms_arry, format_parser *parser)
{
	char			*arg_x;
	int				precision;
	int				width;
	unsigned int	int_hexa_upp;

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
	int_hexa_upp = va_arg(*parms_arry, unsigned int);
	arg_x = ft_itoa(int_hexa_upp, "0123456789abcdef");
	if (int_hexa_upp > 0 && precision == 0)
		precision = ft_strlen(arg_x);
	return (output_x_flags(parser, arg_x, precision, width));
}

int		output_x_upp_specifier(va_list *parms_arry, format_parser *parser)
{
	char			*arg_x;
	int				precision;
	int				width;
	unsigned int	int_hexa_upp;

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
	int_hexa_upp = va_arg(*parms_arry, unsigned int);
	arg_x = ft_itoa(int_hexa_upp, "0123456789ABCDEF");
	if (int_hexa_upp > 0 && precision == 0)
		precision = ft_strlen(arg_x);
	return (output_x_flags(parser, arg_x, precision, width));
}
