/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 00:05:22 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/04 00:05:22 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "flags_utils.h"
#include "libft.h"
#include "utils.h"

int		get_other_flags(char *str, t_spec *spec)
{
	if (*str == '#')
		spec->flag |= FLAG_HEX;
	else if (*str == '+')
		spec->flag |= FLAG_PLUS;
	else if (*str == '-')
		spec->flag |= FLAG_MINUS;
	else if (*str == ' ')
		spec->flag |= FLAG_SPACE;
	return (0);
}

int		get_padding_flags2(char *str, t_spec *spec, int i)
{
	if (spec->minlen == NULL)
	{
		if ((spec->minlen = ft_strdup_if(&str[i], &ft_isdigit)) == NULL)
			return (-1);
	}
	else
	{
		if (search_reverse(str, '.', i) == -1)
		{
			ft_strdel(&(spec->minlen));
			if (!(spec->minlen = ft_strjoin_if("0", &str[i], &ft_isdigit)))
				return (-1);
		}
		else
		{
			ft_strdel(&(spec->maxlen));
			if (!(spec->maxlen = ft_strdup_if(&str[i], &ft_isdigit)))
				return (-1);
		}
	}
	return (1);
}

int		get_padding_flags(char *str, t_spec *spec, int i)
{
	if (str[i] == '.')
	{
		if ((spec->maxlen = ft_strdup_if(&str[i + 1], &ft_isdigit)) == NULL)
			return (-1);
		i += ft_strlen_if(&str[i + 1], &ft_isdigit);
	}
	else if (ft_isdigit(str[i]))
	{
		if (spec->minlen == NULL)
			spec->minlen = ft_strdup_if(&str[i], &ft_isdigit);
		else
		{
			if (get_padding_flags2(str, spec, i) == -1)
				return (-1);
		}
		i += ft_strlen_if(&str[i], &ft_isdigit) - 1;
	}
	return (i);
}

int		get_size_flag(char *str, t_spec *spec)
{
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		spec->flag |= FLAG_S_HH;
		return (1);
	}
	else if (ft_strncmp(str, "ll", 2) == 0)
	{
		spec->flag |= FLAG_S_LL;
		return (1);
	}
	else if (*str == 'h')
		spec->flag |= FLAG_S_H;
	else if (*str == 'l')
		spec->flag |= FLAG_S_L;
	else if (*str == 'L')
		spec->flag |= FLAG_S_UPPER_L;
	else if (*str == 'z')
		spec->flag |= FLAG_S_Z;
	else if (*str == 't')
		spec->flag |= FLAG_S_T;
	else if (*str == 'j')
		spec->flag |= FLAG_S_J;
	return (0);
}

int		get_flags(char *str, t_spec *spec)
{
	int		i;
	int		tmp;

	i = 0;
	while (is_valid_flag(str[i]))
	{
		if (str[i] == '.' || ft_isdigit(str[i]))
		{
			if ((tmp = get_padding_flags(str, spec, i)) == -1)
				return (-1);
			i = tmp;
		}
		else if (is_valid_size_flag(str[i]))
			i += get_size_flag(&str[i], spec);
		else
			i += get_other_flags(&str[i], spec);
		i++;
	}
	return (i);
}
