/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:33:16 by plenain           #+#    #+#             */
/*   Updated: 2018/11/06 21:33:43 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	if (nb < 0)
		return (0);
	i = 1;
	while (i < nb / i)
		i++;
	if (i * i == nb)
		return (i);
	else
		return (0);
}
