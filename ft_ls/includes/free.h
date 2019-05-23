/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:42:16 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:42:18 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H
# include "args.h"
# include "file_list.h"

void	free_file(t_files **file);
void	free_folder(t_folder **folder);
void	free_single_folder(t_folder **folder);
void	free_args(t_args **args);

#endif
