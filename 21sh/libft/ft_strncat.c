/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:13:19 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/11 20:30:24 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char		*ptr;

	ptr = dst;
	while (*dst)
		dst++;
	while (*src && n--)
		*dst++ = *src++;
	*dst = '\0';
	return (ptr);
}
