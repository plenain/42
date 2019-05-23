/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:07:39 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:07:55 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	cmp;
	unsigned char	*dst;
	unsigned char	*source;

	if (n != 0)
	{
		i = 0;
		cmp = (unsigned char)c;
		dst = (unsigned char*)dest;
		source = (unsigned char*)src;
		while (i < n)
		{
			dst[i] = source[i];
			if (source[i] == cmp)
				return (dst + i + 1);
			i++;
		}
	}
	return (NULL);
}
