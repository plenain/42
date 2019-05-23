/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:19:36 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:19:38 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned int nbr, unsigned int base)
{
	if (base > 16 || base <= 1)
		base = 16;
	if (nbr >= base)
		ft_putnbr_base(nbr / base, base);
	ft_putchar(BASE_HEX[nbr % base]);
}
