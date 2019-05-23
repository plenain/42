# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <kicausse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:08:47 by kicausse          #+#    #+#              #
#    Updated: 2018/12/05 23:26:12 by kicausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_abs.c ft_adv_memcmp.c ft_atoi.c ft_atoi_base.c ft_bzero.c ft_ceil.c  \
			ft_floor.c ft_get_bit.c ft_isalnum.c ft_isalpha.c ft_isascii.c  \
			ft_isdigit.c ft_ishex.c ft_isprint.c ft_itoa.c ft_max.c ft_memalloc.c  \
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c  \
			ft_memmove.c ft_memset.c ft_min.c ft_power.c ft_print_char.c  \
			ft_print_char_fd.c ft_print_hex.c ft_print_hex_fd.c ft_print_memory.c  \
			ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c  \
			ft_putnbr_base.c ft_putnbr_fd.c ft_putnbrendl.c ft_putnstr.c  \
			ft_putnstr_fd.c ft_putnstr_non_printable.c ft_putstr.c ft_putstr_fd.c  \
			ft_putstr_non_printable.c ft_putstr_non_printable_fd.c ft_memdup.c  \
			ft_set_bit.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c  \
			ft_strcut.c ft_strdel.c ft_strdup.c ft_strdup_if.c ft_strequ.c  \
			ft_strins.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoin_if.c  \
			ft_strjoinfree.c ft_strlcat.c ft_strlen.c ft_strlen_if.c ft_strmap.c  \
			ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c  \
			ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c  \
			ft_strsub.c ft_strtolower.c ft_strtoupper.c ft_strtrim.c ft_swap.c  \
			ft_tolower.c ft_toupper.c read_memory_int.c read_memory_unsigned_int.c  \
			unicode.c unicode_2.c nbrlen.c \
			print_srcs/colors.c print_srcs/flags.c print_srcs/flags_utils.c  \
			print_srcs/ft_printf.c print_srcs/function_pointers.c  \
			print_srcs/get_nbr_len.c print_srcs/list.c print_srcs/nbr_utils.c  \
			print_srcs/print_base.c print_srcs/print_floats.c  \
			print_srcs/print_numbers.c print_srcs/print_numbers2.c  \
			print_srcs/print_strings.c print_srcs/print_unicode_strings.c  \
			print_srcs/specifiers.c print_srcs/utils.c

OBJ 	= 	$(SRC:.c=.o)

FLAGS 	=	-Wall -Wextra -Werror -Iincludes -I.

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
