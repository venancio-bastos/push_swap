# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 21:44:30 by vebastos          #+#    #+#              #
#    Updated: 2026/01/15 22:44:29 by vebastos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
BONUS_NAME = checker
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g -I includes

SRC_DIR      = src/
UTILS_DIR    = utils/
COMMANDS_DIR = utils/commands/
PS_DIR       = utils/push_swap/
GNL_DIR      = utils/gnl/

SRC_MAIN     = $(SRC_DIR)push_swap.c

SRC_BONUS    = src/checker.c \
               $(GNL_DIR)get_next_line.c \
               $(GNL_DIR)get_next_line_utils.c

SRC_COMMANDS = $(COMMANDS_DIR)ops_push.c \
               $(COMMANDS_DIR)ops_swap.c \
               $(COMMANDS_DIR)ops_rotate.c \
               $(COMMANDS_DIR)ops_rrotate.c
SRC_PS       = $(PS_DIR)init_nodes.c \
               $(PS_DIR)stack_init.c \
               $(PS_DIR)sort_stacks.c \
               $(PS_DIR)sort_tiny.c
SRC_UTILS    = $(UTILS_DIR)ft_split.c \
               $(UTILS_DIR)input_check.c \
               $(UTILS_DIR)stack_utils.c \
               $(UTILS_DIR)checker_utils.c \
               $(UTILS_DIR)utils_lib.c

COMMON_SRC   = $(SRC_COMMANDS) $(SRC_PS) $(SRC_UTILS)

OBJ_MAIN     = $(SRC_MAIN:.c=.o)
OBJ_BONUS    = $(SRC_BONUS:.c=.o)
OBJ_COMMON   = $(COMMON_SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_MAIN) $(OBJ_COMMON)
	$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJ_COMMON) -o $(NAME)

bonus: checker

checker: $(OBJ_BONUS) $(OBJ_COMMON)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ_COMMON) -o checker

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_MAIN) $(OBJ_COMMON) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all

.PHONY: all clean fclean re bonus
