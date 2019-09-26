/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:18:03 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 17:18:06 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_ptr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	new_ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_ptr)
		return (NULL);
	while (s[i])
	{
		new_ptr[i] = f(i, s[i]);
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}
