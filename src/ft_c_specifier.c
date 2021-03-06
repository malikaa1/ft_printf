/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:39:11 by mrahmani          #+#    #+#             */
/*   Updated: 2021/01/04 17:49:31 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_c_speci(char flag, char c, int width)
{
	int		i;
	int		count;

	count = 0;
	i = width - 1;
	if (flag == '-' || (flag == ' ' && width == 0))
		count += write_char(c);
	while (i > 0)
	{
		count += write_char(' ');
		i--;
	}
	if (flag == ' ' && width != 0)
		count += write_char(c);
	return (count);
}

int		ft_print_percent(char flag, char c, int width)
{
	int		i;
	int		count;
	char	output_char;

	if (flag == ' ' || flag == '-')
		output_char = ' ';
	if (flag == '0')
		output_char = '0';
	count = 0;
	i = width - 1;
	if (flag == '-' || (flag == ' ' && width == 0))
		count += write_char(c);
	while (i > 0)
	{
		count += write_char(output_char);
		i--;
	}
	if ((flag == ' ' && width != 0) || (flag == '0' && width != 0))
		count += write_char(c);
	return (count);
}

int		output_c_specifier(va_list *parms_arry, t_format *parser)
{
	char	c;
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
	c = va_arg(*parms_arry, int);
	return (ft_print_c_speci(parser->flag, c, width));
}
