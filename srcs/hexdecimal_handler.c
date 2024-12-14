/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdecimal_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:30:13 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/07 00:35:35 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	hexdecimal_handler(va_list args, t_flags *flags, char token)
{
	int					count;
	char				flag;
	long unsigned int	number;

	count = 0;
	number = va_arg(args, unsigned int);
	if (flags->zero)
		flag = '0';
	if (flags->width && flags->precision)
		flag = ' ';
	if (flags->left_aligment)
		count += print_hex_leftalig(flags, number, token);
	else if (flags->width)
		count += print_hex_width(flags, number, flag, token);
	else if (flags->precision)
		count += print_hex_precision(number, flags->precision, token);
	else if (ft_isupper(token))
		return (count += print_hashtag(number, flags->hashtag, token),
			count += ft_putnbr_base(number, HEXBASEUP), count);
	else
	{
		count += print_hashtag(number, flags->hashtag, token);
		count += ft_putnbr_base(number, HEXBASE);
	}
	return (count);
}

int	print_hex_leftalig(t_flags *flags, long unsigned number, char token)
{
	int	count;

	count = 0;
	if (flags->hashtag)
	{
		if (number != 0)
			count += ft_putchar('0') + ft_putchar(token);
	}
	count += print_hex_precision(number, flags->precision, token);
	while (flags->width > count)
		count += ft_putchar(' ');
	return (count);
}

int	print_hex_width(t_flags *flags, long number, char flag, char token)
{
	int	count;
	int	parameter;

	count = ft_hexsize(number);
	parameter = ft_hexsize(number);
	if (flags->precision > count)
		count = flags->precision;
	if (flags->hashtag)
		count += 2;
	while (flags->width > count)
		count += ft_putchar(flag);
	count += print_hashtag(number, flags->hashtag, token);
	if (flags->precision > parameter)
		count += print_hex_precision(number, flags->precision, token);
	return (count);
}

int	print_hashtag(long unsigned number, int hashtag, char token)
{
	int	count;

	count = 0;
	if (number != 0 && hashtag)
		count += ft_putchar('0') + ft_putchar(token);
	return (count);
}

int	print_hex_precision(long unsigned number, int precision, char token)
{
	int	count;
	int	parameter;

	count = 0;
	parameter = ft_hexsize(number);
	if (number == 0 && precision == 0)
		return (0);
	while (precision > parameter)
		count += ft_putchar('0');
	if (ft_isupper(token))
		count += ft_putnbr_base(number, HEXBASEUP);
	else
		count += ft_putnbr_base(number, HEXBASE);
	return (count);
}
