/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:56:23 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:56:25 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"
#include "sort_reverse.h"
#include "sort_time.h"

void	sort_folders(t_args *args, t_folder **folders)
{
	if (args->flags & FLAG_NON_SORT)
		return ;
	if (args->flags & FLAG_TIME_SORT)
		sort_time(folders);
	if (args->flags & FLAG_REVERSE)
		folders_reverse(folders);
}

void	sort_files(t_args *args, t_files **files)
{
	if (args->flags & FLAG_NON_SORT)
		return ;
	if (args->flags & FLAG_TIME_SORT)
		sort_time_files(files);
	if (args->flags & FLAG_REVERSE)
		files_reverse(files);
}
