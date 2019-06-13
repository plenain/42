/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:47:21 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/14 19:30:23 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*b;

	if (lst && f)
	{
		b = lst;
		if (!(b = f(lst)))
			return (NULL);
		b->next = ft_lstmap(lst->next, f);
		return (b);
	}
	return (NULL);
}
