/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:52:45 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/17 14:07:00 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	y;
	char			*k;

	k = dst;
	i = ft_strlen(dst);
	dst = dst + i;
	y = ft_strlen(src);
	if (i > size || size == 0)
		y = y + size;
	else
		y = y + i;
	while (*src && (++i < size))
		*dst++ = *src++;
	*dst = '\0';
	dst = k;
	return (y);
}
