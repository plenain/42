/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:19:58 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:20:00 by plenain          ###   ########.fr       */
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
