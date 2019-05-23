/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:04:04 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:04:06 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_bit(int nbr, int idx)
{
	return ((nbr >> idx) & 1);
}

int	ft_get_firstbit(int nbr)
{
	int i;

	i = 0;
	while (nbr > 0)
	{
		if (nbr & 1)
			return (i);
		nbr >>= 1;
		i++;
	}
	return (-1);
}

int	ft_get_lastbit(int nbr)
{
	int i;
	int	last;

	i = 0;
	last = -1;
	while (nbr > 0)
	{
		if (nbr & 1)
			last = i;
		nbr >>= 1;
		i++;
	}
	return (last);
}
