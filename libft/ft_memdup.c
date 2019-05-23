/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:14:31 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:14:33 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void					*ft_memdup(const void *src, size_t size)
{
	char	*out;

	if (size == 0 || (out = malloc(size)) == 0)
		return (NULL);
	ft_memcpy(out, src, size);
	return (out);
}
