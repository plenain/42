/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 00:24:58 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/04 00:24:59 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "list.h"
#include "libft.h"
#include "utils.h"
#include "flags.h"
#include "function_pointers.h"

t_nbrbase_func g_base_func[BASE_SPECIFIER_COUNT] = {
	{'x', "0123456789abcdef"},
	{'p', "0123456789abcdef"},
	{'X', "0123456789ABCDEF"},
	{'o', "01234567"},
	{'O', "01234567"},
	{'b', "01"},
	{'\0', "error"}
};

int		get_base_nbr_len(t_spec *spec, int nbrlen, unsigned long long nbr)
{
	if ((spec->option == 'p' || (flag(spec->flag, FLAG_HEX) && nbr > 0
		&& charset_match("xX", spec->option))) && spec->maxlen == NULL)
	{
		nbrlen += 2;
	}
	else if (charset_match("oO", spec->option) && nbr != 0
		&& spec->flag & FLAG_HEX)
		nbrlen++;
	if (nbr == 0 && spec->maxlen != NULL && ft_atoi(spec->maxlen) == 0
		&& !(spec->print = 0))
		nbrlen = 0;
	return (nbrlen);
}

void	get_hexnbr_padding(t_spec *spec, int nbrlen, unsigned long long nbr)
{
	int minlen;
	int maxlen;

	maxlen = ft_floor(0, ft_atoi(spec->maxlen) - nbrlen);
	minlen = ft_floor(0, ft_atoi(spec->minlen) - nbrlen);
	if (spec->maxlen != NULL)
	{
		spec->print = is_printable(spec->print, spec, &maxlen);
		if (((spec->flag & (FLAG_PLUS | FLAG_SPACE)) > 0)
			&& ft_atoi(spec->maxlen) >= nbrlen && nbrlen != 0)
			maxlen++;
		spec->zeropad = maxlen;
	}
	if (spec->minlen != NULL && (minlen -= maxlen) > 0)
	{
		if ((spec->option == 'p' || (flag(spec->flag, FLAG_HEX) && nbr > 0
		&& charset_match("xX", spec->option))) && spec->maxlen != NULL)
			minlen -= 2;
		if (flag(spec->flag, FLAG_MINUS))
			spec->pad_right = minlen;
		else if ((spec->minlen[0] != '0' || (spec->maxlen != NULL)))
			spec->pad = minlen;
		else
			spec->zeropad = minlen;
	}
}

int		print_hex_prefix(t_spec *spec, unsigned long long nbr)
{
	int		prnt_cnt;

	prnt_cnt = 0;
	if (spec->option == 'p')
	{
		prnt_cnt += 2;
		ft_putstr_fd("0x", spec->fd);
	}
	else if (spec->flag & FLAG_HEX && nbr > 0
		&& charset_match("xX", spec->option))
	{
		ft_putstr_fd(spec->option == 'x' ? "0x" : "0X", spec->fd);
		prnt_cnt += 2;
	}
	else if (charset_match("oO", spec->option) && spec->flag & FLAG_HEX
		&& (nbr != 0 || (spec->maxlen != NULL
		&& ft_atoi(spec->maxlen) == 0)))
	{
		ft_putchar_fd('0', spec->fd);
		prnt_cnt++;
	}
	return (prnt_cnt);
}

int		print_hexnbr_padding(t_spec *spec, unsigned long long nbr)
{
	int prnt_cnt;

	prnt_cnt = 0;
	prnt_cnt += ft_print_char_fd(' ', spec->pad, spec->fd);
	prnt_cnt += print_hex_prefix(spec, nbr);
	prnt_cnt += ft_print_char_fd('0', spec->zeropad, spec->fd);
	return (prnt_cnt);
}

int		print_base(t_spec *spec, va_list *args)
{
	int					i;
	int					prnt_cnt;
	unsigned long long	nbr;
	long long			tmp;

	i = 0;
	prnt_cnt = 0;
	tmp = read_nbr(spec, args);
	nbr = get_unbr(spec, &tmp);
	while (i < BASE_SPECIFIER_COUNT - 1)
	{
		if (g_base_func[i].spec == spec->option)
			break ;
		i++;
	}
	tmp = nbr_len_base(nbr, ft_strlen(g_base_func[i].base));
	tmp = get_base_nbr_len(spec, tmp, nbr);
	get_hexnbr_padding(spec, tmp, nbr);
	prnt_cnt += print_hexnbr_padding(spec, nbr);
	if (spec->print)
	{
		prnt_cnt += print_nbr_base(nbr, g_base_func[i].base, spec->fd);
	}
	prnt_cnt += ft_print_char_fd(' ', spec->pad_right, spec->fd);
	return (prnt_cnt);
}
