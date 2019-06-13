/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:09:48 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/04 20:24:45 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 1

typedef	struct		s_file
{
	int				fd;
	char			*fin;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

int					get_next_line(const int fd, char **line);
#endif
