/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_russianpeasant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:48:51 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/15 14:19:22 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_russianpeasant(size_t a, size_t b)
{
	size_t	res;

	res = 0;
	while (b > 1)
	{
		if (b & 1)
			res = res + 1;
		a = a << 1;
		b = b >> 1;
	}
	return (0);
}
