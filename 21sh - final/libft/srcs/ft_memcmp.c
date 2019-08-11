/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:43:00 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:43:02 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			i;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*s1_ptr == *s2_ptr && i < (n - 1))
	{
		s1_ptr++;
		s2_ptr++;
		i++;
	}
	return (*(unsigned char *)s1_ptr - *(unsigned char *)s2_ptr);
}
