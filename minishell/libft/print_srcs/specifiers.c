/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:14:47 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/03 22:14:48 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"
#include "libft.h"
#include "flags.h"
#include <stdlib.h>

int		parse_specifier(const char *start, t_spec **spec, int idx, int fd)
{
	t_spec	*new;
	char	*str;

	str = (char*)start;
	if ((new = spec_lst_new(idx)) == NULL)
		return (-1);
	spec_lst_push(spec, new);
	if ((str += get_flags(str, new)) < start)
		return (-1);
	new->option = *str;
	new->fd = fd;
	if (!is_option(*str) && is_option(ft_tolower(*str)))
		new->option = ft_tolower(*str);
	new->len = 2 + (str - start);
	return (new->len);
}

int		get_specifiers(const char *format, t_spec **spec, int fd)
{
	int		i;
	int		tmp;
	int		len;

	i = 0;
	len = ft_strlen(format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			if ((tmp = parse_specifier(&format[i + 1], spec, i, fd)) == -1)
				return (-1);
			i += tmp;
		}
		else
			i++;
	}
	return (1);
}
