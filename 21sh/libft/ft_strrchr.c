/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 08:09:00 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/17 16:33:10 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*b;

	b = (char *)s;
	while (*s)
	{
		if (*s == (char)c)
			b = (char *)s;
		s++;
	}
	if (*s == c)
		b = (char *)s;
	if (*b == c)
		return (b);
	return (NULL);
}
