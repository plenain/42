# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plenain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 14:26:36 by plenain           #+#    #+#              #
#    Updated: 2019/05/13 16:59:49 by plenain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	minishell

SRC 	= 	srcs/arguments.c srcs/builtin_functions.c srcs/builtin_functions_2.c  \
			srcs/builtin_functions_3.c srcs/builtins.c srcs/command.c  \
			srcs/environment.c srcs/input.c srcs/logs.c srcs/main.c srcs/parser.c  \
			srcs/parser_expander.c srcs/parser_utils.c srcs/utils.c srcs/aliases.c \
			srcs/shrc.c srcs/builtin_utils.c srcs/default_env.c srcs/signals.c

INC 	= 	includes/commands.h includes/constants.h includes/parsing.h  \
			includes/shell.h includes/utils.h

CC		=	gcc

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -Ilibft -Iincludes

all: $(NAME) libft/

$(NAME): libft/ includes/ Makefile $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $< 

re: fclean all

clean:
	make clean -C libft/
	/bin/rm -Rf $(OBJ)

fclean: clean
	make fclean -C libft/
	/bin/rm -Rf $(NAME)
