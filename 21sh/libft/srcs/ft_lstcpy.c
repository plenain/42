/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:37:36 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 16:37:39 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstcpy(t_list **dest, t_list *src)
{
	while (src)
	{
		ft_lstadd(dest, ft_lstnew(src->content, src->content_size));
		src = src->next;
	}
}
