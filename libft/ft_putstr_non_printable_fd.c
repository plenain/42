/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable_fd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:40:32 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 18:40:34 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_putnstr_non_printable_fd(char *str, size_t n, int fd)
{
	size_t	i;

	if (str == NULL)
		return (ft_putnstr_fd("(null)", n, fd));
	else
	{
		i = 0;
		while (str[i] && i < n)
		{
			if (str[i] < 32 || str[i] > 126)
			{
				ft_putchar_fd('\\', fd);
				ft_print_hex_fd(str[i], 2, fd);
			}
			else
				ft_putchar_fd(str[i], fd);
			i++;
		}
	}
	return (i);
}
