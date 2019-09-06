/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins_pwd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:13:35 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:13:36 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int	shell_builtins_pwd(void *sh_, t_list *environ, char **cmds)
{
	t_sh				*sh;
	char				path[PATH_MAX];
	t_generic_options	options;

	sh = (t_sh *)sh_;
	options = shell_builtins_options_parser(cmds, "LP");
	if (options.error)
	{
		ft_putstr_fd("bad option: -", 2);
		ft_putchar_fd(options.error_char, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	if (ft_is_in(options.options, 'P') && !ft_is_in(options.options, 'L') &&
		*shell_env_get(environ, "PWD") == '/')
		ft_putendl(shell_env_get(environ, "PWD"));
	else
	{
		getcwd(path, PATH_MAX);
		ft_putendl(path);
	}
	return (0);
}
