# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plenain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 16:49:13 by plenain           #+#    #+#              #
#    Updated: 2019/02/12 20:58:10 by plenain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	libft/ft_abs.c libft/ft_adv_memcmp.c libft/ft_atoi.c libft/ft_atoi_base.c  \
			libft/ft_bzero.c libft/ft_ceil.c libft/ft_floor.c libft/ft_get_bit.c  \
			libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c  \
			libft/ft_isdigit.c libft/ft_ishex.c libft/ft_isprint.c libft/ft_itoa.c  \
			libft/ft_max.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c  \
			libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c  \
			libft/ft_memset.c libft/ft_min.c libft/ft_power.c libft/ft_print_char.c  \
			libft/ft_print_char_fd.c libft/ft_print_hex.c libft/ft_print_hex_fd.c  \
			libft/ft_print_memory.c libft/ft_putchar.c libft/ft_putchar_fd.c  \
			libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c  \
			libft/ft_putnbr_base.c libft/ft_putnbr_fd.c libft/ft_putnbrendl.c  \
			libft/ft_putnstr.c libft/ft_putnstr_fd.c libft/ft_putnstr_non_printable.c  \
			libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_putstr_non_printable.c  \
			libft/ft_putstr_non_printable_fd.c libft/ft_realloc.c libft/ft_set_bit.c  \
			libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c  \
			libft/ft_strcpy.c libft/ft_strcut.c libft/ft_strdel.c libft/ft_strdup.c  \
			libft/ft_strdup_if.c libft/ft_strequ.c libft/ft_strins.c  \
			libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c  \
			libft/ft_strjoin_if.c libft/ft_strjoinfree.c libft/ft_strlcat.c  \
			libft/ft_strlen.c libft/ft_strlen_if.c libft/ft_strmap.c  \
			libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c  \
			libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c  \
			libft/ft_strrchr.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c  \
			libft/ft_strtolower.c libft/ft_strtoupper.c libft/ft_strtrim.c  \
			libft/ft_tolower.c libft/ft_toupper.c libft/read_memory_int.c  \
			libft/read_memory_unsigned_int.c libft/unicode.c libft/unicode_2.c srcs/colors.c  \
			srcs/flags.c srcs/flags_utils.c srcs/ft_printf.c srcs/function_pointers.c  \
			srcs/get_nbr_len.c srcs/list.c srcs/nbr_utils.c srcs/print_base.c  \
			srcs/print_floats.c srcs/print_numbers.c srcs/print_numbers2.c  \
			srcs/print_strings.c srcs/specifiers.c srcs/utils.c srcs/print_unicode_strings.c

OBJ 	= 	$(SRC:.c=.o)

FLAGS 	=	-Wall -Wextra -Werror -Iincludes

all: $(NAME) includes/

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^

test: all
	gcc main.c $(NAME) -Iincludes && ./a.out	

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< 

re: fclean all

clean:
	@/bin/rm -Rf $(OBJ)

fclean: clean
	@/bin/rm -Rf $(NAME)
