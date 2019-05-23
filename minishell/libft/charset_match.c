/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charset_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:48:04 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 20:48:06 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		charset_match(char *charset, char *str)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (charset[i] && charset[i] == *str)
			++i;
		if (charset[i] != '\0')
			return (0);
		++str;
	}
	return (1);
}

int		charset_unmatch(char *charset, char *str)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (charset[i] && charset[i] != *str)
			++i;
		if (charset[i] != '\0')
			return (0);
		++str;
	}
	return (1);
}
