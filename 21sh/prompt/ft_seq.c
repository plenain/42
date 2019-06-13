/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:41:26 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/08 20:31:57 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_21.h"

int ft_up(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}

int ft_down(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}

int ft_left(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	if (ar->oui)
		ar->oui--;
	return (1);
}

int ft_right(t_prompt *ar, unsigned long c)
{

	if (ar->i && c)
		;
	if (ar->oui < ft_strlen(ar->com))
		ar->oui++;
	return (1);
}
