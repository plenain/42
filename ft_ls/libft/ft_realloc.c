/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:28:23 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:28:25 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_realloc(void *ptr, size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)malloc(size);
	if (tmp != NULL)
	{
		ft_memcpy(tmp, ptr, size);
		free(ptr);
	}
	return (tmp);
}
