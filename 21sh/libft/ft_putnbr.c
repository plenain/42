/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 04:29:31 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/12 19:05:39 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n / 10)
	{
		ft_putnbr(ft_abs(n / 10));
		ft_putchar(ft_abs(n % 10) + '0');
	}
	else
		ft_putchar(ft_abs(n % 10) + '0');
}
