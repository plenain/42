/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:56:15 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/15 12:39:57 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s1, size_t n)
{
	void	*b;

	if (s1 && n > 0)
	{
		if (!(b = ft_memalloc(n)))
			return (NULL);
		return (ft_memcpy(b, s1, n));
	}
	return (NULL);
}
