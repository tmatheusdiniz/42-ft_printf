/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:10:51 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/08 23:10:55 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_numsize_unsig(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_putnbr_unsig(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsig(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	aux_unsigned(t_flags *flags)
{
	int	count;

	count = 0;
	if ((flags->left_aligment || flags->width) && flags->precision == 0)
	{
		count += ft_putnbr(0);
		while (flags->width > count)
			count += ft_putchar(' ');
		return (count);
	}
	while (flags->width-- > 0)
		count += ft_putchar(' ');
	return (count);
}
