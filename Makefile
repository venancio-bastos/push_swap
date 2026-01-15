# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 12:36:23 by vebastos          #+#    #+#              #
#    Updated: 2026/01/15 20:57:23 by vebastos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g -I includes 

SRC_DIR      = src/
UTILS_DIR    = utils/
COMMANDS_DIR = utils/commands/
PS_DIR       = utils/push_swap/

SRC_MAIN     = $(SRC_DIR)push_swap.c
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
               $(UTILS_DIR)utils_lib.c
SRC = $(SRC_MAIN) $(SRC_COMMANDS) $(SRC_PS) $(SRC_UTILS)

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re