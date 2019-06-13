/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:01:34 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/19 14:49:30 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *b;

	if (!(b = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(b->content = ft_memdup(content, content_size)))
		{
			free(b);
			return (NULL);
		}
	}
	else
	{
		b->content = NULL;
		content_size = 0;
	}
	b->content_size = content_size;
	b->next = NULL;
	return (b);
}
