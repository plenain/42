/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:58:10 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/11 22:06:59 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*b;
	char	*g;

	if (s)
		if ((b = malloc(sizeof(char) * ft_strlen(s) + 1)))
		{
			g = b;
			while (*s)
				*b++ = f(*s++);
			*b = '\0';
			return (g);
		}
	return ((void *)0);
}
