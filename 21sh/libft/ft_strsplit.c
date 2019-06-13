/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:24:42 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/14 20:40:16 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			sizeme(char *s, int c)
{
	int v;

	v = 0;
	if (*s && *s != c)
		v++;
	while (*s)
		if (*s++ == c)
			if (*s && (*s != c))
				v++;
	return (v);
}

static	int			count(char *s, int c)
{
	int i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static	char		*add(char *s, char *args, int i, int cc)
{
	int	b;
	int	c;

	c = 0;
	b = 0;
	while (*s == cc)
		s++;
	while (b < i && *s)
	{
		if (*s++ == cc)
			if (*s != cc && *s)
				b++;
	}
	if (!(args = (char *)malloc(sizeof(char) * count(s, cc) + 1)))
		return (NULL);
	while (*s && *s != cc)
		args[c++] = *s++;
	args[c] = '\0';
	return (args);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**args;
	int		y;
	int		g;

	if (!(s))
		return ((void *)0);
	g = 0;
	y = sizeme((char *)s, c);
	if (!(args = (char**)malloc(sizeof(char*) * (y + 1))))
		return (0);
	while (g < y)
	{
		if (!(args[g] = add((char *)s, args[g], g, c)))
		{
			ft_memdel((void *)&args);
			return (NULL);
		}
		g++;
	}
	args[g] = 0;
	return (args);
}
