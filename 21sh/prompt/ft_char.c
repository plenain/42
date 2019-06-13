/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:49:16 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 19:12:15 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_21.h"

int ft_ctrld(t_prompt *ar, char c)
{
	if (ar->i && c)
		;
	return (1);
}

int ft_enter(t_prompt *ar, char c)
{
	char *cpy;

	if (ar->i && c)
		;
	if (ar->com)
	{
		cpy = ft_strdup(ar->com);
		reset();
		free(cpy);
	}
	return (1);
}

int ft_del(t_prompt *ar, char c)
{
	if (ar->i && c)
		;
	return (1);
}
int ft_tab(t_prompt *ar, char c)
{
	if (ar->i && c)
		;
	return (1);
}
