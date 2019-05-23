/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:16:42 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:16:44 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(unsigned int value, int length)
{
	char	*base;
	char	output[sizeof(int) * 2];
	int		i;

	i = 7;
	base = "0123456789abcdef";
	while (value > 0)
	{
		output[i] = base[value % 16];
		value /= 16;
		i--;
	}
	while (i >= 8 - length && i >= 0)
		output[i--] = '0';
	while (i < 8)
		ft_putchar(output[i++]);
}
