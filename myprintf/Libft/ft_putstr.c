/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:10:47 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/25 16:16:39 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char	*s)
{
	int	written;

	if (!s)
		return (write(1, "(null)", 6));
	written = write(STDOUT_FILENO, s, ft_strlen(s));
	if (written == -1)
		return (-1);
	else
		return (written);
}
