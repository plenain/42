/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:40:16 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:41:11 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "args_struct.h"

# define ARGS_H
# define FLAGS 				"AGRUafglnortu1"
# define FLAG_UPPER_A		(1 << 0)
# define FLAG_COLOR			(1 << 1)
# define FLAG_RECURSIVE		(1 << 2)
# define FLAG_CREA_SORT		(1 << 3)
# define FLAG_ALL			(1 << 4)
# define FLAG_NON_SORT		(1 << 5)
# define FLAG_OMIT_UID		(1 << 6)
# define FLAG_LIST			(1 << 7)
# define FLAG_NUMERIC_ID	(1 << 8)
# define FLAG_OMIT_GID		(1 << 9)
# define FLAG_REVERSE		(1 << 10)
# define FLAG_TIME_SORT		(1 << 11)
# define FLAG_ACCESS_SORT	(1 << 12)
# define FLAG_ONE_LINE		(1 << 13)
# define NOTFLAG_FIRST		(1 << 31)

int			validate_parameters(t_args *args, char *str);
void		complete_arguments(t_args *args);
int			validate_arguments(t_args *args, int ac, char **av);

#endif
