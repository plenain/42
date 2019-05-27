/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:18:51 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:18:53 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putendl_fd(char const *s, int fd)
{
	size_t i;

	i = ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (i + 1);
}