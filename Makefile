# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:54:02 by ssi-moha          #+#    #+#              #
#    Updated: 2017/12/29 18:20:34 by ssi-moha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = libft/libft.a

INCLUDE = ft_printf.h

CC = gcc

CFLAGS = -Wall -Werror -Werror

SRC = ft_printf.c ft_print_char.c ft_print_int.c ft_print_hex.c\
	  ft_print_oct.c ft_print_string.c type_ret.c ft_init_struct.c\
	  ft_parse.c handle_width.c set_len.c\
	  ft_lltoa.c ft_lltoa_base.c ft_print_uns.c\
	  modif_arguns.c find_type.c get_modif.c ft_define_len.c ft_print_pointer.c\
	  free_option.c ft_ulltoa_base.c ft_ulltoa.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -c $(SRC) -I $(INCLUDE)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
