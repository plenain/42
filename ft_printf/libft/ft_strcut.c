/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:30:28 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:30:30 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int start, int end)
{
	int		len;

	if (str == NULL || start < 0 || end <= start)
		return (NULL);
	len = ft_strlen(str);
	if (start >= len || end > len)
		return (NULL);
	ft_strcpy(str + start, str + end);
	return (str);
}
