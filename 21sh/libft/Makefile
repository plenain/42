# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:37:32 by bordenoy          #+#    #+#              #
#    Updated: 2019/05/16 13:12:19 by fcatusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(shell ls | grep -E ".+\.c")

INC		=	libft.h

OBJ		= 	$(SRCS:.c=.o)

PURPLE	=	\033[38;5;141m
END		=	\033[0m

CR_UP	=	\033[A
CLEAR	=	\033[K

all: 		$(NAME)

$(NAME): 	$(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o:	%.c
	@echo "${PURPLE}[$@]${END}"
	@gcc $(FLAGS) -I . -c -o $@ $<
	@printf "${CR_UP}${CLEAR}"

$(OBJ):		$(INC)

clean:
	@rm -rf $(OBJ)

fclean: 	clean
	@rm -rf $(NAME)

re: 		fclean all

.PHONY:		 all clean fclean re]]]]
