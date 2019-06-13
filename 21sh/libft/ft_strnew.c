/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:33:45 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/12 18:59:32 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	char *o;

	if ((str = ft_memalloc(size + 1)))
	{
		o = str;
		while (*str)
			*str++ = '\0';
		*str = '\0';
		return (o);
	}
	return ((void *)0);
}
