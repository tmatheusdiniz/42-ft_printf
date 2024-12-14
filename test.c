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
	int	integer = 42;
	int integer2 = -3;
	int	integer3 = 0;
	int	result;
	int	result2;
	char c = 'd';
	char *string = "Hello World!";

	//Tests for char
	
	ft_printf("----------Char----------\n");
	result = ft_printf("result for char : %c\n", c);
	result2 = printf("origin function : |%c|\n", c);
	result = ft_printf("result for char : |%5c|\n", c);
	result2 = printf("result for char origin : |%5c|\n", c);
	result = ft_printf("result for char : |%-5c|\n", c);
	result2 = printf("result for char origin : |%-5c|\n", c);
	printf("result for char with zero |%05c|\n", c);
	ft_printf("number for char : %i\n", result);
	
	printf("count origin function : %i\n", result2);

	//Tests for string
	
	ft_printf("----------String----------\n");
	result = ft_printf("result for string : %s\n", string);
	result2 = ft_printf("number for string : %i\n", result);
	result = ft_printf("result for string : |%.3s|\n", string);
	result2 = printf("result for string origin : |%.3s|\n", string);
	result = ft_printf("result for string : |%5.3s|\n", string);
	result2 = printf("result for string : |%5.3s|\n", string);
	result = ft_printf("result for string : |%-5.3s|\n", string);
	result2 = printf("result for string : |%-5.3s|\n", string);

	//Tests for pointer
	
	ft_printf("----------Pointer----------\n");
	result = ft_printf("result for pointer : %p\n", string);
	result2 = printf("origin function : %p\n", string);
	result = ft_printf("count for pointer : %i\n", result);
	result2 = printf("count origin function : %i\n", result2);
	result = ft_printf("result for pointer : |%20p|\n", string);
	result2 = printf("result for pointer origin : |%20p|\n", string);
	result = ft_printf("result for pointer : |%-20p|\n", string);
	result = printf("result for pointer origin : |%-20p|\n", string);
	result = ft_printf("result for pointer : |%020p|\n", string);
	result = printf("result for pointer : |%.20p|\n", string);

	//Tests for integer
	
	ft_printf("----------Integer----------\n");
	ft_printf("result : %i\n", integer);
	ft_printf("result for 0 : %i\n", integer3);
	result = ft_printf("number for integer : |%-5i|\n", integer);
	result2 = printf("number for integer origin : |%-5i|\n", integer);
	result = ft_printf("number for integer : |%5i|\n", integer);
	result2 = printf("number for integer origin : |%5i|\n", integer);

	//Tests for Unsigned int
	
	ft_printf("----------Unsigned Int----------\n");
	ft_printf("result for unsigned int : %u\n", integer2);
	ft_printf("result for 0 : %u\n", integer3);
	printf("result for unsigned int origin : %u\n", integer2);

	//Tests for Hexadecimal
	
	ft_printf("----------Hexdecimal----------\n");
	result = ft_printf("result for hexdecimal : |%#-14X|\n", integer);
	result2 = printf("result for hexdecimal origin : |%#-14.2X|\n", integer);
	ft_printf("result for 0 : %#x\n", integer3);
	printf("count myfunction : %i\n", result);
	printf("count for origin function : %i\n", result2);
 }
