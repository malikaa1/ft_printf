/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:35:54 by mrahmani          #+#    #+#             */
/*   Updated: 2021/01/05 16:57:43 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		write_str(char *str, int precision)
{
	int		i;

	i = 0;
	if (precision == -1 || precision > ft_strlen(str))
		precision = ft_strlen(str);
	while (str[i] != '\0' && i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		write_flags(char c, char *str, int width, int precision)
{
	int		size;
	int		length;
	int		count;

	count = 0;
	size = 0;
	if (width == -1)
		return (0);
	else
	{
		length = ft_strlen(str);
		precision = precision > width ? width : precision;
		if (precision >= length && width > precision)
			size = width - length;
		else if (precision == -1 || width == precision)
			size = width - length;
		else if ((width > precision && length < width) || width > precision)
			size = width - precision;
	}
	while (size > 0)
	{
		count += write_char(c);
		size--;
	}
	return (count);
}

int		output_s(format_parser *parser, char *str, int precision, int width)
{
	int		count;

	count = 0;
	if (width < -1)
	{
		parser->flag = '-';
		width = width * -1;
	}
	if (parser->flag == '-')
	{
		count += write_str(str, precision);
		count += write_flags(' ', str, width, precision);
	}
	else if (parser->flag == '0')
	{
		count += write_flags('0', str, width, precision);
		count += write_str(str, precision);
	}
	else if (parser->flag == ' ')
	{
		count += write_flags(' ', str, width, precision);
		count += write_str(str, precision);
	}
	return (count);
}

int		output_s_specifier(va_list *parms_arry, format_parser *parser)
{
	char	*arg;
	int		precision;
	int		width;

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
	arg = va_arg(*parms_arry, char *);
	if (arg == NULL)
		arg = "(null)";
	precision = precision < -1 ? ft_strlen(arg) : precision;
	return (output_s(parser, arg, precision, width));
}
