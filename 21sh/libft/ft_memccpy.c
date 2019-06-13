/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:25:54 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/13 16:54:10 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *source;

	source = (unsigned char *)src;
	while (n--)
	{
		ft_memset(dst++, *source, 1);
		if (*source++ == (unsigned char)c)
			return (dst);
	}
	return (void *)0;
}
