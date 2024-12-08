/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:19:12 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/28 23:23:50 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	string_handler(va_list args, t_flags *flags)
{
	int		count;
	char	*string;

	count = 0;
	string = va_arg(args, char *);
	if (flags->width && flags->precision)
		count += print_w_p(string, flags->width,
				flags->precision, flags->left_aligment);
	else if (flags->precision)
		count += print_p(string, flags->precision);
	else if (flags->width)
		count += print_w(string, flags->width);
	else
		count += ft_putstr(string);
	return (count);
}

int	print_w_p(char *string, int width, int precision, int left_aligment)
{
	int	count;
	int	size_string;

	count = 0;
	if (!string)
	{
		if (precision < 6)
			precision = 0;
		else
			count += ft_putstr("(null)");
		return (count);
	}
	size_string = ft_strlen(string);
	if (precision <= size_string)
		size_string = precision;
	precision = size_string;
	if (size_string >= width)
		return (print_p(string, size_string));
	while (left_aligment && precision-- > 0)
		count += ft_putchar(*string++);
	while (width -- > size_string)
		count += ft_putchar(' ');
	while (!left_aligment && precision-- > 0)
		count += ft_putchar(*string++);
	return (count);
}

int	print_p(char *string, int precision)
{
	int	count;

	count = 0;
	if (!string)
	{
		if (precision < 6)
			precision = 0;
		else
			count += ft_putstr("(null)");
		return (count);
	}
	while (string[count] && precision-- > 0)
		count += ft_putchar(string[count]);
	return (count);
}

int	print_w(char *string, int width)
{
	int	count;
	int	size_string;

	count = 0;
	if (!string)
		string = "(null)";
	size_string = ft_strlen(string);
	if (size_string >= width)
		return (count += ft_putstr(string), count);
	else
	{
		while (width -- > 0)
			count += ft_putchar(' ');
		count += ft_putstr(string);
		return (count);
	}
}
