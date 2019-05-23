/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:43:53 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 18:43:55 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strcmp(const char *str1, const char *str2)
{
	unsigned int i;

	i = 0;
	if (str1 == str2)
		return (0);
	if (str1 == NULL)
		return (*str2);
	if (str2 == NULL)
		return (*str1);
	while ((unsigned int)(str1[i]) &&
			(unsigned int)(str1[i]) == (unsigned int)(str2[i]))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

unsigned int	ft_strlcmp(const char *str1, const char *str2)
{
	unsigned int i;

	i = 0;
	if (str1 == str2)
		return (0);
	if (str1 == NULL)
		return (*str2);
	if (str2 == NULL)
		return (*str1);
	while ((unsigned int)(str1[i]) &&
			(unsigned int)(str1[i]) == (unsigned int)(str2[i]))
		i++;
	if (str2[i] == 0)
		return (i);
	return (0);
}
