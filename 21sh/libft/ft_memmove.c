/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:54:36 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/14 21:03:48 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *destination;
	unsigned char *source;

	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (dst < src)
		destination = ft_memcpy(destination, source, len);
	else
	{
		source = (unsigned char*)src + len - 1;
		destination = (unsigned char*)dst + len - 1;
		while (len--)
			*destination-- = *source--;
	}
	return (dst);
}
