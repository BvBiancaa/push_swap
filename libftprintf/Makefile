# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bianca <bianca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 19:14:06 by bmuni             #+#    #+#              #
#    Updated: 2023/06/21 10:11:20 by bianca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

all: $(NAME)

$(NAME):
	make bonus -C libft
	make bonus -C get_next_line
	gcc -Wall -Wextra -Werror -c ft_printf.c ft_printf_nbr.c
	ar -rc $(NAME) *.o libft/*.o get_next_line/*.o
	ranlib $(NAME)

clean:
	rm -f *.o
	rm -f libft/*.o
	rm -f get_next_line/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	rm -f get_next_line/getnextline.a

re: fclean all

.PHONY: all, clean, fclean, re
