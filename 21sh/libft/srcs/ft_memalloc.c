/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:49:02 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 16:49:04 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
