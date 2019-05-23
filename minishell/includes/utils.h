/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:06:03 by plenain           #+#    #+#             */
/*   Updated: 2019/05/13 17:00:43 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "shell.h"

int		exists(char *path);
int		is_dir(char *path);
int		is_executable(char *path);
char	*concat_env_string(char *name, char *value);
char	*get_cwd(t_shell *shell, int realloc);

#endif
