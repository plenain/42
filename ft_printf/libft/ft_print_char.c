/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:20:42 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:20:44 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c, int amount)
{
	int n;

	n = amount;
	while (n-- > 0)
		ft_putchar(c);
	return (ft_floor(0, amount));
}
