/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:55:35 by plenain           #+#    #+#             */
/*   Updated: 2018/12/17 15:32:32 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static t_tetr	*fill_node(char *buf, t_tetr *new)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (buf[k] == '\n')
		buf++;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new->tetrimino[i][j] = buf[k];
			j++;
			k++;
		}
		k++;
		i++;
	}
	return (new);
}

static t_tetr	*new_node(char *buf)
{
	t_tetr	*new;
	int		i;

	if (!(new = (t_tetr *)ft_memalloc(sizeof(t_tetr))))
		return (NULL);
	if (!(new->tetrimino = (char **)ft_memalloc(sizeof(char *) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(new->tetrimino[i] = ft_strnew(4)))
			return (NULL);
		i++;
	}
	new->x = -3;
	new->y = -3;
	return (fill_node(buf, new));
}

static int		nb_tetri(char *buf)
{
	int		nb_tetri;
	int		i;

	i = 0;
	nb_tetri = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			nb_tetri++;
		i++;
	}
	if ((nb_tetri % 4) != 0)
		return (0);
	return (nb_tetri / 4);
}

int				new_list(char *buf, t_tetr **start)
{
	int		nb;
	int		i;
	int		current;
	t_tetr	*tmp;

	if ((nb = nb_tetri(buf)) == 0)
		return (0);
	tmp = new_node(buf);
	*start = tmp;
	tmp->nbr = 'A';
	i = 1;
	current = 21;
	if (*buf == '\n')
		buf++;
	while (i < nb)
	{
		if (!(tmp->next = new_node(buf + current)))
			return (0);
		tmp = tmp->next;
		tmp->nbr = 'A' + i;
		i++;
		current = current + 21;
	}
	tmp->next = NULL;
	return (nb);
}
