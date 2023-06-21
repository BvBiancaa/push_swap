# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmuni <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:08:40 by bmuni             #+#    #+#              #
#    Updated: 2022/11/06 12:33:19 by bmuni            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
OUTPUT=*.o

SRC=ft_atoi.c	\
    ft_checkchar.c	\
    ft_bzero.c	\
    ft_calloc.c	\
    ft_isalnum.c	\
    ft_isalpha.c	\
    ft_isascii.c	\
    ft_isdigit.c	\
    ft_isprint.c	\
    ft_itoa.c	\
    ft_memchr.c	\
    ft_memcmp.c	\
    ft_memcpy.c	\
    ft_memmove.c	\
    ft_memset.c	\
    ft_split.c	\
    ft_strchr.c	\
    ft_strdup.c	\
    ft_strjoin.c	\
    ft_strlcat.c	\
    ft_strlcpy.c	\
    ft_strlen.c	\
    ft_strncmp.c	\
    ft_strnstr.c	\
    ft_strrchr.c	\
    ft_strtrim.c	\
    ft_substr.c	\
    ft_tolower.c	\
    ft_toupper.c	\
    ft_potenza.c	\
    ft_nbrlen.c	\
    ft_strmapi.c	\
    ft_striteri.c	\
    ft_putchar_fd.c	\
    ft_putstr_fd.c	\
    ft_putendl_fd.c	\
    ft_putnbr_fd.c	\

SRCB=ft_lstnew.c	\
    ft_lstadd_back.c	\
    ft_lstadd_front.c	\
    ft_lstsize.c	\
    ft_lstlast.c	\
    ft_lstdelone.c	\
    ft_lstclear.c	\
    ft_lstiter.c	\
    ft_lstmap.c	\

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

bonus:
	gcc -Wall -Wextra -Werror -c $(SRC) $(SRCB)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re 
