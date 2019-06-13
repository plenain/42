/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:39:45 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/12 19:21:58 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len(int n)
{
	int	b;

	b = 1 + (n < 0);
	while ((n /= 10))
		b++;
	return (b);
}

static	int		ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

static void		make(char *b, int n, int i)
{
	while (i)
	{
		b[i - 1] = ft_abs(n % 10) + '0';
		n = n / 10;
		i--;
	}
}

char			*ft_itoa(int n)
{
	char	*b;
	int		i;
	int		c;

	c = 0;
	i = len(n);
	if ((b = malloc(sizeof(*b) * (i + 1))))
	{
		b[0] = '0';
		if (n < 0 && i--)
			b[c++] = '-';
		if (n)
			make(&b[c], n, i);
		return (b);
	}
	return ((void *)0);
}
