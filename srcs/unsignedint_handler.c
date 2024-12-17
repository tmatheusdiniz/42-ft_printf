/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedint_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:58:15 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/08 00:58:47 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

int	unsignedint_handler(va_list args, t_flags *flags)
{
	unsigned int	number;
	int				count;
	int				numbersize;

	number = va_arg(args, unsigned int);
	count = 0;
	numbersize = ft_numsize_unsig(number);
	if (flags->left_aligment)
		count += unsignedint_leftalig(number, numbersize, flags);
	else if (flags->width && flags->width > 0)
		count += unsignedint_w(number, numbersize, flags);
	else if (flags->precision && flags->precision > 0)
		count += unsignedint_prec(number, flags->precision);
	else
		count += ft_putnbr_unsig(number);
	return (count);
}

int	unsignedint_leftalig(long int number, int numbersize, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->width > 0)
		count += unsignedint_w_l(number, numbersize, flags);
	else if (flags->precision > numbersize)
		count += unsignedint_prec(number, flags->precision);
	else
		count += ft_putnbr(number);
	return (count);
}

int	unsignedint_prec(long int number, int precision)
{
	int	count;
	int	numbersize;

	count = 0;
	numbersize = ft_numsize(number);
	if (precision > numbersize)
	{
		while (precision-- > numbersize)
			count += ft_putchar('0');
		count = ft_putnbr(number);
	}
	else
		count += ft_putnbr(number);
	return (count);
}

int	unsignedint_w(long int number, int numbersize, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision > 0 && flags->precision > numbersize)
		numbersize = flags->precision;
	if (flags->zero && !flags->precision)
	{
		while (flags->width-- > numbersize)
			count += ft_putchar('0');
		count += ft_putnbr(number);
	}
	else if (flags->precision)
	{
		while (flags->width-- > numbersize)
			count += ft_putchar(' ');
		count += unsignedint_prec(number, flags->precision);
	}
	else
	{
		while (flags->width-- > numbersize)
			count += ft_putchar(' ');
		count += ft_putnbr(number);
	}
	return (count);
}

int	unsignedint_w_l(long int number, int numbersize, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision > 0 && flags->precision > numbersize)
		numbersize = flags->precision;
	if (flags->zero && !flags->precision)
	{
		count += ft_putnbr(number);
		while (flags->width-- > numbersize)
			count += ft_putchar('0');
	}
	else if (flags->precision)
	{
		count += unsignedint_prec(number, flags->precision);
		while (flags->width-- > numbersize)
			count += ft_putchar(' ');
	}
	else
	{
		count += ft_putnbr(number);
		while (flags->width-- > numbersize)
			count += ft_putchar(' ');
	}
	return (count);
}
