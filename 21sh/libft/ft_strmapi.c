/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 23:52:56 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/11 22:20:18 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*b;
	char	*c;
	int		i;

	i = 0;
	if (s)
		if ((b = malloc(sizeof(char) * ft_strlen(s) + 1)))
		{
			c = b;
			while (s[i])
			{
				b[i] = f((unsigned int)i, s[i]);
				i = i + 1;
			}
			b[i] = '\0';
			return (c);
		}
	return ((void *)0);
}
