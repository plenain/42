/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbeetwin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:32:03 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/14 14:45:35 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstbeetwin(t_list **start, t_list *new)
{
	t_list	*b;

	if (*start)
	{
		b = *start;
		new->next = b->next;
		b->next = new;
		*start = b;
	}
}
