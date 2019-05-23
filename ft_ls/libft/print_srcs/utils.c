/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:46:45 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/03 22:46:45 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

int		charset_match(char *s, char c)
{
	while (*s != 0)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int		is_option(char c)
{
	return (charset_match(OPTIONS, c) == 1);
}

int		flag(int nbr, int flags)
{
	return ((nbr & flags) == flags);
}

int		search_reverse(char *str, char c, int start)
{
	while (start >= 0)
	{
		if (str[start] == c)
			return (start);
		start--;
	}
	return (-1);
}

int		is_printable(int print, t_spec *spec, int *maxlen)
{
	if (ft_atoi(spec->maxlen) == 0 && spec->option == 'p' && !(*maxlen = 0))
		return (0);
	return (print);
}
