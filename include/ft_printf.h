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
# define HEXBASEUP "0123456789ABCDEF"
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
int		percentage_handler(void);
int		hexdecimal_handler(va_list args, t_flags *flags, char token);

// Aux String function
int		print_w_p(char *string, int width, int precision, int left_aligment);
int		print_p(char *string, int precision);
int		print_w(char *sring, int width);

// Aux Integer function
int		print_int_left_pp(int number, t_flags *flags);
int		print_int_p(int number, int precision, int space, int sign_plus);
int		print_zero(int number, int size_number, t_flags *flags);
int		print_w_int(int number, t_flags *flags);

//Aux Unsigned Int function
int		unsignedint_leftalig(long int number, int numbersize, t_flags *flags);
int		unsignedint_prec(long int number, int precision);
int		unsignedint_w(long int number, int numbersize, t_flags *flags);
int		unsignedint_w_l(long int number, int numbersize, t_flags *flags);

//Aux Pointer function
int		print_width(int width, int left_aligment,
			int size_address, size_t number);
int		print_null(int left_aligment, int width);

//Aux Hexdecimal function
int		print_hex_leftalig(t_flags *flags, long unsigned number, char token);
int		print_hex_precision(long unsigned number, int precision, char token);
int		print_hex_width(t_flags *flags, long number, char flag, char token);
int		print_hashtag(long unsigned number, int hashtag, char token);

// Flags
t_flags	*initialization_flags(void);
t_flags	*flags_handler(const char *string, size_t *i, t_flags *flags);

// Utils
int		ft_numsize(long long n);
int		ft_numsize_unsig(unsigned int n);
int		ft_hexsize(size_t n);
int		ft_putnbr(long long n);
int		ft_putnbr_unsig(unsigned int n);
int		ft_putnbr_base(unsigned long long n, char *base);
int		print_aux_w(int number, t_flags *flags, int size_number);
int		aux_zero(int number, int width);
int		aux_z_plus(int size_number, int width, int sign_plus);
int		aux_z_space(int size_number, int width, int space);

#endif
