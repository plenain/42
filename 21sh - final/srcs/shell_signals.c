/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:10:54 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:11:00 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		shell_signals_reprompt(int i)
{
	t_sh *sh;

	i = 0;
	sh = shell_recover();
	if (!sh->signals_disabled)
	{
		shell_prompt_display(0);
		shell_prompt_add_new();
		ft_putstr("\n");
		shell_prompt_display(1);
	}
}

static void		shell_signals_exit(int i)
{
	i = 0;
	shell_exit();
}

static void		shell_signals_resize(int i)
{
	i = 0;
	shell_prompt_update_window();
	shell_prompt_display(1);
}

static void		shell_signals_handler(int i)
{
	if (i == SIGWINCH)
		shell_signals_resize(i);
	else if (i == SIGINT)
		shell_signals_reprompt(i);
	else if (i == SIGQUIT)
		shell_signals_exit(i);
}

void			shell_signals(void)
{
	signal(SIGINT, shell_signals_handler);
	signal(SIGQUIT, shell_signals_handler);
	signal(SIGWINCH, shell_signals_handler);
}
