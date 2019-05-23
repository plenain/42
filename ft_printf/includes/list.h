/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:51:49 by plenain           #+#    #+#             */
/*   Updated: 2019/02/12 18:36:00 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <string.h>

typedef struct	s_spec
{
	char			option;
	int				flag;
	char			*minlen;
	char			*maxlen;
	int				idx;
	int				len;
	int				pad;
	int				pad_right;
	int				zeropad;
	int				nbrneg;
	int				print;
	int				fd;
	size_t			size;
	struct s_spec	*next;
}				t_spec;

t_spec			*spec_lst_new(int idx);
void			spec_lst_clear(t_spec *lst);
void			spec_lst_push(t_spec **begin_list, t_spec *spec);

#endif
