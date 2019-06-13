/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:26:08 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/11 22:23:29 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*b;
	char	*c;

	if (s)
		if ((b = malloc(sizeof(char) * (len + 1))))
		{
			c = b;
			while (len--)
				*b++ = s[start++];
			*b = '\0';
			return (c);
		}
	return ((void *)0);
}
