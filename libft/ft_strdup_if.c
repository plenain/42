/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:30:00 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 19:30:02 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup_if(const char *s, int (*f)(int))
{
	int		i;
	int		len;
	char	*output;

	len = 0;
	while (s[len] && f(s[len]))
		len++;
	output = (char*)malloc(len + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = s[i];
		i++;
	}
	output[len] = '\0';
	return (output);
}
