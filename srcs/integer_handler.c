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
	if (flags->left_aligment && flags->precision && flags->sign_plus)
		return (print_int_l_pp(number, flags->precision, flags->width, 1));
	else if (flags->left_aligment && flags-> precision)
		return ((print_int_l_pp(number, flags->precision, flags->width, 0)));
	else if ()
}

int	print_int_p(int number, int precision, )
{

}

int	print_int_l_pp(int number, int precision, int width, int sign_plus)
{
	int		count;
	int		size_number;
	char	*number_to_char;

	count = 0;
	number_to_char = ft_itoa(number);
	size_number = ft_numsize(number);
	if (size_number >= precision)
		size_number = precision;
	if (sign_plus && number > 0)
		count += ft_putchar('+');
	if (width > size_number)
	{
		while (size_number-- > 0)
			count = ft_putchar(number_to_char[count++]);
		while (width > size_number)
			count = ft_putchar(number_to_char[count++]);
	}
	else
	{
		while (size_number-- > 0)
			count += ft_putchar(*number_to_char++);
	}
	return (count);
}
