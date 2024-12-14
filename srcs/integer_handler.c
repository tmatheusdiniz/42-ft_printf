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
	if (flags->left_aligment && flags->precision)
		count += print_int_left_pp(number, flags->precision,
				flags->width, flags->sign_plus);
	else if (flags->left_aligment && flags->width > 0)
		count += print_int_left_pp(number, flags->precision,
				flags->width, flags->sign_plus);
	else if (flags->precision && !flags->width)
		count += print_int_p(number, flags->precision, flags->spce, flags->sign_plus);
	else if (flags->precision && flags->width)
		count += print_aux_w(number, flags, ft_numsize(number), ' ');
	else if (flags->width && !)
	else if (flags->zero)
		count += print_zero(number,
				flags->width, TRUE, flags->sign_plus);
	else
		count += ft_putstr(ft_itoa(number));
	return (count);
}

int	print_int_p(int number, int precision, int space, int sign_plus)
{
	int		count;
	int		size_number;
	char	*number_to_char;

	count = 0;
	size_number = ft_numsize(number);
	number_to_char = ft_itoa(number);
	if (sign_plus && number > 0 && !space)
		count += ft_putchar('+');
	else if (space && !sign_plus)
		count += ft_putchar(' ');
	if (precision > size_number)
	{
		while (precision-- > size_number)
			count = ft_putchar('0');
		count += ft_putstr(number_to_char);
	}
	else
		count += ft_putstr(number_to_char);
	return (free(number_to_char), count);
}

int	print_zero(int number, t_flags *flags)
{
	int		count;
	int		size_number;
	char	*number_to_char;

	count = 0;
	number_to_char = ft_itoa(number);
	size_number = ft_numsize(number);
	if (size_number >= flags->width)
	{
		if (flags->sign_plus && number > 0)
			count += ft_putchar('+');
		count += ft_putstr(number_to_char);
	}
	else
	{
		if (flags->zero && (!flags->sign_plus || number < 0))
			count += print_aux_w(width, size_number, FALSE, '0');
		else if (zero && sign_plus && number > 0)
			count += print_aux_w(width - 1, size_number, TRUE, '0');
		else if (sign_plus && number > 0)
			count += print_aux_w(width - 1, size_number, TRUE, ' ');
		while (size_number-- > 0)
			count = ft_putchar(number_to_char[count++]);
	}
	return (free(number_to_char), count);
}

int	print_w(int number, t_flags *flags, int sign_plus, char zero_or_space)
{
	int	count;
	int	size_number;

	count = 0;
	if (flags->precision || flags->left_aligment)
		return (print_aux_w(number, flags, ft_numsize(number)));
	// i need to create two funcitons for return the value, which can be 1 or 0 to sign_plus and zero_or_space
	else
	{
		if (sign_plus && zero_or_space != '0')
			count += ft_putchar('+');
		while (flags->width-- > size_number)
			count += ft_putchar(zero_or_space);
		if (sign_plus && zero_or_space == ' ')
			count += ft_putchar('+');
	}
	return (count);
}

int	print_int_left_pp(int number, t_flags *flags)
{
	int		count;
	int		size_number;
	int		aux;
	char	*number_to_char;

	count = 0;
	number_to_char = ft_itoa(number);
	size_number = ft_numsize(number);
	aux = size_number;
	if (flags->precision > flags->width)
		count += print_int_p(number, flags->precision, FALSE, flags->sign_plus);
	else if (flags->precision && !flags->width)
		print_int_p(number, flags->precision, flags->space, flags->sign_plus);
	else if (flags->precision && flags->width)
		print_w(number, flags, 0, ' ');
	else
	{
		if (flags->sign_plus && number > 0)
			count += ft_putchar('+');
		count += ft_putstr(number_to_char);
		while (flags->width -- > size_number)
			ft_putchar(' ');
		// or i can call the function print_w to print the space or zero. So, in this case, i would to exclude the lines above.
	}
	return (free(number_to_char), count);
}
