/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:57:06 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:57:10 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <sys/stat.h>

char	*build_prefix(char *prev_prefix, char *curr_folder)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(prev_prefix) + ft_strlen(curr_folder) + 2);
	if (tmp == NULL)
		return (NULL);
	ft_strcat(tmp, prev_prefix);
	ft_strcat(tmp, curr_folder);
	if (curr_folder[ft_strlen(curr_folder) - 1] != '/')
		ft_strcat(tmp, "/");
	return (tmp);
}

int		exists(char *path)
{
	struct stat	f_stat;
	struct stat	l_stat;

	return (lstat(path, &f_stat) + stat(path, &l_stat) == 0);
}

char	get_last_char(char *str)
{
	while (str[0] && str[1])
		str++;
	return (*str);
}

char	*is_dir2(char *path)
{
	struct stat	f_stat;
	int			i;

	i = 0;
	while (path[i] && path[i] != '/')
		i++;
	if (path[i] == '/')
	{
		path[i] = '\0';
		if (!lstat(path, &f_stat) && !S_ISDIR(f_stat.st_mode))
			return ("Not a directory");
		path[i] = '\\';
	}
	return ("No such file or directory");
}

int		is_dir(t_args *args, char *path)
{
	struct stat	f_stat;

	if (args
		&& (get_last_char(path) == '/' || (args->flags & FLAG_LIST) == 0))
		stat(path, &f_stat);
	else
		lstat(path, &f_stat);
	return (S_ISDIR(f_stat.st_mode));
}
