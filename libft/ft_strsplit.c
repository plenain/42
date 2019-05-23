/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:41:41 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 19:41:43 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*copy_word(const char *src, char limit)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] && src[i] != limit)
		i++;
	output = (char*)ft_strnew(i);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != limit)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

static int		count_words(const char *str, char limit)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != limit)
		{
			count++;
			while (str[i] && str[i] != limit)
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

static char		**free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**output;
	int		i;
	int		x;

	if (s == 0 ||
		!(output = (char**)ft_memalloc(sizeof(char*) * count_words(s, c))))
		return (NULL);
	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if ((output[x] = copy_word(s + i, c)) == NULL)
				return (free_tab(output, x));
			while (s[i] && s[i] != c)
				i++;
			x++;
		}
		else
			i++;
	}
	output[x] = 0;
	return (output);
}
