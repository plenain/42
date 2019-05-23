/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:32:31 by plenain           #+#    #+#             */
/*   Updated: 2019/05/20 17:43:17 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "utils.h"
#include "shell.h"
#include "commands.h"
#include "constants.h"
#include "parsing.h"

void	exec_line_command(t_shell *shell, char *cmd)
{
	char	**args;

	if (ft_strlen(cmd) >= BUF_SIZE)
		if ((shell->buf = ft_realloc(shell->buf, ft_strlen(cmd))) == NULL)
			return ;
	ft_strcpy(shell->buf, cmd);
	if ((args = parse_input(shell->buf, shell)) == NULL)
		return ;
	exec_command(shell, args);
	ft_free_tab(args);
}

void	exec_file(t_shell *shell, char *file)
{
	int		fd;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(2, "source: error: could not read file %s\n", file);
		return ;
	}
	buf = NULL;
	while (get_next_line(fd, &buf) == 1)
	{
		exec_line_command(shell, buf);
		ft_strdel(&buf);
	}
	return ;
	ft_strdel(&buf);
	close(fd);
}

void	b_export2(t_shell *shell, char *var)
{
	int		i;
	char	*tmp;

	i = ft_cfind(var, '=');
	if (i == -1)
	{
		tmp = get_env_var(var, shell->env);
		if (tmp != NULL)
			ft_printf("%s=%s\n", var, tmp);
		return ;
	}
	if (i == 0)
		return ;
	var[i] = '\0';
	set_env_var(var, var + i + 1, shell);
}

void	cd(t_shell *shell, char *folder)
{
	if (chdir(folder) == 0)
	{
		set_env_var("OLDPWD", get_env_var("PWD", shell->env), shell);
		set_env_var("PWD", shell->pwd, shell);
		get_cwd(shell, 1);
	}
	else if (*folder == '-')
	{
		set_env_var("_", get_env_var("PWD", shell->env), shell);
		set_env_var("PWD", get_env_var("OLDPWD", shell->env), shell);
		cd(shell, get_env_var("PWD", shell->env));
		set_env_var("OLDPWD", get_env_var("_", shell->env), shell);
	}
	else
		ft_printf_fd(2, "cd: permission denied: %s\n", folder);
}
