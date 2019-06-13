/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 06:29:36 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/13 17:11:17 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *b;
	unsigned char *c;

	b = (unsigned char*)s1;
	c = (unsigned char*)s2;
	while (n)
	{
		if (*b != *c)
			return ((int)*b - (int)*c);
		b++;
		c++;
		n--;
	}
	return (0);
}
