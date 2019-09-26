/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:36:35 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 16:36:38 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_at(t_list **lst, t_list *new, int at)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = *lst;
	while (i <= (at - 1))
	{
		tmp = tmp->next;
		if (tmp == NULL)
			break ;
		i++;
	}
	if (tmp != NULL)
	{
		new->next = tmp->next;
		tmp->next = new;
	}
	else
	{
		ft_lstadd(lst, new);
	}
}
