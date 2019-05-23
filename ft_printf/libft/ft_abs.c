/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:11:17 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:11:21 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

unsigned int	ft_abs(int value)
{
	if (value == INT_MIN)
		return ((unsigned int)INT_MAX + 1);
	return (value > 0 ? value : -value);
}
