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

int	print_aux_int(int number, t_flags *flags, int size_number)
{
	int	count;

	count = 0;
	if (flags->left_aligment && flags->precision && flags->width > 0)
	{
		count += print_int_p(number, flags->precision, flags->space, flags->sign_plus);
		while (flags->width > count)
			count += ft_putchar(' ');
	}
	else if (flags->width && flags->precision && !flags->left_aligment)
	{
		
	}
}
