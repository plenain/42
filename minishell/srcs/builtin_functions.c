/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:07:39 by plenain           #+#    #+#             */
/*   Updated: 2019/05/15 23:37:36 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "commands.h"
#include "constants.h"

void	b_env(t_shell *shell, char **args)
{
	unsigned int i;

	if (args[1] != NULL)
	{
		b_export(shell, args);
		return ;
	}
	i = 0;
	while (shell->env[i])
	{
		ft_putendl(shell->env[i]);
		++i;
	}
}

void	b_alias_list(t_shell *shell, char **args)
{
	int		i;

	(void)args;
	i = 0;
	while (shell->alias && shell->alias[i])
	{
		ft_putendl(shell->alias[i]);
		++i;
	}
	if (i == 0)
		ft_putendl(SHELL_NAME": No alias set.");
}

void	b_alias(t_shell *shell, char **args)
{
	int		i;
	char	*tmp;

	if (args[1] == 0)
	{
		b_alias_list(shell, args);
		return ;
	}
	i = ft_cfind(args[1], '=');
	if (i == -1)
	{
		tmp = get_env_var(args[1], shell->alias);
		if (tmp != NULL)
			ft_printf("%s=%s\n", args[1], tmp);
		return ;
	}
	args[1][i] = '\0';
	if (charset_unmatch(FORBIDDEN_ALIAS_CHARS, args[1]))
		set_env_var(args[1], args[1] + i + 1, (t_shell*)&shell->alias);
	else
		ft_putstr_fd("Error: Alias name contains forbidden characters.\n", 2);
}

void	b_setenv(t_shell *shell, char **args)
{
	if (args[1] != NULL && args[2] != NULL)
		set_env_var(args[1], args[2], shell);
	else
		ft_putstr_fd("Usage: setenv NAME VALUE\n", 2);
}

void	b_unsetenv(t_shell *shell, char **args)
{
	if (args[1] != NULL)
		remove_env_var(args[1], shell->env);
	else
		ft_putstr_fd("Usage: unsetenv NAME\n", 2);
}
