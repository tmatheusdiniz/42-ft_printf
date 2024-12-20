# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 22:38:40 by mreinald          #+#    #+#              #
#    Updated: 2024/11/10 00:41:56 by mreinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

stdio_h = ft_putchar.c

stdlib_h = ft_atoi.c ft_strdup.c ft_calloc.c

string_h = ft_strlen.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c

strings_h = ft_bzero.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c

ctype_h = ft_isalnum.c ft_isascii.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isupper.c ft_islower.c

non_stardad = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_substr.c ft_strtrim.c ft_strjoin.c ft_split.c ft_strmapi.c ft_striteri.c ft_putstr.c

linked_list = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC = ${stdio_h} ${stdlib_h} ${string_h} ${strings_h} ${ctype_h} ${non_stardad}

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${linked_list:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I

.o:.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	ar rcs ${NAME} ${OBJS}

all:	${NAME}

bonus :	${OBJS} ${OBJS_BONUS}
	@ar rcs ${NAME} $^

clean :
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
