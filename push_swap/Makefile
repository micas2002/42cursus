# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:11:00 by mibernar          #+#    #+#              #
#    Updated: 2022/03/31 12:37:34 by mibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c error_check.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Werror -Wextra -Wall
LIBFT_DIR = libft
PRINTF_DIR = printf

NAME = pushswap.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INC)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
