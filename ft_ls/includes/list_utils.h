/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:43:18 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:43:20 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H
# include "file_list.h"
# include <string.h>

void		print_group_with_pad(t_files *files, int reset);
void		print_owner_with_pad(t_files *files, int reset);
void		print_links_with_pad(t_files *files, int reset);
void		print_size_with_pad(t_files *files, int reset);

#endif
