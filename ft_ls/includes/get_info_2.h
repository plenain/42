/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:43:07 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:43:09 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_INFO_2_H
# define GET_INFO_2_H
# include "args.h"
# include "file_list.h"
# include <sys/stat.h>

void	build_permission_string(char *str, int st_mode);
void	get_symlink_target(t_files *file);

#endif
