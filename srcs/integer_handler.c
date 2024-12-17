/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:22:05 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/30 13:01:56 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	integer_handler(va_list args, t_flags *flags)
{
	int			count;
	long int	number;

	count = 0;
	number = va_arg(args, int);
	if (flags->left_aligment)
		count += print_int_left_pp(number, flags);
	else if (flags->precision && !flags->width)
		count += print_int_p(number, flags->precision,
				flags->space, flags->sign_plus);
	else if (flags->precision && flags->width)
		count += print_w_int(number, flags);
	else if (flags->width > 0 && !flags->precision)
		count += print_w_int(number, flags);
	else if (flags->zero)
		count += print_zero(number,ft_numsize(number), flags);
	else
		count += ft_putstr(ft_itoa(number));
	return (count);
}

int	print_int_p(int number, int precision, int space, int sign_plus)
{
	int		count;	
	int		size_number;

	count = 0;
	size_number = ft_numsize(number);
	if (sign_plus && number >= 0 && !space)
		count += ft_putchar('+');
	else if (space && !sign_plus && number >= 0)
		count += ft_putchar(' ');
	if (precision > size_number)
	{
		if (number < 0)
		{
			count += ft_putchar('-');
			number = -number;
			size_number++;
		}
		while (precision-- > size_number)
			count += ft_putchar('0');
		count += ft_putnbr(number);
	}
	else
		count += ft_putnbr(number);
	return (count);
}

int	print_zero(int number, int size_number, t_flags *flags)
{
	int	count;
	
	count = 0;
	if (size_number >= flags->width)
	{
		if (flags->sign_plus && number >= 0)
			count += ft_putchar('+');
		count += ft_putnbr(number);
	}
	else
	{
		if (flags->zero && flags->space && number >= 0 && !flags->sign_plus)
			count += aux_z_space(number, flags->width - 1, TRUE);
		else if (flags->zero && flags->space && (number < 0 || flags->sign_plus))
			count += aux_z_space(number, flags->width, FALSE);
		else if (flags->zero && (!flags->sign_plus || number < 0))
			count += aux_z_plus(number, flags->width, FALSE);
		else if (flags->zero && flags->sign_plus && number >= 0)
			count += aux_z_plus(number, flags->width - 1, TRUE);
		else
			count += aux_zero(number, flags->width);
	}
	return (count);
}

int	print_w_int(int number, t_flags *flags)
{
	int	count;
	int	size_number;

	count = 0;
	size_number = ft_numsize(number);
	if (flags->precision || flags->left_aligment)
		return (print_aux_w(number, flags, ft_numsize(number)));
	else if (flags->width > 0 && flags->zero)
		count += print_zero(number, ft_numsize(number), flags);
	else
	{
		if (flags->sign_plus || flags->space)
			flags->width --;
		while (flags->width -- > size_number)
			count += ft_putchar(' ');
		if (flags->sign_plus && number >= 0)
			count += ft_putchar('+');
		else if (flags->space && number >= 0)
			count += ft_putchar(' ');
		count += ft_putnbr(number);
	}
	return (count);
}

int	print_int_left_pp(int number, t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->precision > flags->width || (flags->precision && !flags->width))
		count += print_int_p(number, flags->precision,
				flags->space, flags->sign_plus);
	else if (flags->precision && flags->width)
		count += print_w_int(number, flags);
	else if (flags->width > 0 && !flags->precision)
	{
		if (flags->sign_plus && number > 0)
			count += ft_putchar('+');
		if (flags->space)
			count += ft_putchar(' ');
		count += ft_putnbr(number);
		while (flags->width > count)
			count += ft_putchar(' ');
	}
	else
		count += ft_putnbr(number);
	return (count);
}
