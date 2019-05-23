/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:41:32 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:41:35 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_STRUCT_H
# define ARGS_STRUCT_H
# include "file_list.h"

typedef struct	s_args
{
	int			flags;
	t_folder	*search_folder;
}				t_args;

t_args			*new_args(void);
void			free_args(t_args **args);
void			free_folder(t_folder **folder);

#endif
