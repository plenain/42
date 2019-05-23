/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:15:27 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:15:30 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_power(int nb, int power)
{
	long	result;

	result = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
