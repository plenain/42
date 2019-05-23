/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:54:27 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:54:29 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_struct.h"
#include "args.h"
#include "libft.h"
#include "ft_ls.h"
#include "utils.h"
#include "conditions.h"
#include "printing.h"
#include "get_info.h"
#include "get_info_2.h"
#include "free.h"
#include "sort.h"
#include <dirent.h>
#include <stdlib.h>

void	error_perm_denied(t_args *args, t_folder *curr)
{
	if (args->search_folder != curr || curr->next != NULL)
		ft_printf("%s:\n", curr->fullpath);
	ft_printf_fd(2, "ft_ls: %s: Permission denied\n", curr->name);
	if (curr->next != NULL)
		ft_putchar('\n');
	free_single_folder(&curr);
}

void	add_dots(t_args *args, t_folder *curr)
{
	t_files *file;

	if (((args->flags & FLAG_ALL) && !(args->flags & FLAG_UPPER_A)) == 0)
		return ;
	if ((file = file_lst_new("..", build_prefix(curr->prefix, curr->name))))
	{
		files_lst_push(args->flags | NOTFLAG_FIRST, &curr->files, file);
		get_files_info(args, curr, file);
	}
	file = file_lst_new(".", build_prefix(curr->prefix, curr->name));
	if (curr->files && file)
	{
		files_lst_push(args->flags | NOTFLAG_FIRST, &curr->files, file);
		get_files_info(args, curr, file);
	}
}

void	list_files2(DIR *d, t_args *args, t_folder *curr)
{
	t_folder	*next;
	int			newline;

	if (d)
	{
		add_dots(args, curr);
		get_folders_info(args, curr);
		sort_files(args, &curr->files);
		print_folder(args, curr);
		next = curr->subfolders;
		newline = curr->next != NULL;
		free_single_folder(&curr);
		if (args->flags & FLAG_RECURSIVE && next)
		{
			sort_folders(args, &next);
			list_files(args, next);
			if (newline)
				ft_putchar('\n');
		}
		closedir(d);
	}
	else if (curr->exists)
		error_perm_denied(args, curr);
}

void	list_files(t_args *args, t_folder *curr)
{
	DIR				*d;
	struct dirent	*f;
	t_files			*file;
	t_folder		*next;

	while (curr != NULL && (next = curr->next) != curr)
	{
		d = (!curr->exists) ? (NULL) : (opendir(curr->fullpath));
		while (d && (f = readdir(d)) != NULL)
		{
			if (is_hidden(f->d_name, args) || is_dot(f->d_name))
				continue ;
			file = file_lst_new(f->d_name,
				build_prefix(curr->prefix, curr->name));
			files_lst_push(args->flags, &curr->files, file);
			get_files_info(args, curr, file);
			if (!file || f->d_type != DT_DIR
				|| (args->flags & FLAG_RECURSIVE) == 0)
				continue ;
			folder_lst_push(args->flags, &curr->subfolders,
				folder_lst_new(f->d_name, ft_strdup(file->prefix)));
		}
		list_files2(d, args, curr);
		curr = next;
	}
}

int		main(int ac, char **av)
{
	t_args		*args;
	int			err;

	if ((args = new_args()) == NULL)
		return (0);
	if ((err = validate_arguments(args, ac, av)) == ERR_NO_ERR)
	{
		complete_arguments(args);
		sort_folders(args, &args->search_folder);
		print_invalid_folders(args, args->search_folder);
		remove_nonfiles_folders(&args->search_folder);
		list_files(args, args->search_folder);
	}
	else if (err == ERR_INVALID_ARG)
	{
		ft_putstr("usage: ft_ls [-"FLAGS"] [file ...]\n");
		if (args->search_folder)
			free_single_folder(&(args->search_folder));
	}
	free(args);
	return (0);
}
