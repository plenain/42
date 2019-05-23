/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:19:42 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:19:44 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*destination;
	unsigned char	*source;

	if (n != 0)
	{
		if (dest < src)
			ft_memcpy(dest, src, n);
		else
		{
			destination = (unsigned char*)dest;
			source = (unsigned char*)src;
			i = n;
			while (i-- != 0)
			{
				destination[i] = source[i];
			}
		}
	}
	return (dest);
}
