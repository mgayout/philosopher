# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 12:52:52 by mgayout           #+#    #+#              #
#    Updated: 2024/04/05 14:26:57 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
PHILO_FLAGS = 	-g #-pthread -fsanitize=address -fsanitize=thread
SRC_DIR = src/
OBJ_DIR = obj/

SRC =	main \
		init \
		routine \
		eat \
		sleep_think \
		libft \
		utils \
		utils2 \
		get_data \
		get_data2 \
		get_philo \
		update_value \

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re