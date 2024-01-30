# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 16:55:49 by ymassiou          #+#    #+#              #
#    Updated: 2024/01/29 16:09:59 by ymassiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
NAME_BONUS	= checker

SRC = srcs/mandatory/cost.c \
		srcs/mandatory/reverse_rotation.c \
		srcs/mandatory/utils.c \
		srcs/mandatory/ft_parse.c \
		srcs/mandatory/rotation.c \
		srcs/mandatory/utils_2.c \
		srcs/mandatory/utils_3.c \
		srcs/mandatory/place.c \
		srcs/mandatory/sort_n.c \
		srcs/mandatory/push.c \
		srcs/mandatory/stack_manu.c \
		srcs/mandatory/push_swap_main.c \
		srcs/mandatory/swap.c
SRC_BONUS = srcs/bonus/checker_bonus.c \
			srcs/bonus/gnl_utils_bonus.c \
			srcs/bonus/rotation_bonus.c \
			srcs/bonus/utils_2_bonus.c \
			srcs/bonus/ft_parse_bonus.c \
			srcs/bonus/push_bonus.c \
			srcs/bonus/stack_manu_bonus.c \
			srcs/bonus/utils_3_bonus.c \
			srcs/bonus/gnl_bonus.c \
			srcs/bonus/reverse_rotation_bonus.c \
			srcs/bonus/swap_bonus.c \
			srcs/bonus/utils_bonus.c
OBJ				= $(SRC:.c=.o)
OBJ_BONUS		= $(SRC_BONUS:.c=.o)
INCS			= -I ./includes/
HEADER			= ./includes/push_swap.h
HEADER_BONUS	= ./includes/push_swap_bonus.h

all: $(NAME)

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
			$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
