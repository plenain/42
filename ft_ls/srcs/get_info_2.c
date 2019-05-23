/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:54:56 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:54:58 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_info_2.h"
#include "args.h"
#include "file_list.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>

char	get_entry_type(char *str, int st_mode)
{
	ft_strcpy(str, "----------  ");
	if (S_ISBLK(st_mode))
		return ('b');
	if (S_ISCHR(st_mode))
		return ('c');
	if (S_ISDIR(st_mode))
		return ('d');
	if (S_ISLNK(st_mode))
		return ('l');
	if (S_ISSOCK(st_mode))
		return ('s');
	if (S_ISFIFO(st_mode))
		return ('p');
	return ('-');
}

void	build_permission_string(char *str, int st_mode)
{
	str[0] = get_entry_type(str, st_mode);
	if (st_mode & S_IRUSR)
		str[1] = 'r';
	if (st_mode & S_IWUSR)
		str[2] = 'w';
	if (st_mode & S_IXUSR)
		str[3] = 'x';
	if (st_mode & S_ISUID)
		str[3] = str[3] == 'x' ? 's' : 'S';
	if (st_mode & S_IRGRP)
		str[4] = 'r';
	if (st_mode & S_IWGRP)
		str[5] = 'w';
	if (st_mode & S_IXGRP)
		str[6] = 'x';
	if (st_mode & S_ISGID)
		str[6] = str[6] == 'x' ? 's' : 'S';
	if (st_mode & S_IROTH)
		str[7] = 'r';
	if (st_mode & S_IWOTH)
		str[8] = 'w';
	if (st_mode & S_IXOTH)
		str[9] = 'x';
	if (st_mode & S_ISVTX)
		str[9] = (str[7] == 'r' || str[9] == 'x') ? 't' : 'T';
}

void	get_symlink_target(t_files *file)
{
	char	buf[257];
	char	*out;
	int		read;

	if (!file->is_link)
		return ;
	read = readlink(file->fullpath, buf, 256);
	if (read <= 0 || read >= 257)
		return ;
	out = ft_memdup(buf, read + 1);
	if (out != 0)
	{
		out[read] = '\0';
		file->symlink_path = out;
	}
}
