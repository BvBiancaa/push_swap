# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bianca <bianca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 18:34:44 by bmuni             #+#    #+#              #
#    Updated: 2023/06/19 20:15:39 by bianca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

all: $(NAME)

bonus: checker

$(NAME):
	make -C libftprintf
	gcc  -g -Wall -Wextra -Werror moonie.c minlis.c fly.c checker_moves_two.c norm.c sort_pino_split.c utils.c check_rep.c main.c move_set_one.c move_set_five.c  move_set_two.c move_set_three.c move_set_four.c push_swap.c push_utils.c utils_main.c utilsutils.c findus.c sort_pino.c libftprintf/libftprintf.a -o $(NAME)
	@clear
	@echo "\033[0;32m push_swap is ready \033[0m"

checker:
	make -C libftprintf
	gcc -g checker.c checker_moves.c checker_moves_one.c checker_moves_two.c libftprintf/libftprintf.a -o checker
	#@clear
	@echo "\033[0;32m checker is ready \033[0m" 

clean:
	make -C libftprintf clean

fclean: clean
	make -C libftprintf fclean
	rm -f push_swap checker

re: fclean all

.PHONY: all, bonus, clean, fclean, re
