/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:26:02 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/14 20:56:03 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddend(t_list **ab, t_list *l)
{
	t_list *b;
	t_list *g;

	if (!(*ab))
		return (NULL);
	if (!(l))
		return (*ab);
	b = *ab;
	g = b;
	while (b->next)
		b = b->next;
	b->next = l;
	return (g);
}
