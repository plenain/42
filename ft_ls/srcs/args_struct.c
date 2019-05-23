/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:53:38 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:53:41 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "args_struct.h"

t_args	*new_args(void)
{
	t_args	*new;

	if ((new = (t_args*)ft_memalloc(sizeof(t_args))) == NULL)
		return (NULL);
	return (new);
}
