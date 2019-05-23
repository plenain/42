/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:55:52 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:55:54 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"
#include "printing_utils.h"
#include "args.h"
#include "file_list.h"
#include "list_utils.h"
#include "print_inline.h"
#include "print_list.h"
#include "libft.h"
#include "free.h"
#include "utils.h"
#include "get_info.h"

int		remove_nonfiles_folders(t_folder **folders)
{
	t_folder	*curr;
	t_folder	*prev;
	t_folder	*tmp;
	int			found;

	curr = *folders;
	prev = 0;
	found = 0;
	while (curr != 0)
	{
		if (!curr->is_dir && ++found)
		{
			if (prev != 0)
				prev->next = curr->next;
			else
				*folders = curr->next;
			tmp = curr;
			curr = curr->next;
			free_single_folder(&tmp);
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
	return (found);
}

void	print_folderfiles_inline(t_args *args, t_folder *folders)
{
	int		n1;
	int		n2;

	n1 = 0;
	n2 = 0;
	while (folders != NULL)
	{
		if (folders->folderfile)
		{
			if (args->flags & FLAG_COLOR)
				print_colors((t_files*)folders);
			ft_putstr(folders->fullpath);
			if (args->flags & FLAG_COLOR)
				ft_printf("{RESET}");
			ft_putchar('\n');
			n1 = 1;
		}
		else if (folders->exists)
			n2 = 1;
		folders = folders->next;
	}
	if (n1 && n2)
		ft_putchar('\n');
}

void	print_folderfiles_list(t_args *args, t_folder *folders)
{
	int		n1;
	int		n2;

	n1 = 0;
	n2 = 0;
	print_links_with_pad((t_files*)folders, 2);
	print_owner_with_pad((t_files*)folders, 2);
	print_group_with_pad((t_files*)folders, 2);
	print_size_with_pad((t_files*)folders, 2);
	while (folders != NULL)
	{
		if (folders->folderfile)
		{
			print_file_name(args, (t_files*)folders);
			n1 = 1;
		}
		else if (folders->exists)
			n2 = 1;
		folders = folders->next;
	}
	if (n1 && n2)
		ft_putchar('\n');
}

void	print_invalid_folders(t_args *args, t_folder *folders)
{
	t_folder *curr;

	curr = folders;
	while (curr != 0)
	{
		curr->is_dir = 1;
		if (curr->exists && !exists(curr->fullpath))
		{
			ft_printf("ft_ls: %s: %s\n", curr->name, is_dir2(curr->fullpath));
			curr->exists = 0;
		}
		else if (!is_dir(args, curr->fullpath))
		{
			get_folders_info(args, curr);
			curr->exists = 0;
			curr->folderfile = 1;
			curr->is_dir = 0;
		}
		curr = curr->next;
	}
	if (args->flags & FLAG_LIST)
		print_folderfiles_list(args, folders);
	else
		print_folderfiles_inline(args, folders);
}

void	print_folder(t_args *args, t_folder *folders)
{
	if (!folders->exists)
		return ;
	if (args->flags & FLAG_LIST)
		print_folder_list(args, folders);
	else
		print_folder_inline(args, folders);
}
