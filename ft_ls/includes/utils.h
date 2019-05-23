/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:45:54 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:45:56 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "args.h"

char	*build_prefix(char *prev_prefix, char *curr_folder);
int		exists(char *path);
int		is_dir(t_args *args, char *path);
char	*is_dir2(char *path);

#endif
