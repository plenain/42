/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:33:29 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 18:33:31 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t		ft_putstr_non_printable(char *str)
{
	size_t	i;

	if (str == NULL)
		return (ft_putstr("(null)"));
	else
	{
		i = 0;
		while (str[i])
		{
			if (str[i] < 32 || str[i] > 126)
			{
				ft_putchar('\\');
				ft_print_hex(str[i], 2);
			}
			else
				ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}
