#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:33:14 by jpfeffer          #+#    #+#              #
#    Updated: 2017/04/19 12:18:15 by jpfeffer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libgnl.a

C_FILES = get_next_line.c

LIBFT		=	../../libft/libft.a
LIBLINK		=	-L ../../libft -lft

CFLAGS = -Wall -Wextra -Werror

LIBFT_SRCS = $(addprefix libft/,$(LIBFT))

SRCS = $(C_FILES)

OBJ = $(C_FILES:.c=.o)

.PHONY: all libft test clean fclean re

all: libft $(NAME)

libft: $(LIBFT)

$(LIBFT):
	@make -C ../../libft

$(NAME):
	@gcc $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

test: fclean
	@gcc $(SRCS) main.c

clean:
	@rm -f $(OBJ) main.o
	@make clean -C ../../libft

fclean: clean
	@rm -f $(NAME) a.out
	@make fclean -C ../../libft

re: fclean all