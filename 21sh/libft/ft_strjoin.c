/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:38:20 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/11 22:24:26 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*b;
	char	*c;

	if (s1 && s2)
		if ((b = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			c = b;
			while (*s1)
				*b++ = *s1++;
			while (*s2)
				*b++ = *s2++;
			*b = '\0';
			return (c);
		}
	return ((void *)0);
}
