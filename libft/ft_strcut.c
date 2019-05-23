/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:17:26 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 19:17:36 by plenain          ###   ########.fr       */
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
