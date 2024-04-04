# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 12:52:52 by mgayout           #+#    #+#              #
#    Updated: 2024/04/04 16:32:00 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

SRC =	src/main.c \
		src/init.c \
		src/philo.c \
		src/eating.c \
		src/utils/libft.c \
		src/utils/utils.c \
		src/utils/get_data.c \
		src/utils/get_data2.c \
		src/utils/get_philo.c \
		src/utils/update_value.c \

OBJ		=	${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re