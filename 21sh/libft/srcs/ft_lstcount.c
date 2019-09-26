/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:37:17 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 16:37:21 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	ft_lstcount(t_list *list)
{
	int		count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}
