/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:01:36 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:01:38 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_char_value(char c)
{
	int				i;
	const char		*base = "0123456789abcdef";

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned long	ft_atoi_base(const char *str, unsigned int base)
{
	unsigned long	result;
	int				i;
	int				tmp;

	i = 0;
	result = 0;
	if (str == 0 || base > 16)
		return (0);
	if (base == 16 && str[0] == '0' && str[1] == 'x')
		i = 2;
	while ((tmp = get_char_value(ft_tolower(str[i]))) != -1)
	{
		result = result * base + tmp;
		i++;
	}
	return (result);
}
