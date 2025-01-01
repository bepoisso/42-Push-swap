# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 18:34:37 by bepoisso          #+#    #+#              #
#    Updated: 2025/01/01 16:57:08 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#_________________VARIABLE_________________

NAME = push_swap
CC= gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)

#_________________FILES_________________

SRC_DIR = ./srcs
OBJ_DIR = ./objs
INC_DIR = ./includes

SRC_FILES=\
			push_swap.c\
			push_operations.c\
			swap_operations.c\
			rotate_operations.c\
			rotate_operations_pt2.c\
			sort.c\
			sort_cost.c\
			sort_init.c\
			sort_target.c\
			sort_utils.c\
			utils.c\
			parser.c\
			error.c\

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

#_________________RULES_________________

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make clean -C libft > /dev/null 2>&1
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C libft > /dev/null 2>&1
	@rm -f $(NAME)

re: fclean all

debug: re
	gdb -tui -q push_swap

val: re
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap 3 1 4 2

.PHONY: all clean fclean re
