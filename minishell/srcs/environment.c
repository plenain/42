/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:09:43 by plenain           #+#    #+#             */
/*   Updated: 2019/05/16 22:45:27 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"

char	*get_env_var(char *name, char **env)
{
	unsigned int tmp;

	if (env == NULL)
		return (NULL);
	while (*env)
	{
		tmp = ft_strlcmp(*env, name);
		if (tmp != 0 && (*env)[tmp] == '=')
			return (*env + tmp + 1);
		++env;
	}
	return (0);
}

char	**copy_env(char **env, char *newelem)
{
	int				len;
	int				i;
	char			**output;

	i = -1;
	len = (newelem != NULL);
	while (env && env[++i])
		if (env[i][0] != '\0')
			len++;
	if ((output = ft_memalloc(sizeof(char**) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (env && env[i])
	{
		if (env[i][0] != '\0'
			&& (output[len++] = ft_strdup(env[i])) == NULL)
			return (reverse_free_tab(output, len));
		++i;
	}
	if (newelem != 0)
		output[len++] = newelem;
	output[len] = NULL;
	return (output);
}

int		remove_env_var(char *name, char **env)
{
	unsigned int tmp;

	while (*env)
	{
		tmp = ft_strlcmp(*env, name);
		if (tmp != 0 && (*env)[tmp] == '=')
		{
			*env[0] = '\0';
			return (1);
		}
		++env;
	}
	return (0);
}

void	set_env_var(char *name, char *value, t_shell *shell)
{
	unsigned int	tmp;
	unsigned int	i;
	char			**tmpenv;

	if (shell->env == NULL)
	{
		shell->env = copy_env(NULL, concat_env_string(name, value));
		return ;
	}
	i = 0;
	while (shell->env[i])
	{
		tmp = ft_strlcmp(shell->env[i], name);
		if (tmp != 0 && (shell->env[i])[tmp] == '=')
		{
			ft_strdel(&(shell->env[i]));
			shell->env[i] = concat_env_string(name, value);
			return ;
		}
		++i;
	}
	tmpenv = shell->env;
	shell->env = copy_env(tmpenv, concat_env_string(name, value));
	ft_free_tab(tmpenv);
}
