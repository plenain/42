/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:39:35 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 16:39:38 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstget_at(t_list *lst, int at)
{
	int i;

	i = 0;
	while (lst)
	{
		if (i == at)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
