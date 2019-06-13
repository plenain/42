/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:45:16 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 15:36:53 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_21.h"

static char	*remalloc(char *c, size_t y)
{
	char *t;
	size_t u;

	u = 0;
	if (!(t = (char *)malloc(sizeof(char) * (y + 61))))
		return (NULL);
	while (u < y)
	{
		t[u] = c[u];
		u++;
	}
	t[u] = '\0';
	free(c);
	return (t);
}

static char *add_begin(char *a, char c)
{
	char *r;
	size_t u;
	size_t y;

	u = 0;
	y = 0;
	r = ft_strdup(a);
	a[y++] = c;
	while (r[u])
		a[y++] = r[u++];
	a[y] = '\0';
	if (y && ((y % 60) == 0))
		a = remalloc(a, y);
	free(r);
	return (a);
}

static  char * add_alpha(char *ac, char c)
{
	size_t y;


	y = 0;
	while (ac[y])
		y++;
	ac[y++] = c;
	ac[y] = '\0';
	if (y && ((y % 60) == 0))
		ac = remalloc(ac, y);
	return (ac);
}

static char  *add_middle(char *ac, char t, size_t c)
{
	char *r;
	size_t y;
	size_t u;

	u = 0;
	y = 0;
	while (c--)
		y++;
	r = ft_strdup(&ac[y]);
	ac[y++] = t;
	while (r[u])
		ac[y++] = r[u++];
	ac[y] = '\0';
	free(r);
	if (y && ((y % 60) == 0))
		ac = remalloc(ac, y);
	return (ac);
}

void	ft_alpha(t_prompt *ac, char c)
{
	size_t y;

	if (ac->com == NULL)
		ac->com = make_cursor();
	y = ft_strlen(ac->com);
	if (y == ac->oui)
	{	
		ac->com = add_alpha(ac->com, c);
		ac->oui++;
	}
	else if (ac->oui == 0)
		ac->com = add_begin(ac->com, c);
	else
		ac->com = add_middle(ac->com, c, ac->oui);
}
