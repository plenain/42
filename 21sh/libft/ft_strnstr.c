/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 08:31:33 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/14 19:02:20 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*c;

	c = (char *)needle;
	if (haystack == needle)
		return ((char *)haystack);
	if (*haystack && len)
		while (len && *haystack)
		{
			if (len >= ft_strlen(c))
				if (ft_memcmp(haystack, c, ft_strlen(c)) == 0)
					return ((char *)haystack);
			haystack++;
			len--;
		}
	return (NULL);
}
