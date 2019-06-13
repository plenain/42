/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:37:55 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/11 22:37:27 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		compare(const char *str, const char *find)
{
	while (*str && *find)
		if (*str++ != *find++)
			return (0);
	if (*find)
		return (0);
	return (1);
}

char			*ft_strstr(const char *str, const char *find)
{
	if (!(*str) && !(*find))
		return ((char *)str);
	while (*str)
	{
		if (compare(str, find))
			return (char*)str;
		str++;
	}
	return ((void *)0);
}
