/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:16:45 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 17:16:47 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new_str;

	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	ft_strcat(new_str, s1);
	ft_strcat(new_str, s2);
	return (new_str);
}
