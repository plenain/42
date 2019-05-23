/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:25:39 by plenain           #+#    #+#             */
/*   Updated: 2019/02/05 20:26:51 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t		ft_putstr(char const *s)
{
	size_t len;

	if (s == NULL)
		return (ft_putstr("(null)"));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
