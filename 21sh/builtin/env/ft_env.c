/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:59:24 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/01 15:38:51 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

char	*ft_getenv(t_env z, char *name)
{
	char	*y;
	int		i;
	char	*p;

	y = NULL;
	if (z.b)
		while ((p = *z.b++))
		{
			i = 0;
			if (ft_fet(p, name))
			{
				while (p[i] != '=')
					i++;
				i++;
				y = ft_strdup(&p[i]);
				return (y);
			}
		}
	return (y);
}

void	free_env(t_env b)
{
	size_t	i;

	i = 0;
	if (b.b)
	{
		while (b.b[i])
			free(b.b[i++]);
		free(b.b);
	}
}

char	**fadd(t_env *b)
{
	char	**y;
	int		l;

	l = 0;
	b->i += 100;
	y = (char **)malloc(sizeof(char) * (*b->i));
	while (b->b[l])
	{
		y[l] = ft_strdup(b->b[l]);
		l++;
	}
	free(b->b);
	return (y);
}

char	**add_env(t_env *r, char *b)
{
	if (*r->c >= *r->i)
		r->b = fadd(r);
	r->b[*r->c] = ft_strdup(b);
	*r->c = *r->c + 1;
	r->b[*r->c] = NULL;
	return (r->b);
}

char	**make_env(char **str, t_env *env, int pp)
{
	size_t	i;
	char	**b;

	*env->i = 0;
	*env->c = 0;
	if (!(str) || !(*str))
		str = ft_create_env(pp);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	*env->c = i;
	*env->i = i + 100;
	if (!(i) || !(b = (char **)malloc(sizeof(char *) * (*env->i))))
		return (NULL);
	i = 0;
	while (*str)
		b[i++] = ft_strdup(*str++);
	b[i] = NULL;
	i = *env->c + 100;
	return (b);
}
