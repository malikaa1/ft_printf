/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:43:33 by mrahmani          #+#    #+#             */
/*   Updated: 2021/01/05 12:58:04 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		write_string(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

int		write_char(char c)
{
	ft_putchar(c);
	return (1);
}

int		write_number(long long nb)
{
	int		length;
	char	*str;

	str = ft_itoa(nb, "0123456789");
	length = ft_strlen(str);
	free(str);
	ft_putnbr(nb);
	return (length);
}

int		output(va_list *parms_arry, t_format *parser)
{
	if (parser->specifier == '%')
		return (ft_print_percent(parser->flag, '%', parser->width));
	if (parser->specifier == ' ')
		return (0);
	if (parser->specifier == 'd' || parser->specifier == 'i')
		return (output_d_specifier(parms_arry, parser));
	if (parser->specifier == 's')
		return (output_s_specifier(parms_arry, parser));
	if (parser->specifier == 'c')
		return (output_c_specifier(parms_arry, parser));
	if (parser->specifier == 'u')
		return (output_u_specifier(parms_arry, parser));
	if (parser->specifier == 'x')
		return (output_x_low_specifier(parms_arry, parser));
	if (parser->specifier == 'X')
		return (output_x_upp_specifier(parms_arry, parser));
	if (parser->specifier == 'p')
		return (output_p_specifier(parms_arry, parser));
	return (0);
}

int		ft_printf(char *args, ...)
{
	int		i;
	int		count;
	va_list	parms_arry;
	t_format parser;
	
	i = 0;
	count = 0;
	va_start(parms_arry, args);
	while (args[i] != '\0')
	{
		if (args[i] == '%')
		{
			parser = init_parser();
			i++;
			parse_flags(&i, args, &parser);
			parse_width(&i, args, &parser);
			parse_precision(&i, args, &parser);
			parse_specifier(&i, args, &parser);
			count += output(&parms_arry, &parser);
		}
		else
			count += write_char(args[i++]);
	}
	va_end(parms_arry);
	return (count);
}
