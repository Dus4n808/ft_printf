# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 17:31:30 by dufama            #+#    #+#              #
#    Updated: 2025/10/07 16:31:41 by dufama           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTILS = utils/printf_utils.c

SRCS = ft_printf.c $(UTILS)

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc

AR = ar

ARFLAGS = rcs

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) -$(ARFLAGS) $(NAME) $(OBJS)

bonus:	$(OBJS)
		$(AR) -$(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o test
	./test

# test_bonus: bonus main.c
# 	$(CC) $(CFLAGS) main.c -L. -lft -o test
# 	./test

.PHONY: all clean fclean re bonus
