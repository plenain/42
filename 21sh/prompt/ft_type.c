/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:11:42 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 17:42:34 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_prompt.h"

int	is_escape(unsigned long c)
{
	if (c == 23323 || c == 3365659 || c == 3234587 || c == 993090331)
		return (1);
	return (0);
}

int is_in(unsigned long m)
{
	if (UP_KEY == m || m == DD || DOWN_KEY == m || LEFT_KEY == m)
		return (1);
	if (RIGHT_KEY == m || HOME == m  || END == m || m == PD)
		return (1);
	if (m == PU || m== MODE)
		return (1);
	if (m == 77194440301339 || m == 79393463556891)
		return (1);
	return (0);
}

static void ft_vide(t_prompt *a)
{
	a->i = 0;
	a->y = 0;
	ft_memset(a->p,'\0', ESCAPE);
	clean(a, 1);
}

static int notseq(t_prompt *a)
{
	if (a->y > 8)
	{
		ft_vide(a);
		return (0);
	}
	return (1);
}

static int	is_in_escape(t_prompt *a, char c)
{	
	unsigned long num;

	ft_add(a, c);
	num = *(unsigned long *)a->p;
	if ((!(is_escape(num)) && is_in(num)))
	{
		ft_seqence(a, num);
		ft_vide(a);
	}
	else if (!(is_escape(num)) && !(is_in(num)))
		return (notseq(a));
	return (1);
}

int	ft_escape(t_prompt *ar, char c)
{
	return (is_in_escape(ar, c));
}

void	ft_add(t_prompt *ar, char c)
{
	ar->p[ar->y++] = c;
	ar->p[ar->y] = '\0';
	if (ar->y > ESCAPE)
	{
		ft_memset(ar->p, '\0', ESCAPE);
		ar->y = 0;
	}
}

int ft_letter(t_prompt *ar, char c)
{
	if (c == 27 )
	{
		if (ar->read == 1 )
			exit(0);
		if (ar->read != 1 && (ar->i = 1))
			ft_add(ar, c);
	}
	else
		ft_action(ar, c);
	return (0);
}
