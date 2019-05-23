/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:44:20 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:44:22 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H
# include "file_list.h"
# include "args.h"

int		remove_nonfiles_folders(t_folder **folders);
void	print_invalid_folders(t_args *args, t_folder *folders);
void	print_folder(t_args *args, t_folder *folders);

#endif
