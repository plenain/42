/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:12:05 by plenain           #+#    #+#             */
/*   Updated: 2019/05/20 17:43:56 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "constants.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

char	*concat_env_string(char *name, char *value)
{
	unsigned int	len;
	char			*output;

	len = ft_strlen(name);
	if ((output = ft_strnew(len + 1 + ft_strlen(value))) == NULL)
		return (NULL);
	ft_memcpy(output, name, len);
	output[len] = '=';
	ft_strcpy(output + len + 1, value);
	return (output);
}

int		exists(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (!S_ISDIR(f_stat.st_mode));
}

int		is_executable(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (!S_ISDIR(f_stat.st_mode) && (f_stat.st_mode & S_IXUSR));
}

int		is_dir(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (S_ISDIR(f_stat.st_mode));
}

char	*get_cwd(t_shell *shell, int realloc)
{
	int		i;
	int		last;
	char	buf[512];

	i = 0;
	last = 0;
	if (realloc)
	{
		ft_strdel(&(shell->pwd));
		if (getcwd(buf, 512) == 0 || ((shell->pwd = ft_strdup(buf)) == NULL))
			return (NULL);
		set_env_var("PWD", shell->pwd, shell);
	}
	else if (shell->pwd == NULL)
		return (SHELL_NAME": error: could not fetch current directory\n");
	while (shell->pwd[i])
	{
		if (shell->pwd[i] == '/')
			last = i;
		++i;
	}
	if (shell->pwd
		&& ft_strcmp(shell->pwd, get_env_var("HOME", shell->env)) == 0)
		return ("~");
	return (shell->pwd + last + 1);
}
