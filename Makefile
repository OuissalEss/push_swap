# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 06:58:42 by oessamdi          #+#    #+#              #
#    Updated: 2022/05/11 01:10:10 by oessamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

SRC_PUSH_SWAP = push_swap.c lstfonctions.c arrayfonctions.c Libft.c push.c quick_sort.c \
	rotatea.c rotateb.c rotate.c sort_two_three.c sort_four.c sort_five.c swap.c \
	stackfonctions.c sort_big_stack.c rb_rrb.c

SRC_CHECKER = checker.c lstfonctions.c arrayfonctions.c Libft.c push.c quick_sort.c \
	rotatea.c rotateb.c rotate.c sort_two_three.c sort_four.c sort_five.c swap.c \
	stackfonctions.c sort_big_stack.c rb_rrb.c get_next_line.c get_next_line_utils.c
	
CC = gcc 

CFLAGS = -Wall -Wextra -Werror

DEBUG = -fsanitize=address -g

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

RM = @rm -f

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(OBJ_PUSH_SWAP) 
		@$(CC) $(CFLAGS) $(OBJ_PUSH_SWAP) -o $(PUSH_SWAP)
		@echo "\033[1;32mPUSH_SWAP CREATED!"

$(CHECKER) : $(OBJ_CHECKER)
		@$(CC) $(CFLAGS) $(OBJ_CHECKER) -o $(CHECKER)
		@echo "\033[1;32mCHECKER CREATED!"

.c.o :
		@$(CC) $(CFLAG) -c $<

clean :
	$(RM) *.o
	@echo "Removed all the .o files"

fclean :
	$(RM) *.o
	$(RM) $(PUSH_SWAP) $(CHECKER)
	@echo "Removed all executbles"

re : fclean all

.PHONY:	all clean fclean re