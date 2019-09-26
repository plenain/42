/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:18:58 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 17:19:02 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*ret;
	size_t	i;

	ret = dst;
	i = 0;
	while (*src && i < n)
	{
		*dst = *src;
		i++;
		src++;
		dst++;
	}
	while (i < n)
	{
		*dst = '\0';
		dst++;
		i++;
	}
	return (ret);
}
