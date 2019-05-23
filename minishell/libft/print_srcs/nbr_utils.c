/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:23:10 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/05 22:23:11 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_pointers.h"
#include "libft.h"
#include "specifiers.h"

unsigned long long	get_unbr(t_spec *spec, void *n)
{
	if (spec->size <= sizeof(char))
		return (read_uchar(n));
	else if (spec->size <= sizeof(short))
		return (read_ushort(n));
	else if (spec->size <= sizeof(int))
		return (read_uint(n));
	else if (spec->size <= sizeof(long))
		return (read_ulong(n));
	return (read_ullong(n));
}

long long			get_nbr(t_spec *spec, void *n)
{
	if (spec->size <= sizeof(char))
		return (read_char(n));
	else if (spec->size <= sizeof(short))
		return (read_short(n));
	else if (spec->size <= sizeof(int))
		return (read_int(n));
	else if (spec->size <= sizeof(long))
		return (read_long(n));
	return (read_llong(n));
}

int					nbr_neg(t_spec *spec, void *n)
{
	if (spec->option == 'u')
		return (0);
	return (get_nbr(spec, n) < 0);
}

int					nbr_null(t_spec *spec, void *n)
{
	return (get_nbr(spec, n) == 0);
}

long long			read_nbr(t_spec *spec, va_list *args)
{
	long long	n;

	if (spec->size <= sizeof(int))
		n = va_arg(*args, int);
	else if (spec->size <= sizeof(long))
		n = va_arg(*args, long);
	else
		n = va_arg(*args, long long);
	return (get_unbr(spec, &n));
}
