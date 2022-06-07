# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 19:19:48 by iwhana            #+#    #+#              #
#    Updated: 2022/02/10 17:31:48 by iwhana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_atoi.c arr.c push_and_swap.c rotate_stack.c sort_all.c sort_max_1.c sort_max_2.c create_stack.c push_swap.c

OBJ = $(SRC:.c=.o)

HDRS = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME) : $(HDRS) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all
 
.PHONY: all clean fclean
