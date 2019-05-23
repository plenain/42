/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:56:20 by plenain           #+#    #+#             */
/*   Updated: 2018/12/17 15:32:10 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	check_pos3(int x, int y, t_tetr *current)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (current->tetrimino[i][j] == '#')
			{
				if ((current->x + i == x)
					&& (current->y + j == y))
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_pos(t_tetr *tetr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr->tetrimino[i][j] == '#')
				if ((i + tetr->x) >= size || (j + tetr->y) >= size
					|| (i + tetr->x) < 0 || (j + tetr->y) < 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_pos2(t_tetr *start, t_tetr *tetr)
{
	int		i;
	int		j;
	t_tetr	*current;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr->tetrimino[i][j] == '#')
			{
				current = start;
				while (current->nbr != tetr->nbr)
				{
					if (!(check_pos3(tetr->x + i, tetr->y + j, current)))
						return (0);
					current = current->next;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			backtrack_tetr(t_tetr *start, t_tetr *tetr, int size)
{
	int		i;
	int		j;

	i = -3;
	while (i < size)
	{
		j = -3;
		while (j < size)
		{
			tetr->x = i;
			tetr->y = j;
			if (check_pos(tetr, size) == 1
				&& check_pos2(start, tetr) == 1)
			{
				if ((tetr->next) == NULL)
					return (1);
				if ((backtrack_tetr(start, tetr->next, size)) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
