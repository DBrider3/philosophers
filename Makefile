# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 15:58:55 by dcho              #+#    #+#              #
#    Updated: 2021/09/11 20:38:46 by dcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# CFLAGS = -I ./includes -I ./libft
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I ./include

RM = rm -f

NAME = philo

SRC =	free.c\
		init.c\
		main.c\
		mutex.c\
		philo_main.c\
		philo_utils.c\
		print.c\
		scan.c\
		sleep.c\
		time.c


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
