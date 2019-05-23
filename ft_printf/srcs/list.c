/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:54:42 by plenain           #+#    #+#             */
/*   Updated: 2019/02/12 18:37:24 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

t_spec	*spec_lst_new(int idx)
{
	t_spec	*tmp;

	if ((tmp = (t_spec*)ft_memalloc(sizeof(t_spec))) == NULL)
		return (NULL);
	ft_bzero(tmp, sizeof(t_spec));
	tmp->print = 1;
	tmp->idx = idx;
	tmp->fd = 1;
	return (tmp);
}

void	spec_lst_push(t_spec **begin_list, t_spec *spec)
{
	t_spec *tmp;

	if (begin_list == NULL)
		return ;
	if (*begin_list == NULL)
		*begin_list = spec;
	else
	{
		tmp = *begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = spec;
	}
}

void	spec_lst_clear(t_spec *lst)
{
	t_spec	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		ft_strdel(&(tmp->minlen));
		ft_strdel(&(tmp->maxlen));
		free(tmp);
	}
}
