/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:09:20 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:09:31 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int	file_cmd(t_sh *sh, t_list *environ, char **cmds)
{
	struct stat stat_;

	if (lstat(cmds[0], &stat_) == -1)
	{
		shell_errors_no_file_directory(cmds[0]);
		return (-1);
	}
	if (S_ISDIR(stat_.st_mode))
	{
		shell_errors_is_directory(cmds[0]);
		return (-1);
	}
	if (access(cmds[0], X_OK) == 0)
		return (shell_launch_cmd(sh, environ, cmds[0], cmds));
	shell_errors_no_file_directory(cmds[0]);
	return (-1);
}

int			shell_launch_cmd(t_sh *sh, t_list *environ, char *cmd,
					char **args)
{
	int					pid;

	if ((pid = fork()) == 0)
		execve(cmd, args, shell_env_from_list(environ));
	else
		waitpid(pid, 0, 0);
	UNUSED(sh);
	return (0);
}

int			shell_boot_cmd(t_sh *sh, t_list *environ, char **cmds)
{
	char	**path;
	char	*tmp;
	int		i;

	path = ft_strsplit(shell_env_get(sh->env_list, "PATH"), ':');
	i = 0;
	if (ft_strchr(cmds[0], '/') != NULL)
		return (file_cmd(sh, environ, cmds));
	while (path && path[i])
	{
		tmp = ft_strfjoin(ft_strjoin(path[i], "/"), cmds[0]);
		if (access(tmp, X_OK) == 0)
		{
			ft_free_tab(path);
			return (shell_launch_cmd(sh, environ, tmp, cmds));
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	shell_errors_not_found(cmds[0]);
	if (path)
		ft_free_tab(path);
	return (-1);
}

int			shell_boot(t_sh *sh, t_list *environ, char **cmds)
{
	if (cmds[0] && shell_is_builtin(sh, cmds))
		return (shell_boot_builtin(sh, environ, cmds));
	else if (cmds[0])
		return (shell_boot_cmd(sh, environ, cmds));
	return (-1);
}
