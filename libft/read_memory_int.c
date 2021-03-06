/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_memory_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:45:01 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 19:45:03 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		read_char(void *n)
{
	return (*(char*)n);
}

short		read_short(void *n)
{
	return (*(short*)n);
}

int			read_int(void *n)
{
	return (*(int*)n);
}

long		read_long(void *n)
{
	return (*(long*)n);
}

long long	read_llong(void *n)
{
	return (*(long long*)n);
}
