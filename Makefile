#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 10:05:14 by jpfeffer          #+#    #+#              #
#    Updated: 2017/04/19 12:18:15 by jpfeffer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

PUSH_SWAP = push_swap

CHECKER = checker

C_FILES = push_and_swap.c rotate.c rrotate.c validation.c op_handler_1.c \
op_handler_2.c op_handler_3.c handle_string.c min_max.c indices.c debugger.c \
solve.c calc_sort.c sort.c options.c stats.c

LIBFT		=	./libft/libft.a
PRINTF		=	./libraries/ft_printf/libftprintf.a
GNL			=	./libraries/get_next_line/libgnl.a
LIBLINK		=	-L ./libraries -lpushswap
LIBRARY		=	./libraries/libpushswap.a
SRCS		=	$(C_FILES) $(GNL_SRCS)
HEADER		=	push_swap.h

C_FLAGS = -Wall -Werror -Wextra

.PHONY: all library libft printf gnl test clean fclean re

all: library $(PUSH_SWAP) $(CHECKER)

library: libft printf gnl $(LIBRARY)

$(LIBRARY):
	@libtool -static -o $(LIBRARY) $(LIBFT) $(PRINTF) $(GNL)

libft: $(LIBFT)

$(LIBFT):
	@make -C ./libft

printf: $(PRINTF)

$(PRINTF):
	@make -C ./libraries/ft_printf

gnl: $(GNL)

$(GNL):
	@make -C ./libraries/get_next_line

$(PUSH_SWAP): $(SRCS) $(HEADER) push_swap.c
	@gcc $(C_FLAGS) $(LIBLINK) $(SRCS) push_swap.c -o push_swap

$(CHECKER): $(SRCS) $(HEADER) checker.c
	@gcc $(C_FLAGS) $(LIBLINK) $(SRCS) checker.c -o checker

test: fclean library
	@gcc $(SRCS) $(LIBLINK) push_swap.c -o push_swap
	@gcc $(SRCS) $(LIBLINK) checker.c -o checker

clean:
	@make clean -C ./libft
	@make clean -C ./libraries/ft_printf
	@make clean -C ./libraries/get_next_line

fclean: clean
	@rm -f $(PUSH_SWAP) $(CHECKER) $(LIBRARY) a.out test
	@make fclean -C ./libft
	@make fclean -C ./libraries/ft_printf
	@make fclean -C ./libraries/get_next_line

re: fclean all