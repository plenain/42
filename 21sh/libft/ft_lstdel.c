/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:34:04 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/14 19:12:33 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *b;
	t_list *c;

	if (*alst)
	{
		c = *alst;
		while ((b = c))
		{
			del(b->content, b->content_size);
			c = c->next;
			free(b);
		}
		*alst = NULL;
	}
}
