/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:34:44 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 19:34:46 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *s)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t			ft_strclen(const char *s, char c)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}
