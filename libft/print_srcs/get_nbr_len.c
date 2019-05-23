/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:15:46 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/05 01:15:47 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_pointers.h"
#include "specifiers.h"
#include "utils.h"
#include "libft.h"
#include "flags.h"

int		nbr_lllen(long long n, t_spec *spec)
{
	int len;

	len = (n < 0);
	if (len == 0)
		len = (n == 0) + ((spec->flag & (FLAG_PLUS | FLAG_SPACE)) > 0);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int		nbr_ulllen(unsigned long long n, t_spec *spec)
{
	int len;

	len = (n == 0) + ((spec->flag & (FLAG_PLUS | FLAG_SPACE)) > 0);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int		nbr_len_base(unsigned long long nbr, int base_len)
{
	int len;

	len = nbr == 0;
	while (nbr != 0 && ++len)
		nbr /= base_len;
	return (len);
}

int		nbr_len(t_spec *spec, void *n)
{
	if (spec->option == 'u')
	{
		if (spec->size <= sizeof(char))
			return (nbr_ulllen(read_uchar(n), spec));
		else if (spec->size <= sizeof(short))
			return (nbr_ulllen(read_ushort(n), spec));
		else if (spec->size <= sizeof(int))
			return (nbr_ulllen(read_uint(n), spec));
		else if (spec->size <= sizeof(long))
			return (nbr_ulllen(read_ulong(n), spec));
		else if (spec->size <= sizeof(long long))
			return (nbr_ulllen(read_ullong(n), spec));
	}
	if (spec->size <= sizeof(char))
		return (nbr_lllen(read_char(n), spec));
	else if (spec->size <= sizeof(short))
		return (nbr_lllen(read_short(n), spec));
	else if (spec->size <= sizeof(int))
		return (nbr_lllen(read_int(n), spec));
	else if (spec->size <= sizeof(long))
		return (nbr_lllen(read_long(n), spec));
	else if (spec->size <= sizeof(long long))
		return (nbr_lllen(read_llong(n), spec));
	return (0);
}
