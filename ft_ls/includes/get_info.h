/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:42:44 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:42:49 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_INFO_H
# define GET_INFO_H
# include "args.h"
# include "file_list.h"

void	get_folders_info(t_args *args, t_folder *folders);
void	get_files_info(t_args *args, t_folder *folder, t_files *files);

#endif
