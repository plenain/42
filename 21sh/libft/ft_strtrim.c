/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 01:00:20 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/12 21:35:43 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		start(const char *s)
{
	int i;

	i = 0;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		i++;
		s++;
	}
	return (i);
}

static	int		end(const char *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		c;
	char	*b;

	if (s)
	{
		i = start(s);
		c = end(s);
		if (i == (int)ft_strlen(s))
			return (ft_strdup(s + i));
		if ((b = (ft_strsub(s, i, (c - i + 1)))))
			return (b);
	}
	return (NULL);
}
