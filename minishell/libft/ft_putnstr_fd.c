/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:08:04 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 18:08:07 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t		ft_putnstr_fd(char *str, size_t n, int fd)
{
	size_t i;

	if (str == NULL)
		return (ft_putnstr_fd("(null)", n, fd));
	i = 0;
	while (str[i] && i < n)
		i++;
	write(fd, str, i);
	return (i);
}
