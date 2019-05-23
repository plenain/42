/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:09:17 by plenain           #+#    #+#             */
/*   Updated: 2019/04/15 21:09:19 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "utils.h"
#include "libft.h"
#include "commands.h"
#include "constants.h"

char	*build_command(char *prefix, char *command, unsigned int prefix_len,
						unsigned int cmdlen)
{
	char	*output;

	if ((output = ft_strnew(prefix_len + cmdlen + 1)) == NULL)
		return (NULL);
	ft_memcpy(output, prefix, prefix_len);
	output[prefix_len] = '/';
	ft_memcpy(output + prefix_len + 1, command, cmdlen + 1);
	return (output);
}

char	*find_command(char *command, char *path)
{
	unsigned int	i;
	unsigned int	cmdlen;
	char			*final_command;

	if (ft_cfind(command, '/') != -1)
		return (exists(command) ? command : "");
	cmdlen = ft_strlen(command);
	while (path && *path != '\0')
	{
		i = 0;
		while (path[i] != '\0' && path[i] != ':')
			++i;
		if (!(final_command = build_command(path, command, i, cmdlen)))
			return (NULL);
		if (exists(final_command))
			return (final_command);
		ft_strdel(&final_command);
		if (path[i] == '\0')
			break ;
		path += i + 1;
	}
	return ("");
}

int		start_child_process(t_shell *shell, char **args, char *command)
{
	if (!(is_executable(command)))
	{
		ft_printf_fd(2, SHELL_NAME": permission denied: %s\n", command);
		return (0);
	}
	if (fork() == 0)
		return (execve(command, args, shell->env));
	else
	{
		if (command != args[0])
			ft_strdel(&command);
		shell->running_command = 1;
		wait(0);
		shell->running_command = 0;
	}
	return (0);
}

int		exec_command(t_shell *shell, char **args)
{
	char	*command;

	if (args == NULL || *args == NULL || **args == '\0'
		|| exec_builtin(args[0], args, shell) != -1)
		return (0);
	if (!(command = find_command(args[0], get_env_var("PATH", shell->env))))
		return (0);
	if (command[0] == '\0')
	{
		if (is_dir(args[0]))
			cd(shell, args[0]);
		else
			ft_printf_fd(2, SHELL_NAME": command not found: %s\n", args[0]);
		return (0);
	}
	return (start_child_process(shell, args, command));
}
