/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:38:35 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:38:37 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t length)
{
	size_t	i;
	size_t	i2;

	i = 0;
	while (s1[i] != '\0' && i < length)
	{
		i2 = 0;
		while (s1[i + i2] == s2[i2] && s1[i + i2] && i + i2 < length)
			i2++;
		if (s2[i2] == '\0')
			return ((char*)s1 + i);
		i++;
	}
	if (s1[0] == '\0' && s2[0] == '\0')
		return ((char*)s1);
	return (NULL);
}
