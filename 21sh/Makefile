NAME = 21sh

INCLUDE = -I include

CC = gcc -c -Wall -Wextra -Werror -g
GO = gcc -o 

PINK	=	\033[35;5;108m
PURPLE	=	\033[38;5;141m
MAGENTA	=	\033[38;5;177m
END		=	\033[0m

CR_UP	=	\033[A
CLEAR	=	\033[K

SRC		= $(shell ls ./src/ | grep -E ".+\.c")
ENV		= $(shell ls ./builtin/env/ | grep -E ".+\.c") 
PROMPT	= $(shell ls ./prompt/ | grep -E ".+\.c")
INIT	= $(shell ls ./init/ | grep -E ".+\.c")
SIGN	= $(shell ls ./signaux/ | grep -E ".+\.c")
STATIC	= $(shell ls ./static | grep -E ".+\.c")

STATICS		= $(addprefix static/, $(STATIC))
SRCS		= $(addprefix src/, $(SRC))
EE			= $(addprefix builtin/env/, $(ENV))
PROMPTS		= $(addprefix prompt/, $(PROMPT))
INITS		= $(addprefix init/, $(INIT))
SIGNS		= $(addprefix signaux/, $(SIGN))

OBJ_SRC	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_PT	= $(addprefix $(OBJ_DIR), $(PROMPT:.c=.o))
OBJ_IN	= $(addprefix $(OBJ_DIR), $(INIT:.c=.o))
OBJ_SIG	= $(addprefix $(OBJ_DIR), $(SIGN:.c=.o))
OBJ_STA	= $(addprefix $(OBJ_DIR), $(STATIC:.c=.o))
OBJ_ENV	= $(addprefix $(OBJ_DIR), $(ENV:.c=.o))

all:	$(NAME)

$(NAME):
		@make -C libft/
		@echo "${MAGENTA}LIBRARY COMPILED ✓${END}"
		@$(CC)  $(INCLUDE) $(SRCS) $(EE) $(PROMPTS) $(INITS) $(SIGNS) $(STATICS)
		@$(GO) $(NAME) -L libft/  -lft  -ltermcap $(OBJ_SRC) $(OBJ_PT) $(OBJ_IN) $(OBJ_SIG) $(OBJ_STA) $(OBJ_ENV) 
		@echo "${PINK}21SH IS READY ✓${END}"	
		@mkdir -p ./objs && mv $(OBJ_SRC) $(OBJ_PT) $(OBJ_IN) $(OBJ_SIG) $(OBJ_STA) $(OBJ_ENV) ./objs

./objs/%.o:%.c
		@echo "${MAGENTA}[$@]${END}"
		@$(CC) $(INCLUDE) -c $< 
		@printf "${CR_UP}${CLEAR}"

clean:
		@rm -rf ./objs/
		@rm -f *.o 2> /dev/null
		@make clean -C  libft/
		@echo "${PURPLE}clean objs ✗${END}"

fclean:	clean
		@rm -f $(NAME)
		@make fclean -C libft/
		@echo "${PURPLE}clean $(NAME) ✗${END}"

re:	fclean all

.PHONY:	all clean fclean re
