/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:56:46 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/18 14:13:55 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../Libft/libft.h"

# define HEXBASE "0123456789abcdef"
# define TYPES "%cspdiuxX\0"
# define FLAGS "-0.# +"

# define TRUE 1
# define FALSE 0

typedef struct s_flags
{
	int	sign_plus;
	int	left_aligment;
	int	zero;
	int	width;
	int	dot;
	int	precision;
	int	hashtag;
	int	space;
}		t_flags;

// The main
int		ft_printf(const char *string, ...);
int		ft_formats(char *string, size_t *i, va_list args, t_flags *flags);

// to_conversions
int		string_handler(va_list args, t_flags *flags);
int		char_handler(va_list args, t_flags *flags);
int		integer_handler(va_list args, t_flags *flags);
int		unsignedint_handler(va_list args, t_flags *flags);
int		pointer_handler(va_list args, t_flags *flags);
int		percentage_handler(t_flags *flags);
int		hexdecimal_handler(va_list args, t_flags *flags, int token);

// Aux String function
int	print_w_p(char *string, int width, int precision, int left_aligment);
int	print_p(char *string, int precision);
int	print_w(char *sring, int width);

// Aux Integer function
int	print_int_left_pp(int number, int precision, int width, int plus);
int	print_int_p(int number, int precision, int space, int sign_plus);
int	print_zero(int number, int width, int zero, int sign_plus);
int	print_aux_w(int width, int size_number, int sign_plus, char zero_or_space);
int	print_int_left_pp(int number, int precision, int width, int sign_plus);

//Aux Pointer function
int	print_width(int width, int left_aligment, int size_address, size_t number);
int	print_null(int left_aligment, int width);

// Flags
t_flags	*initialization_flags(void);
t_flags	*flags_handler(const char *string, size_t *i, t_flags *flags);

// Utils
int		ft_numsize(long long n);
int		ft_putnbr_base(unsigned long long n, char *base);

#endif
