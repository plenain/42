/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:15:00 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/11 20:31:58 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char n;

	n = (char)c;
	while (*s)
	{
		if (*s == n)
			return ((char *)s);
		s++;
	}
	if (*s == n)
		return ((char *)s);
	return ((char *)0);
}
