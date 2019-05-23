/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:45:23 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:45:25 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_REVERSE_H
# define SORT_REVERSE_H
# include "args.h"
# include "file_list.h"

void	folders_reverse(t_folder **begin_list);
void	files_reverse(t_files **files);

#endif
