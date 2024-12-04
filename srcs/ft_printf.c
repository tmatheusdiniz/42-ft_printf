/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:29:15 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/18 20:40:46 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	formats(const char *string, size_t *i, va_list args, t_flags *flags)
{
	while (ft_memchr(FLAGS, string[*i], 6) || ft_isdigit(string[*i]))
		flags = flags_handler(string, i, flags);
	if (string[*i] == 's')
		return (string_handler(args, flags));
	else if (string[*i] == 'c')
		return (char_handler(args, flags));
	else if (string[*i] == 'i' || string[*i] == 'd')
		return (integer_handler(args, flags));
	else if (string[*i] == 'u')
		return (unsignedint_handler(args, flags));
	else if (string[*i] == 'p')
		return (pointer_handler(args, flags));
	else if (string[*i] == '%')
		return (percentage_handler(flags));
	else if (string[*i] == 'x' && ft_isupper(string[*i]))
		return (hexdecimal_handler(args, flags, 1));
	else if (string[*i] == 'x')
		return (hexdecimal_handler(args, flags, 0));
	free(flags);
	return (0);
}

int	ft_printf(const char *string, ...)
{
	int		count;
	size_t	i;
	t_flags	*flags;
	va_list	args;

	if (string[0] == '%')
		return (-1);
	i = 0;
	count = 0;
	flags = NULL;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i ++;
			count += formats(string, &i, args, flags);
		}
		else
			count += ft_putchar(string[i++]);
	}
	if (flags)
		free(flags);
	va_end(args);
	return (count);
}
