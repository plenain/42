/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:14:18 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/03 23:14:19 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "list.h"
#include "libft.h"
#include "utils.h"
#include "flags.h"
#include "function_pointers.h"

void		get_nbr_padding(t_spec *spec, int nbrlen, int nbrnull)
{
	int minlen;
	int maxlen;

	if (spec->maxlen != NULL && ft_atoi(spec->maxlen) == 0
		&& nbrnull && !(spec->print = 0))
		nbrlen = 0;
	maxlen = ft_floor(0, ft_atoi(spec->maxlen) - nbrlen);
	minlen = ft_floor(0, ft_atoi(spec->minlen) - nbrlen);
	if (spec->maxlen != NULL)
	{
		if (((spec->flag & (FLAG_PLUS | FLAG_SPACE)) > 0 || spec->nbrneg)
			&& ft_atoi(spec->maxlen) >= nbrlen && nbrlen != 0)
			maxlen++;
		spec->zeropad = maxlen;
	}
	if (spec->minlen != NULL && (minlen -= maxlen) > 0)
	{
		if (flag(spec->flag, FLAG_MINUS))
			spec->pad_right = minlen;
		else if (spec->minlen[0] != '0' || (spec->maxlen != NULL))
			spec->pad = minlen;
		else
			spec->zeropad = minlen;
	}
}

int			print_sign(t_spec *spec, int nbrneg)
{
	if (nbrneg)
		ft_putchar_fd('-', spec->fd);
	else if (flag(spec->flag, FLAG_PLUS))
		ft_putchar_fd('+', spec->fd);
	else if (flag(spec->flag, FLAG_SPACE))
		ft_putchar_fd(' ', spec->fd);
	else
		return (0);
	return (1);
}

int			print_nbr_padding(t_spec *spec)
{
	int prnt_cnt;

	prnt_cnt = 0;
	prnt_cnt += ft_print_char_fd(' ', spec->pad, spec->fd);
	if (spec->option != 'u' && spec->option != 'U' && spec->print)
		prnt_cnt += print_sign(spec, spec->nbrneg);
	prnt_cnt += ft_print_char_fd('0', spec->zeropad, spec->fd);
	return (prnt_cnt);
}

int			print_integer(t_spec *spec, va_list *args)
{
	int			prnt_cnt;
	long long	nbr;

	prnt_cnt = 0;
	nbr = read_nbr(spec, args);
	spec->nbrneg = nbr_neg(spec, &nbr);
	get_nbr_padding(spec, nbr_len(spec, &nbr), nbr_null(spec, &nbr));
	prnt_cnt += print_nbr_padding(spec);
	if (spec->print)
		prnt_cnt += print_nbr(spec, &nbr);
	prnt_cnt += ft_print_char_fd(' ', spec->pad_right, spec->fd);
	return (prnt_cnt);
}
