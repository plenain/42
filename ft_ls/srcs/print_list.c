/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:55:35 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:55:37 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_list.h"
#include "printing_utils.h"
#include "printing.h"
#include "file_list.h"
#include "list_utils.h"
#include "libft.h"
#include "args.h"
#include "free.h"
#include "conditions.h"

void	print_file_name(t_args *args, t_files *files)
{
	ft_putstr(files->permission);
	print_links_with_pad(files, 0);
	if ((args->flags & FLAG_OMIT_UID) == 0)
		print_owner_with_pad(files, 0);
	if ((args->flags & FLAG_OMIT_GID) == 0)
		print_group_with_pad(files, 0);
	print_size_with_pad(files, 0);
	ft_putstr(files->date);
	ft_putchar(' ');
	if (args->flags & FLAG_COLOR)
		print_colors(files);
	ft_putstr(files->name);
	if (args->flags & FLAG_COLOR)
		ft_printf("{RESET}");
	if (files->symlink_path != NULL)
		ft_printf(" -> %s", files->symlink_path);
	ft_putchar('\n');
}

void	print_files_list(t_args *args, t_files *files)
{
	print_links_with_pad(files, 1);
	print_owner_with_pad(files, 1);
	print_group_with_pad(files, 1);
	print_size_with_pad(files, 1);
	while (files != 0)
	{
		print_file_name(args, files);
		files = files->next;
	}
}

void	print_folder_list(t_args *args, t_folder *folders)
{
	if (folders->next != NULL || folders != args->search_folder)
		ft_printf("%s:\n", folders->fullpath);
	if (folders->files != 0)
	{
		ft_printf("total %d\n", folders->total);
		print_files_list(args, folders->files);
	}
	if (folders->next != NULL || folders->subfolders != NULL)
		ft_putchar('\n');
}
