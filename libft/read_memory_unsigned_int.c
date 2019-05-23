/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_memory_unsigned_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:45:14 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 19:45:16 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char		read_uchar(void *n)
{
	return (*(unsigned char*)n);
}

unsigned short		read_ushort(void *n)
{
	return (*(unsigned short*)n);
}

unsigned int		read_uint(void *n)
{
	return (*(unsigned int*)n);
}

unsigned long		read_ulong(void *n)
{
	return (*(unsigned long*)n);
}

unsigned long long	read_ullong(void *n)
{
	return (*(unsigned long long*)n);
}
