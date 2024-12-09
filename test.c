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
	int	integer = -42;
	int integer2 = -3;
	char c = 'c';
	char *test = "Hello World!";	
	int	result;
	int	result2;

	//Tests for char
	
	ft_printf("----------Char----------\n");
	result = ft_printf("result for char : %c\n", c);
	result2 = printf("origin function : %c\n", c);
	ft_printf("number for char : %i\n", result);
	printf("count origin function : %i\n", result2);

	//Tests for string
	
	ft_printf("----------String----------\n");
	result = ft_printf("result for string : %s\n", test);
	ft_printf("number for string : %i\n", result);

	//Tests for pointer
	
	ft_printf("----------Pointer----------\n");
	result = ft_printf("result for pointer : %p\n", test);
	result2 = printf("origin function : %p\n", test);
	ft_printf("count for pointer : %i\n", result);
	printf("count origin function : %i\n", result2);

	//Tests for integer
	
	ft_printf("----------Integer----------\n");
	ft_printf("result : %i\n", integer);
	result = ft_printf("result for integer : Hello World, i have %i years\n", integer);
	ft_printf("number for integer : %i\n", result);

	//Tests for Unsigned int
	
	ft_printf("----------Unsigned Int----------\n");
	ft_printf("result for unsigned int : %u\n", integer2);
	printf("result for unsigned int origin : %u\n", integer2);

	//Tests for Hexadecimal
	
	ft_printf("----------Hexdecimal----------\n");
	result = ft_printf("result for hexdecimal : |%#-14X|\n", integer);
	result2 = printf("result for hexdecimal origin : |%#-14.2X|\n", integer);
	printf("count myfunction : %i\n", result);
	printf("count for origin function : %i\n", result2);
 }
