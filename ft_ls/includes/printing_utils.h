/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:44:51 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:44:53 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_UTILS_H
# define PRINTING_UTILS_H

void	print_file_with_pad(t_files *file, int maxlen);
void	print_colors(t_files *files);
int		get_files_maxlen(t_files *files);
int		get_folderfiles_maxlen(t_folder *files);

#endif
