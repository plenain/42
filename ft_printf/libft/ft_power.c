/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:20:26 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:20:28 by plenain          ###   ########.fr       */
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
