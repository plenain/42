/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:45:29 by plenain           #+#    #+#             */
/*   Updated: 2018/11/27 15:45:31 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(char *s, char c, int offset)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (s + i + offset);
	return (NULL);
}