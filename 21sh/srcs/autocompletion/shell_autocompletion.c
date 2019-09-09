/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_autocompletion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:11:24 by plenain           #+#    #+#             */
/*   Updated: 2019/09/06 13:49:25 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

char	*shell_autocompletion_compute(t_list *cur, t_list *list,
												char *query)
{
	char	*result;
	int		i;

	i = ft_strlen(query) - 1;
	result = ft_strdup(query);
	while (++i != -1 && (cur = list))
	{
		while (cur && i != -1)
		{
			if (ft_strncmp(result, cur->content, i) != 0)
			{
				result = ft_strdup(cur->content);
				result[i - 1] = 0;
				i = -1;
				return (result + ft_strlen(query));
			}
			else
			{
				free(result);
				result = ft_strdup(cur->content);
			}
			cur = cur->next;
		}
	}
	return (NULL);
}

void	shell_autocompletion_add_results_from_path(t_list **list,
													char *path, char *search)
{
	char		*full_path;
	t_dirent	*dirent;
	DIR			*dir;
	t_stat		stat;

	dir = opendir(path);
	while (dir != NULL && ((dirent = readdir(dir)) != NULL))
	{
		if (dirent->d_name[0] != '.' && ft_strncmp(dirent->d_name, search,
			ft_strlen(search)) == 0)
		{
			full_path = ft_strfjoin(ft_strjoin(path, "/"), dirent->d_name);
			lstat(full_path, &stat);
			free(full_path);
			full_path = ft_strdup(dirent->d_name);
			if (S_ISDIR(stat.st_mode))
				full_path = ft_strfjoin(full_path, "/");
			ft_lstadd(list, ft_lstnew(full_path, ft_strlen(full_path) + 1));
			free(full_path);
		}
	}
	if (dir)
		closedir(dir);
}

char	*shell_autocompletion_search_as_path(t_list **list, char *search)
{
	char	*query;
	char	*query_path;

	query = ft_strrchr(search, '/') + 1;
	query_path = ft_strnew(ft_strlen(search) - ft_strlen(query) + 1);
	ft_strncpy(query_path, search, ft_strlen(search) - ft_strlen(query));
	shell_autocompletion_add_results_from_path(list, query_path, query);
	if (ft_lstcount(*list) == 1)
		return (ft_strdup(((char *)((*list)->content)) + ft_strlen(query)));
	if (ft_lstcount(*list) == 0)
		return (NULL);
	return (shell_autocompletion_compute(*list, *list, query));
}

char	*shell_autocompletion_search_env(t_sh *sh, t_list **list,
												char *search)
{
	char	*query;
	char	*query_path;
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	query_path = ft_strdup("./");
	query = search;
	shell_autocompletion_add_results_from_path(list, query_path, query);
	path = ft_strsplit(shell_env_get(sh->env_list, "PATH"), ':');
	while (path[i])
	{
		tmp = ft_strfjoin(ft_strjoin(path[i], "/"), query_path);
		shell_autocompletion_add_results_from_path(list, tmp, query);
		i++;
		free(tmp);
	}
	if (path)
		ft_free_tab(path);
	if (ft_lstcount(*list) == 1)
		return (ft_strdup(((char *)((*list)->content)) + ft_strlen(query)));
	if (ft_lstcount(*list) == 0)
		return (NULL);
	return (shell_autocompletion_compute(*list, *list, query));
}

char	*shell_autocompletion(char *search)
{
	t_sh	*sh;
	t_list	*results;
	t_list	*tmp;
	char	*output;

	sh = shell_recover();
	results = NULL;
	if (ft_strrchr(search, '/'))
		output = shell_autocompletion_search_as_path(&results, search);
	else
		output = shell_autocompletion_search_env(sh, &results, search);
	while (results)
	{
		tmp = results->next;
		free(results->content);
		free(results);
		results = tmp;
	}
	return (output);
}
