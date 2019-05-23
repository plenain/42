/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:56:08 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:56:10 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_list.h"
#include "conditions.h"
#include <unistd.h>

void	print_colors(t_files *files)
{
	if (files->permission[0] == 'c')
		ft_printf("{0b}");
	else if (files->permission[0] == 'b')
		ft_printf("{0c}");
	else if (files->permission[9] == 't')
		ft_printf("\033[48;5;14m{00}");
	else if (files->is_link)
		ft_printf("{0a}");
	else if (files->is_dir && files->permission[8] == 'w')
		ft_printf("\033[48;5;11m{00}");
	else if (files->is_dir)
		ft_printf("{0e}");
	else if (files->is_exec && files->permission[3] == 's')
		ft_printf("\033[48;5;1m{00}");
	else if (files->is_exec)
		ft_printf("{01}");
}

int		get_files_maxlen(t_files *files)
{
	int	maxlen;
	int	tmp;

	maxlen = 0;
	while (files != NULL)
	{
		tmp = ft_strlen(files->name);
		if (tmp > maxlen)
			maxlen = tmp;
		files = files->next;
	}
	return (maxlen);
}

void	print_file_with_pad(t_files *file, int maxlen)
{
	int		len;

	len = ft_strlen(file->name);
	write(1, file->name, len);
	ft_print_char(' ', maxlen - len);
}
