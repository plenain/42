/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:36:24 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:36:27 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *destination, const char *source)
{
	int i;
	int offset;

	offset = 0;
	while (destination[offset] != '\0')
		offset++;
	i = 0;
	while (source[i] != '\0')
	{
		destination[offset + i] = source[i];
		i++;
	}
	destination[offset + i] = '\0';
	return (destination);
}
