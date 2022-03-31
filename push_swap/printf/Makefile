# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 13:33:51 by mibernar          #+#    #+#              #
#    Updated: 2022/03/31 12:36:11 by mibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_i.c ft_printf_p.c \
		ft_printf_s.c ft_printf_u.c ft_printf_x_lower.c ft_printf_x_upper.c \
		ft_unsigned_itoa.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Werror -Wextra -Wall
LIBFT_DIR = libft

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INC)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean all
