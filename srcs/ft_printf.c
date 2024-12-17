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
	char	c;

	while (ft_memchr(FLAGS, string[*i], 6) || ft_isdigit(string[*i]))
		flags = flags_handler(string, i, flags);
	if (string[*i] == 's')
		return ((*i)++, string_handler(args, flags));
	else if (string[*i] == 'c')
		return ((*i)++, char_handler(args, flags));
	else if (string[*i] == 'i' || string[*i] == 'd')
		return ((*i)++, integer_handler(args, flags));
	else if (string[*i] == 'u')
		return ((*i)++, unsignedint_handler(args, flags));
	else if (string[*i] == 'p')
		return ((*i)++, pointer_handler(args, flags));
	else if (string[*i] == '%')
		return ((*i)++, percentage_handler());
	else if (string[*i] == 'x' || string[*i] == 'X')
	{
		c = string[*i];
		return ((*i)++, hexdecimal_handler(args, flags, c));
	}
	return (0);
}

int	ft_printf(const char *string, ...)
{
	int		count;
	size_t	i;
	t_flags	flags;
	va_list	args;

	if (!string || (string[0] == '%' && string[1] == '\0'))
		return (-1);
	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i])
	{
		ft_bzero(&flags, sizeof(t_flags));
		if (string[i] == '%')
		{
			i ++;
			count += formats(string, &i, args, &flags);
		}
		else
			count += ft_putchar(string[i++]);
	}
	va_end(args);
	return (count);
}
