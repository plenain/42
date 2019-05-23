/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:41:56 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 19:41:58 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int i2;

	i = 0;
	while (str1[i] != '\0')
	{
		i2 = 0;
		while (str1[i + i2] == str2[i2] && str1[i + i2])
			i2++;
		if (str2[i2] == '\0')
			return ((char*)str1 + i);
		i++;
	}
	if (str1[0] == '\0' && str2[0] == '\0')
		return ((char*)str1);
	return (NULL);
}
