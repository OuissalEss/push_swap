# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 06:58:42 by oessamdi          #+#    #+#              #
#    Updated: 2022/05/10 21:43:44 by oessamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

SRC = push_swap.c lstfonctions.c arrayfonctions.c ft_atoi.c push.c quick_sort.c \
	rotatea.c rotateb.c rotate.c sort_two_three.c sort_four.c sort_five.c swap.c \
	stackfonctions.c sort_big_stack.c rb_rrb.c

CC = @gcc $(SRC) 

CFLAGS = -Wall -Wextra -Werror

DEBUG = -fsanitize=address -g

OBJC = $(SRC:.c=.o)

RM = @rm -f

$(NAME) :
			$(CC) -o $(NAME)

all : $(NAME)

debug :
	gcc $(CFLAGS) $(DEBUG) $(SRC) -o $(NAME)

clean :

fclean :
			$(RM) $(NAME)

re : fclean all

.PHONY:	all clean fclean re