/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:20:10 by plenain           #+#    #+#             */
/*   Updated: 2019/09/26 17:20:14 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}
