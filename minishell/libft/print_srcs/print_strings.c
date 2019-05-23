/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:29:25 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/03 22:29:26 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "list.h"
#include "libft.h"
#include "flags.h"
#include "utils.h"

int		print_padding(t_spec *spec)
{
	int prnt_cnt;

	prnt_cnt = 0;
	prnt_cnt += ft_print_char_fd(' ', spec->pad, spec->fd);
	prnt_cnt += ft_print_char_fd('0', spec->zeropad, spec->fd);
	return (prnt_cnt);
}

void	get_padding(t_spec *spec, int len)
{
	int minlen;

	minlen = ft_atoi(spec->minlen) - len;
	if (spec->minlen != NULL)
	{
		if (flag(spec->flag, FLAG_MINUS))
			spec->pad_right = minlen;
		else if (spec->minlen[0] != '0')
			spec->pad = minlen;
		else
			spec->zeropad = minlen;
	}
}

int		print_char(t_spec *spec, va_list *args)
{
	int	c;
	int	prnt_cnt;

	get_padding(spec, 1);
	prnt_cnt = print_padding(spec);
	if (charset_match_c("cC", spec->option))
		c = va_arg(*args, int);
	else
		c = spec->option;
	if (spec->option != '\0')
	{
		prnt_cnt++;
		if (spec->option == 'C')
			ft_putchar_uni(c);
		else
			ft_putchar_fd(c, spec->fd);
	}
	prnt_cnt += ft_print_char_fd(' ', spec->pad_right, spec->fd);
	return (prnt_cnt);
}

int		print_string(t_spec *spec, va_list *args)
{
	int		len;
	int		prnt_cnt;
	char	*string;

	prnt_cnt = 0;
	string = va_arg(*args, char*);
	len = ft_strlen(string);
	if (string == 0)
		len = 6;
	if (spec->maxlen != 0 && ft_atoi(spec->maxlen) < len)
		len = ft_atoi(spec->maxlen);
	get_padding(spec, len);
	prnt_cnt += print_padding(spec);
	if (spec->option == 's')
		prnt_cnt += ft_putnstr_fd(string, len, spec->fd);
	else
		prnt_cnt += ft_putnstr_non_printable_fd(string, len, spec->fd);
	prnt_cnt += ft_print_char_fd(' ', spec->pad_right, spec->fd);
	return (prnt_cnt);
}
