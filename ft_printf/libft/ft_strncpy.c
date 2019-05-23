/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:37:21 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:37:23 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t num)
{
	unsigned int i;

	i = 0;
	while (source[i] != '\0' && i < num)
	{
		destination[i] = source[i];
		i++;
	}
	while (i < num)
	{
		destination[i] = '\0';
		i++;
	}
	return (destination);
}
