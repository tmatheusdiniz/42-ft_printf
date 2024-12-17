/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:14:42 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/14 18:15:12 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_aux_w(int number, t_flags *flags, int size_number)
{
	int	count;

	count = 0;
	if (flags->left_aligment && flags->precision && flags->width > 0)
	{
		count += print_int_p(number, flags->precision,
				flags->space, flags->sign_plus);
		while (flags->width > count)
			count += ft_putchar(' ');
	}
	else if (flags->width && flags->precision && !flags->left_aligment)
	{
		if (flags->precision > size_number)
			size_number = flags->precision;
		if (flags->sign_plus || flags->space)
			flags->width --;
		while (flags->width-- > size_number)
			count += ft_putchar(' ');
		count += print_int_p(number, flags->precision,
				flags->space, flags->sign_plus);
	}
	return (count);
}

int	aux_zero(int number, int width)
{
	int	count;
	int	size_number;

	count = 0;
	size_number = ft_numsize(number);
	while (width-- > size_number)
		count += ft_putchar('0');
	count += ft_putnbr(number);
	return (count);
}

int	aux_z_plus(int number, int width, int sign_plus)
{
	int	count;
	int	size_number;

	count = 0;
	size_number = ft_numsize(number);
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
		sign_plus = FALSE;
	}
	if (sign_plus && number >= 0)
		count += ft_putchar('+');
	while (width-- > size_number)
		count += ft_putchar('0');
	count += ft_putnbr(number);
	return (count);
}

int	aux_z_space(int number, int width, int space)
{
	int	count;
	int	size_number;

	count = 0;
	size_number = ft_numsize(number);
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
		space = FALSE;
	}
	if (space && number >= 0)
		count += ft_putchar(' ');
	while (width-- > size_number)
		count += ft_putchar('0');
	count += ft_putnbr(number);
	return (count);
}
