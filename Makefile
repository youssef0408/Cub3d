# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joe_jam <joe_jam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 22:33:53 by yothmani          #+#    #+#              #
#    Updated: 2024/04/04 01:46:41 by joe_jam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D
CC              = gcc
CFLAGS          = -g -Wall -Wextra -Werror
RM              = rm -rf
LIBFT           = $(LIBFT_DIR)/libft.a
SRC_DIR         = src
OBJ_DIR			= obj
INC_DIR         = includes
LIBFT_DIR       = lib/libft


LIBS            = -I$(INC_DIR) -I$(LIBFT_DIR)

SRC_FILES = parsing/map.c parsing/main.c  parsing/file.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)



$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(LIBS)
	@echo $(BOLD)$(MINT) "Compiled $<"


$(OBJ_DIR):
	mkdir -p obj/ obj/parsing

	
norm:
	@echo $(BOLD)$(GREEN)" Mandatory part!"$(MINT)
	@echo $(BOLD)$(PINK)" Library: "
	@norminette $(LIBFT_DIR)
	@echo $(BOLD)$(MINT)" Includes: "
	@norminette $(INC_DIR)
	@echo $(BOLD)$(MAUVE)" Sources: "
	@norminette $(SRC)
	
clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR)
	@echo $(BOLD)$(GREEN)objects and executables are cleaned ! ... 🧹🗑️$(RESET)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) 
	@echo $(BOLD)$(L_PURPLE) $(PINK)All cleaned up! ....🧹🗑️$(RESET)

re: fclean all

.PHONY: all clean fclean re install

# ######################### Colors #########################

GREEN="\033[32m"
MINT="\033[38;5;51m"
L_PURPLE="\033[38;5;55m"
MAUVE="\033[38;5;147m"
PINK="\033[38;5;175m"
RESET="\033[0m"
BOLD="\033[1m"
UP = "\033[A"
DOWN = "\033[B"
RIGHT = "\033[C"
LEFT = "\033[D"
CUT = "\033[K"
SAVE = "\033[s"
RESTORE = "\033[u"