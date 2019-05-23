/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:42:00 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:42:03 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_LIST_H
# define FILE_LIST_H

typedef struct	s_files
{
	char				*name;
	char				*prefix;
	char				*fullpath;
	int					filetype;
	int					exists;
	int					is_dir;
	int					is_exec;
	int					is_link;
	int					nlinks;
	int					folderfile;
	unsigned int		mode;
	unsigned int		major;
	unsigned int		minor;
	unsigned long long	filesize;
	unsigned long long	time;
	char				*symlink_path;
	char				permission[13];
	char				*owner;
	char				*group;
	char				*date;
	struct s_files		*next;
}				t_files;

typedef struct	s_folder
{
	char				*name;
	char				*prefix;
	char				*fullpath;
	int					filetype;
	int					exists;
	int					is_dir;
	int					is_exec;
	int					is_link;
	int					nlinks;
	int					folderfile;
	unsigned int		mode;
	unsigned int		major;
	unsigned int		minor;
	unsigned long long	filesize;
	unsigned long long	time;
	char				*symlink_path;
	char				permission[13];
	char				*owner;
	char				*group;
	char				*date;
	struct s_folder		*next;
	int					total;
	t_files				*files;
	struct s_folder		*subfolders;
}				t_folder;

t_files			*file_lst_new(char *name, char *prefix);
void			files_lst_push(int flags, t_files **begin, t_files *file);
int				folder_lst_size(t_folder *folder);

t_folder		*folder_lst_new(char *name, char *prefix);
void			folder_lst_push(int flags, t_folder **begin, t_folder *file);

#endif
