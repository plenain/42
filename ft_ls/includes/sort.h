/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:45:04 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:45:06 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "args.h"
# include "file_list.h"

void	sort_folders(t_args *args, t_folder **folders);
void	sort_files(t_args *args, t_files **files);

#endif
