/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:40:35 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:40:37 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtoupper(char *string)
{
	unsigned int	i;

	i = 0;
	while (string[i])
	{
		string[i] = ft_toupper(string[i]);
		i++;
	}
	return (string);
}
