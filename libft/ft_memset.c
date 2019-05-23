/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:14:51 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:14:53 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *ptr, int value, size_t num)
{
	while (num-- != 0)
	{
		((unsigned char*)ptr)[num] = value;
	}
	return (ptr);
}
