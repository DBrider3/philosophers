# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 15:58:55 by dcho              #+#    #+#              #
#    Updated: 2021/08/31 21:36:26 by dcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# CFLAGS = -I ./includes -I ./libft
CFLAGS = -Wall -Wextra -Werror -I ./include

RM = rm -f

NAME = philo

SRC =	main.c			\
		scan.c			\
		init.c			\
		free.c			\
		time.c			\
		philo_main.c	\
		philo_utils.c	\


SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $^ \
		-o $@

%.o : $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
