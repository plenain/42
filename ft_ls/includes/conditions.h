/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:41:49 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:41:51 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITIONS_H
# define CONDITIONS_H
# include "args.h"

int		file_exists(char *path);
int		is_recursive(char *foldername, t_args *args);
int		is_hidden(char *filename, t_args *args);
int		is_dot(char *foldername);

#endif
