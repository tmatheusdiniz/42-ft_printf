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

#include "../include/ft_libft.h"

static int	is_type(char c)
{
	const char	*types;
	
	types = "cspdiuxX%";
	while (*types)
	{
		if (c == *types)
			return (1);
		types ++;
	}
	return (0);
}

int	ft_printf(const char *type, ...)
{
	int	count;
	size_t	i;
	va_list	md;

	i = 0;
	count = 1;
	va_start(md, type);
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1] && is_type(type[i + 1]))
		{

		}	
		else
		{
			ft_putstr_fd((char *)&type[i + 1], STDOUT_FILENO);
			count ++;
		}
		i ++;
	}
	va_end(md);
	return (count);
}

