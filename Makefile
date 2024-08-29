# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 18:34:37 by bepoisso          #+#    #+#              #
#    Updated: 2024/08/29 14:41:57 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#_________________VARIABLE_________________

NAME = push_swap
CC= gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

#_________________FILES_________________

SRC_DIR = ./srcs
OBJ_DIR = ./objs
INC_DIR = ./includes

SRC_FILES=\

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

#_________________RULES_________________

all: $(NAME)
	$(CC) $(CFLAGS) $(NAME)

$(NAME): $(OBJS)
	@make -C libft

$(OBJS): $(SRCS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make clean -C libft
	@rm -rf $(OBJ_DIR)
	@rm -rf main.o

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re