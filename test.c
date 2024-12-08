/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:37:41 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/28 00:38:21 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	main(void)
{
	int	year = 25;
	char c = 'c';
	char *test = "Hello World!";	
	int	result;

	//Tests for char
	
	ft_printf("----------Char----------\n");
	result = ft_printf("result for char: %c\n", c);
	ft_printf("number for char : %i\n", result);
	
	//Tests for string
	
	ft_printf("----------String----------\n");
	result = ft_printf("result for string : %s\n", test);
	ft_printf("number for string : %i\n", result);

	//Tests for pointer
	
	//ft_printf("----------Pointer----------");
	//result = ft_printf("result for pointer : %p\n", test);
	//ft_printf("number for pointer : %i\n", result);

	//Tests for integer
	
	ft_printf("----------Integer----------\n");
	result = ft_printf("result for integer : Hello World, i have %i years\n", year);
	ft_printf("number for integer : %i\n", result);

 }
