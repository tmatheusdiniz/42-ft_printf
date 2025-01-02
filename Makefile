# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 21:29:32 by mreinald          #+#    #+#              #
#    Updated: 2024/11/27 23:47:58 by mreinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DARK_BLUE = $(shell printf "\33[38;5;18m")
LIGHT_BLUE = $(shell printf "\33[38;5;39m")
YELLOW = $(shell printf "\33[38;5;226m")
WHITE = $(shell printf "\33[38;5;15m")
RESET = $(shell printf "\33[0m")

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = 	srcs/char_handler.c \
		srcs/ft_printf.c \
		srcs/ft_printf_flags.c \
		srcs/ft_printf_utils.c \
		srcs/ft_printf_utils_int.c \
		srcs/ft_printf_utils_unsig.c \
		srcs/hexdecimal_handler.c \
		srcs/integer_handler.c \
		srcs/percentage_handler.c \
		srcs/pointer_handler.c \
		srcs/string_handler.c \
		srcs/unsignedint_handler.c

INCLUDE = include
OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft/libft.a

all: $(LIBFT) intro $(NAME)

$(LIBFT):
	@echo "$(LIGHT_BLUE)Compiling libft...$(RESET)"
	@$(MAKE) --silent -C ./Libft
	@echo "$(LIGHT_BLUE)libft compiled and linked.$(RESET)"

intro:
	@if [ ! -f $(NAME) ] || [ $(LIBFT) -nt $(NAME) ]; then \
		echo "$(DARK_BLUE)"; \
		echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"; \
		echo "███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗"; \
		echo "██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝"; \
		echo "█████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  "; \
		echo "██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  "; \
		echo "██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     "; \
		echo "╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     "; \
		echo "$(RESET)"; \
		echo "$(YELLOW)Starting the ft_printf compilation...$(RESET)"; \
	else \
		echo "$(WHITE)$(NAME) is up-to-date!$(RESET)"; \
	fi

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(WHITE)✅ $(NAME) created successfully!$(RESET)"

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@
	@sleep 0.02

clean:
	@echo "$(DARK_BLUE)🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make --silent -C ./Libft clean
	@echo "$(DARK_BLUE)Object files cleaned!$(RESET)"
	@rm -f .compiled

fclean: clean
	@rm -f $(NAME)
	@make --silent -C ./Libft fclean
	@clear
	@echo "$(DARK_BLUE)Full cleanup complete!$(RESET)"

re: fclean all

bonus: all

.PHONY: all intro clean fclean bonus re

