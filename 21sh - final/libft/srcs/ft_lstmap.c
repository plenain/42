/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:41:10 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:41:12 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*prv_elm;

	if (!lst || !f)
		return (NULL);
	new_lst = f(lst);
	prv_elm = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		prv_elm->next = tmp;
		prv_elm = tmp;
		lst = lst->next;
	}
	prv_elm->next = NULL;
	return (new_lst);
}
