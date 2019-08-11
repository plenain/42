/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:56:16 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:56:18 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	ptr = ptr + ft_strlen(ptr);
	while (*ptr != (char)c && ptr != s)
		ptr--;
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}
