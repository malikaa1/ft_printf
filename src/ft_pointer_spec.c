#include "ft_printf.h"

int write_flag_p(int size)
{
	int count;

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
	int count;
	int length;

	count = 0;
	length = ft_strlen(ptr);
	if (width > length)
		width = width - length;
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
		while((precision - 1) > 0)
		{
			count += write_char('0');
			precision--;
		}
	}
	return (count);
}

int output_pointer_flag(long long int ptr, int width, int precision, char flag)
{
	int length;
	int count;

	count = 0;
	length = ft_strlen(ft_itoa(ptr, "0123456789abcdef"));
	if (width > length)
		width = width - precision - length;
	else
		width = 0;
	if (flag == ' ' || flag == '0')
	{
		count += write_flag_p(width);
		count += write_string("0x");
		while ((precision - length) > 0)
		{
			count += write_char('0');
			precision--;
		}
		count += write_string(ft_itoa(ptr, "0123456789abcdef"));
	}
	if (flag == '-')
	{
		count += write_string("0x");
		count += write_string(ft_itoa(ptr, "0123456789abcdef"));
		count += write_flag_p(width);
	}
	return (count);
}

int output_p_specifier(va_list *parms_arry, format_parser *parser)
{
	long long int ptr;
	int length;
	int precision;

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
	length = ft_strlen(ft_itoa(ptr, "0123456789abcdef"));
	precision = parser->precision;
	if (ptr == 0 && precision == 0)
		return (null_pointer("0x",parser->width, precision, parser->flag));
	else if (ptr == 0 && precision != 0)
		return (null_pointer("0x0", parser->width, precision, parser->flag));
	else
		return (output_pointer_flag(ptr, parser->width, precision, parser->flag));
}
