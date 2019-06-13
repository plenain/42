/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signaux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:45:15 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 15:39:35 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21.h"
#include <stdio.h>

extern t_data *g_data;

void reset()
{
	g_data->t.y = 0;
	g_data->t.i = 0;
	g_data->t.pos = 0;
	g_data->t.read = 0;
	ft_memset(g_data->t.p,'\0', ESCAPE);
	ft_memset(g_data->t.c, '\0', 2);
	g_data->t.oui = 0;
	free(g_data->t.com);
	g_data->t.com = NULL;
}

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		reset();
		exit(0);
	}
}

void		grab_sign(void)
{
	int	i;

	i = 0;
	while (i < NSIG)
	{
		if (signal(i, sig_handler) == SIG_ERR)
			ft_putstr("");
		i++;
	}
}
