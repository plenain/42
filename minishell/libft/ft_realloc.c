/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:40:51 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 18:40:53 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int newsize)
{
	char *output;

	output = ft_strnew(newsize);
	if (output)
		ft_strlcpy(output, str, newsize + 1);
	ft_strdel(&str);
	return (output);
}
