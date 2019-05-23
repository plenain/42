/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:11:14 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:11:15 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*src;

	if (num != 0)
	{
		i = 0;
		dest = (unsigned char*)destination;
		src = (unsigned char*)source;
		while (i < num)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (destination);
}
