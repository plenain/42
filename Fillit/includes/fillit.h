/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:03:47 by plenain           #+#    #+#             */
/*   Updated: 2018/12/17 15:31:45 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "../libft/libft.h"
# define BUF_SIZE 546

typedef struct		s_tetr
{
	char			**tetrimino;
	int				x;
	int				y;
	char			nbr;
	struct s_tetr	*next;
}					t_tetr;

int					init_tetri(char *source, t_tetr **start);
int					new_list(char *buf, t_tetr **start);
int					check_symbols(char *buf, int size);
int					check_size(char *buf, int size);
int					check_size_tetri(char **tetri);
int					check_next(char **tetri);
int					check_next2(char **tetri);
int					backtrack_tetr(t_tetr *start, t_tetr *tetr, int size);
void				printer(t_tetr *ptr, int size);

#endif
