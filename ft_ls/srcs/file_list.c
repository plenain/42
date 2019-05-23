/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:54:03 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:54:07 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "libft.h"
#include "file_list.h"
#include <stdlib.h>

t_files		*file_lst_new(char *name, char *prefix)
{
	t_files *tmp;

	if (!prefix || (tmp = (t_files*)ft_memalloc(sizeof(t_files))) == NULL)
	{
		ft_strdel(&prefix);
		return (NULL);
	}
	if ((tmp->name = ft_strdup(name)) == NULL)
	{
		ft_strdel(&prefix);
		free(tmp);
		return (NULL);
	}
	tmp->prefix = prefix;
	if ((tmp->fullpath = ft_strjoin(prefix, name)) == NULL)
	{
		ft_strdel(&prefix);
		free(tmp);
		return (NULL);
	}
	tmp->exists = 1;
	return (tmp);
}

void		files_lst_push(int flags, t_files **begin, t_files *file)
{
	t_files	*curr;
	t_files	*prev;

	curr = *begin;
	prev = NULL;
	if (flags & FLAG_NON_SORT && (flags & NOTFLAG_FIRST) == 0)
		while (curr)
		{
			prev = curr;
			curr = curr->next;
		}
	else if ((flags & FLAG_NON_SORT) == 0)
		while (curr && ft_strcmp(curr->name, file->name) < 0)
		{
			prev = curr;
			curr = curr->next;
		}
	file->next = (prev != NULL ? prev->next : curr);
	if (prev == NULL)
		*begin = file;
	else
		prev->next = file;
}

t_folder	*folder_lst_new(char *name, char *prefix)
{
	t_folder *tmp;

	if (!prefix || (tmp = (t_folder*)ft_memalloc(sizeof(t_folder))) == NULL)
		return (NULL);
	if ((tmp->name = ft_strdup(name)) == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tmp->prefix = prefix;
	if ((tmp->fullpath = ft_strjoin(prefix, name)) == NULL)
	{
		ft_strdel(&prefix);
		free(tmp);
		return (NULL);
	}
	tmp->exists = 1;
	return (tmp);
}

void		folder_lst_push(int flags, t_folder **begin, t_folder *folder)
{
	t_folder	*curr;
	t_folder	*prev;

	curr = *begin;
	prev = NULL;
	if (flags & FLAG_NON_SORT && (flags & NOTFLAG_FIRST) == 0)
		while (curr)
		{
			prev = curr;
			curr = curr->next;
		}
	else if ((flags & FLAG_NON_SORT) == 0)
		while (curr && ft_strcmp(curr->name, folder->name) < 0)
		{
			prev = curr;
			curr = curr->next;
		}
	folder->next = (prev != NULL ? prev->next : curr);
	if (prev == NULL)
		*begin = folder;
	else
		prev->next = folder;
}
