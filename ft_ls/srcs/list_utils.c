/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:55:11 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:55:12 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_list.h"
#include "conditions.h"
#include "libft.h"

void		print_owner_with_pad(t_files *files, int reset)
{
	static size_t	len = 0;

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
			if (reset == 1 && !files->folderfile)
			{
				if (ft_strlen(files->owner) > len)
					len = ft_strlen(files->owner);
			}
			else if (reset == 2 && files->folderfile)
				if (ft_strlen(files->owner) > len)
					len = ft_strlen(files->owner);
			files = files->next;
		}
	}
	else if (files != 0)
	{
		ft_putstr(files->owner);
		ft_print_char(' ', len - ft_strlen(files->owner) + 2);
	}
}

void		print_group_with_pad(t_files *files, int reset)
{
	static size_t	len = 0;

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
			if (reset == 1 && !files->folderfile)
			{
				if (ft_strlen(files->group) > len)
					len = ft_strlen(files->group);
			}
			else if (reset == 2 && files->folderfile)
				if (ft_strlen(files->group) > len)
					len = ft_strlen(files->group);
			files = files->next;
		}
	}
	else if (files != 0)
	{
		ft_putstr(files->group);
		ft_print_char(' ', len - ft_strlen(files->group) + 2);
	}
}

void		print_links_with_pad(t_files *files, int reset)
{
	static int	len = 0;

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
			if (reset == 1 && !files->folderfile)
			{
				if (nbrlen(files->nlinks) > len)
					len = nbrlen(files->nlinks);
			}
			else if (reset == 2 && files->folderfile)
				if (nbrlen(files->nlinks) > len)
					len = nbrlen(files->nlinks);
			files = files->next;
		}
	}
	else if (files != 0)
	{
		ft_print_char(' ', len - nbrlen(files->nlinks));
		ft_putnbr(files->nlinks);
		ft_putchar(' ');
	}
}

void		get_biggest_size_field(t_files *files, int *len,
									int *tmp, int reset)
{
	ft_bzero(len, sizeof(int) * 3);
	while (files != 0)
	{
		tmp[0] = unbrlen(files->filesize);
		tmp[1] = unbrlen(files->major);
		tmp[2] = unbrlen(files->minor);
		if (files->filetype == 'b' || files->filetype == 'c')
			tmp[0] = tmp[1] + tmp[2] + 3;
		if ((reset == 1 && !files->folderfile)
			|| (reset == 2 && files->folderfile))
		{
			if (tmp[0] > len[0])
				len[0] = tmp[0];
			if (tmp[1] > len[1])
				len[1] = tmp[1];
			if (tmp[2] > len[2])
				len[2] = tmp[2];
		}
		files = files->next;
	}
}

void		print_size_with_pad(t_files *files, int reset)
{
	static int	len[3] = {0, 0, 0};
	int			tmp[3];

	if (reset != 0)
		get_biggest_size_field(files, len, tmp, reset);
	else if (files != 0)
	{
		if (files->filetype == 'b' || files->filetype == 'c')
		{
			ft_putchar(' ');
			ft_print_char(' ', len[1] - unbrlen(files->major));
			ft_putnbr(files->major);
			ft_putstr(", ");
			ft_print_char(' ', len[2] - unbrlen(files->minor));
			ft_putnbr(files->minor);
		}
		else
		{
			ft_print_char(' ', len[0] - unbrlen(files->filesize));
			ft_putnbr(files->filesize);
		}
		ft_putchar(' ');
	}
}
