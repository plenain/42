/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:35:43 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 16:35:47 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int		ft_nblen_internal(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static	void	ft_putnbr_buffer(int nb, char *str, int *index)
{
	if (nb == -2147483648)
	{
		ft_strcpy(str, "-2147483648");
		*index = 11;
		return ;
	}
	if (nb < 0)
	{
		str[*index] = '-';
		nb *= -1;
		(*index)++;
	}
	if (nb >= 10)
		ft_putnbr_buffer(nb / 10, str, index);
	str[*index] = nb % 10 + '0';
	(*index)++;
}

char			*ft_itoa(int n)
{
	char	*tmp;
	int		index;

	tmp = (char *)malloc(ft_nblen_internal(n) + 1);
	if (!tmp)
		return (NULL);
	*tmp = '\0';
	index = 0;
	if (!tmp)
		return (NULL);
	ft_putnbr_buffer(n, tmp, &index);
	tmp[index] = '\0';
	return (tmp);
}
