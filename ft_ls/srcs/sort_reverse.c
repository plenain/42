/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:56:34 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:56:36 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_reverse.h"

void	files_reverse(t_files **begin_list)
{
	t_files	*previous;
	t_files	*current;
	t_files	*next;

	if (begin_list == 0 || *begin_list == 0)
		return ;
	previous = 0;
	current = *begin_list;
	while (current != 0)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}

void	folders_reverse(t_folder **begin_list)
{
	t_folder	*previous;
	t_folder	*current;
	t_folder	*next;

	if (begin_list == 0 || *begin_list == 0)
		return ;
	previous = 0;
	current = *begin_list;
	while (current != 0)
	{
		folders_reverse(&current->subfolders);
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}
