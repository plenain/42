/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 06:05:14 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/11 20:18:57 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*b;

	b = (unsigned char*)s;
	while (n--)
	{
		if (*b == ((unsigned char)c))
			return (b);
		b++;
	}
	return ((void *)0);
}
