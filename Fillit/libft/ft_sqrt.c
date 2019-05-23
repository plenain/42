/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:14:50 by plenain           #+#    #+#             */
/*   Updated: 2018/12/13 17:14:54 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;
	int		a;
	int		n;

	i = 0;
	n = 1;
	a = 0;
	while (a != nb)
	{
		if (i > 46340 || nb >= 2147483647)
			return (0);
		a = a + n;
		n = n + 2;
		i++;
	}
	return (i);
}