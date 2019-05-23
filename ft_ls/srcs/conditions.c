/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:53:51 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:53:53 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "libft.h"
#include <sys/stat.h>

int		file_exists(char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (stat(path, &path_stat) == 0);
}

int		is_dot(char *foldername)
{
	return (ft_strcmp(foldername, ".") == 0
			|| ft_strcmp(foldername, "..") == 0);
}

int		is_recursive(char *foldername, t_args *args)
{
	if (ft_strcmp(foldername, ".") == 0 || ft_strcmp(foldername, "..") == 0)
		return (0);
	return ((args->flags & FLAG_RECURSIVE) != 0);
}

int		is_hidden(char *filename, t_args *args)
{
	if (filename[0] != '.')
		return (0);
	if (args->flags & FLAG_ALL)
		return (0);
	return (1);
}
