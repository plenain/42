/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:56:55 by plenain           #+#    #+#             */
/*   Updated: 2018/12/17 15:33:01 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char	**tabnew(int size)
{
	char	**tab;
	int		i;

	if (!(tab = (char **)ft_memalloc(sizeof(*tab) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(tab[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static char	**dot_filler(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

static void	free_tab(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putendl(tab[i]);
		ft_strdel(&tab[i]);
		i++;
	}
	ft_memdel((void **)tab);
}

void		printer(t_tetr *ptr, int size)
{
	int		i;
	int		j;
	char	**tab;

	tab = tabnew(size);
	dot_filler(tab, size);
	while (ptr != NULL)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (ptr->tetrimino[i][j] == '#')
				{
					tab[ptr->x + i][ptr->y + j] = ptr->nbr;
				}
				j++;
			}
			i++;
		}
		ptr = ptr->next;
	}
	free_tab(tab, size);
}
