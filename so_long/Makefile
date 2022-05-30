# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 11:25:56 by mibernar          #+#    #+#              #
#    Updated: 2022/05/30 11:47:13 by mibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c

OBJS = $(SRCS:.c=.o)

CC = gcc -g
RM = rm -rf
CFLAGS = -Werror -Wextra -Wall
PRINTF_DIR = printf

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -L$(PRINTF_DIR) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C $(PRINTF_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(PRINTF_DIR)

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)