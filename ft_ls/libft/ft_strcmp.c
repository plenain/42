/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:29:51 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:29:54 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strcmp(const char *str1, const char *str2)
{
	unsigned int i;

	i = 0;
	if (str1 == str2)
		return (0);
	if (str1 == 0 || str2 == 0)
		return (-1);
	while ((unsigned int)(str1[i]) &&
			(unsigned int)(str1[i]) == (unsigned int)(str2[i]))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
