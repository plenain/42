/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:51:27 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:51:29 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int		ft_strcut(char **s1, char **s2, char c)
{
	char	*tmp;
	char	*ret;
	size_t	len;

	len = 0;
	ret = ft_strdup(*s2);
	while (ret[len] && ret[len] != c)
		len++;
	ret[len] = 0;
	*s1 = ret;
	tmp = ft_strsub(*s2, ft_strlen(*s1) + 1, ft_strlen(*s2) - ft_strlen(*s1));
	if (s2 && *s2)
		free(*s2);
	*s2 = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	return (1);
}
