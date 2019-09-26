/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:38:17 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 16:38:24 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstdel_at(t_list **list, int at, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*prev;
	int		count;

	if (!list || !(*list))
		return ;
	tmp = *list;
	prev = NULL;
	count = 0;
	while (count != at && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		count++;
	}
	if (count == at)
	{
		if (prev)
			prev->next = tmp->next;
		else
			*list = tmp->next;
		del(tmp->content, tmp->content_size);
	}
}
