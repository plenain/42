/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:48:55 by plenain           #+#    #+#             */
/*   Updated: 2018/11/27 13:48:57 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void		*new_ptr;

	if (!ptr || !size)
		return (NULL);
	if (!(new_ptr = ft_strnew(size)))
		return (NULL);
	ft_strcpy(new_ptr, ptr);
	return (new_ptr);
}
