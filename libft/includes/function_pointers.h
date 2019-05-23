/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:23:27 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/03 22:23:27 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_POINTERS_H
# define FUNCTION_POINTERS_H
# include <stdarg.h>
# include "specifiers.h"

# define SPECIFIER_COUNT (19)
# define NBR_SPECIFIER_COUNT (3)
# define BASE_SPECIFIER_COUNT (7)

typedef struct			s_func
{
	char	spec;
	int		(*func)(t_spec*, va_list*);
}						t_func;

typedef struct			s_nbrbase_func
{
	char	spec;
	char	*base;
}						t_nbrbase_func;

int						print_spec(t_spec *spec, va_list *arg);

int						print_char(t_spec *spec, va_list *args);
int						print_string(t_spec *spec, va_list *args);
int						print_unicode_string(t_spec *spec, va_list *args);

int						print_integer(t_spec *spec, va_list *args);
int						print_unsigned_nbr(t_spec *spec, void *n);
int						print_nbr(t_spec *spec, void *n);
int						ft_putllnbr(long long n, int fd);

int						nbr_len(t_spec *spec, void *n);
int						nbr_len_base(unsigned long long nbr, int base_len);

int						nbr_neg(t_spec *spec, void *n);
int						nbr_null(t_spec *spec, void *n);
unsigned long long		get_unbr(t_spec *spec, void *n);
long long				get_nbr(t_spec *spec, void *n);
long long				read_nbr(t_spec *spec, va_list *args);

int						print_base(t_spec *spec, va_list *args);
int						print_nbr_base(unsigned long long nbr, char *base,
						int fd);

int						print_floats(t_spec *spec, va_list *args);

void					get_padding(t_spec *spec, int len);
int						print_padding(t_spec *spec);

#endif
