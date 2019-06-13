/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:20:55 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/01 17:29:23 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

size_t	ft_eg(char *c)
{
	size_t i;

	i = 0;
	if (c)
		while (c[i] && c[i] != '=')
			i++;
	return (i);
}

int		ft_fet(char *a, char *b)
{
	int		i;
	size_t	u;
	size_t	l;

	i = 1;
	if (a && b)
	{
		u = ft_strlen(b);
		l = ft_eg(a);
		if (u > 1 && b[u - 1] == '=')
			l++;
		if (l == u)
			i = ft_strncmp(b, a, l);
		if (i == 0)
			return (1);
	}
	return (0);
}

char	**ft_create_env(int i)
{
	char	**n;

	if (i == 0)
		return (NULL);
	n = (char **)malloc(sizeof(char *) * 4);
	n[0] = ft_strdup("PWD=/");
	n[1] = ft_strdup("OLDPWD=/");
	n[2] = ft_strdup("HOME=/");
	n[3] = NULL;
	return (n);
}

