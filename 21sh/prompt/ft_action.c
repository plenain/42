/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:49:04 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 18:17:03 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_21.h"

static int	ft_not(t_prompt *a, unsigned long c)
{
	if (a && c)
		;
	return (1);
}

static int ft_starter(t_prompt *ar, char c)
{
	int  i;
	t_action b[4] = {
		{CTRLD, ft_ctrld},
		{ENTER, ft_enter},
		{DEL, ft_del},
		{TAB, ft_tab}
	};

	if (ar->i)
		;
	i = 0;
	while (i < 4)
		if (b[i++].d == c)
			return (b[i - 1].ptf(ar, c));
	return (0);
}

int	ft_seqence(t_prompt *ar, unsigned long  c)
{
	int i;
	t_seq b[11] = {
		{UP_KEY, ft_up},
		{DOWN_KEY, ft_down},
		{LEFT_KEY, ft_left},
		{RIGHT_KEY, ft_right},
		{DD, ft_dd},
		{HOME, ft_home},
		{END, ft_end},
		{PU, ft_pu},
		{PD, ft_pd},
		{NOT, ft_not},
		{NIT, ft_not}
	};

	i = 0;
	while (i < 11)
		if (b[i++].d == c)
			return (b[i - 1].ptf(ar, c));
	return (0);
}

void ft_action(t_prompt *ar, char c)
{
	if (ft_starter(ar, c))
		;
	else
		ft_alpha(ar, c);
}
