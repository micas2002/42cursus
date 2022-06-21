# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguel <miguel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 11:25:56 by mibernar          #+#    #+#              #
#    Updated: 2022/06/21 15:06:16 by miguel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c vars_utils.c img_utils.c 

OBJS = $(SRCS:.c=.o)

CC = gcc -g
RM = rm -rf
CFLAGS = -Werror -Wextra -Wall
PRINTF_DIR = printf
LIBFT_DIR = libft

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	make -C $(LIBFT_DIR)
#	mac
#	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#	linux
	gcc -I minilibx-linux/ *.c -L minilibx-linux/ -lmlx_Linux -lXext -lX11 && ./a.out

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
