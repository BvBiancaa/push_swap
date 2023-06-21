# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmuni <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 12:53:24 by bmuni             #+#    #+#              #
#    Updated: 2022/11/06 13:04:56 by bmuni            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=getnextline.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100 -c get_next_line.c get_next_line_utils.c
	ar -rc $(NAME) *.o
	ranlib $(NAME)

bonus:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100 -c get_next_line_bonus.c get_next_line_utils_bonus.c
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
