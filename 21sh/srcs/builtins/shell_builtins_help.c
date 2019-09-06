/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:13:12 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:13:17 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		shell_builtins_help(void *sh_, t_list *environ, char **cmds)
{
	UNUSED(sh_);
	UNUSED(cmds);
	UNUSED(environ);
	ft_putendl("help:\n");
	ft_putendl("builtins:");
	ft_putendl("cd [-LP] [path]");
	ft_putendl("pwd [-LP]");
	ft_putendl("exit [code]");
	ft_putendl("env [-i] [var=value, ...] [cmd]");
	ft_putendl("setenv [var] [value]");
	ft_putendl("unsetenv [var]");
	return (0);
}
