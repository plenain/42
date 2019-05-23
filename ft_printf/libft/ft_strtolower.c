/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:40:08 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:40:10 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtolower(char *string)
{
	unsigned int	i;

	i = 0;
	while (string[i])
	{
		string[i] = ft_tolower(string[i]);
		i++;
	}
	return (string);
}
