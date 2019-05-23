/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adv_memcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:51:47 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 20:51:55 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static unsigned char	get_char_val(char c)
{
	int			i;
	const char	*base = "0123456789abcdef";

	i = 0;
	while (base[i])
	{
		if (base[i] == ft_tolower(c))
			return (i);
		i++;
	}
	return (0);
}

int						ft_adv_memcmp(const void *source, const char *hexdata)
{
	unsigned char		byte;
	unsigned int		i;
	unsigned char		*ptr;

	ptr = (unsigned char*)source;
	i = 0;
	if (source == NULL || hexdata == NULL)
		return (-1);
	while (hexdata[i] != '\0')
	{
		if (hexdata[i] == ' ')
		{
			i++;
			continue ;
		}
		byte = get_char_val(hexdata[i]) * 16 + get_char_val(hexdata[i + 1]);
		if (byte != *ptr)
			return (byte - *ptr);
		ptr++;
		i++;
		if (hexdata[i] != '\0')
			i++;
	}
	return (0);
}
