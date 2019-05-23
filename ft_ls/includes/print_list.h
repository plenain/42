/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:44:04 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:44:06 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_LIST_H
# define PRINT_LIST_H
# include "args.h"
# include "file_list.h"

void	print_file_name(t_args *args, t_files *files);
void	print_folder_list(t_args *args, t_folder *folders);

#endif
