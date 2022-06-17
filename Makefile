# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 19:44:26 by emadriga          #+#    #+#              #
#    Updated: 2022/06/17 23:41:11 by emadriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program's name
NAME	= minishell

# compiler
GCC		= clang

# compiling flags
FLAGS	= -Wall -Wextra -Werror -Ofast $(SANITIZE) -pedantic

# sanitize
SANITIZE = 
# SANITIZE = -fsanitize=address

# readline doing readliney things
RLINE_INC	= -I/Users/$(USER)/.brew/opt/readline/include
RLINE_L		= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib

# Header files
INCLUDES_FILES =	constants.h				\
					minishell.h				\
					dtos.h					\
					functions/errors.h		\
					functions/builtins.h	\
					functions/expansions.h	\
					functions/heredocs.h	\
					functions/paths.h		\
					functions/processes.h	\
					functions/quotes.h		\
					functions/signals.h		\
					functions/tokens.h		\
					functions/utils.h

# Source and object files
SRC_FILES	= 	main.c								\
				builtins/builtins.c					\
				builtins/cd.c						\
				builtins/env.c						\
				builtins/echo.c						\
				builtins/exit.c						\
				builtins/export.c					\
				builtins/pwd.c						\
				builtins/unset.c					\
				errors/error_handler.c				\
				errors/error_handler2.c				\
				errors/error_handler3.c				\
				expansions/var_expansor.c			\
				expansions/var_expansor2.c			\
				heredocs/heredoc_handler.c			\
				paths/get_path.c					\
				processes/get_processes.c			\
				processes/process_redirections.c	\
				processes/run_processes.c			\
				quotes/close_quotes.c				\
				quotes/quote_mark_handler.c			\
				signals/signal_handler.c			\
				tokens/token_handler.c				\
				tokens/token_handler2.c				\
				utils/array_str_handler.c			\
				utils/lst_str_handler.c				\
				utils/lst_str_handler2.c			\
				utils/lst_redir_handler.c			\
				utils/lst_process_handler.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
INCLUDES = $(addprefix $(INC_DIR), $(INCLUDES_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# Libft linkers
LNK  = -L $(LIBFT_DIR) -lft $(SANITIZE)

# all rule
all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)builtins/
	@mkdir -p $(OBJ_DIR)errors/
	@mkdir -p $(OBJ_DIR)expansions/
	@mkdir -p $(OBJ_DIR)heredocs/
	@mkdir -p $(OBJ_DIR)paths/
	@mkdir -p $(OBJ_DIR)processes/
	@mkdir -p $(OBJ_DIR)quotes/
	@mkdir -p $(OBJ_DIR)signals/
	@mkdir -p $(OBJ_DIR)tokens/
	@mkdir -p $(OBJ_DIR)utils/
$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INCLUDES)
	@$(GCC) $(FLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) $(RLINE_INC) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compiling
$(NAME): $(OBJ)
	@echo "\033[0;33mCompiling... Wait a sec.\033[0;31m"
	@$(GCC) $(OBJ) $(FLAGS) $(LNK) $(RLINE_L) -lm -o $(NAME)
	@echo "\033[0;32m$(NAME) generated!\033[0;37m"

mynorm:
	norminette $(SRC_DIR) $(INC_DIR) $(LIBFT_DIR)

bonus:	all

# clean rule
clean:
			@rm -Rf $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@echo "\033[1;34m[INFO]\033[0m Objects removed!"

# fclean rule
fclean:		clean
			@rm -f $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@echo "$(NAME) removed!"

# re rule
re:			fclean all bonus

# phony
.PHONY:		all clean fclean re mynorm
