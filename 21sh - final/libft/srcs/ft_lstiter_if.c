/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:40:54 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:40:55 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstiter_if(t_list *lst, void (*f)(t_list *e), int (*g)(t_list *e))
{
	while (lst)
	{
		if (g(lst))
			f(lst);
		lst = lst->next;
	}
}