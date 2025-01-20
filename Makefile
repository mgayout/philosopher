# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 12:52:52 by mgayout           #+#    #+#              #
#    Updated: 2025/01/20 12:47:56 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAG = -Wall -Wextra -Werror
PHFLAGS = -g #-pthread -fsanitize=address -fsanitize=thread

SRCDIR	= src
OBJDIR	= obj
HEADIR	= include

SRC		= $(shell find $(SRCDIR) -name '*.c')
OBJ		= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
HEADER	= $(shell find $(HEADIR) -name '*.h')

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ) $(FLAG) $(PHFLAG) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@gcc $(FLAG) $(PHFLAG) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re