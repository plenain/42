/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:12:36 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 12:59:40 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TWENTY_H
# define FT_TWENTY_H
# include "libft.h"
# include "ft_env.h"
# include "ft_prompt.h"
# include "ft_signaux.h"
# include "ft_jb.h"
# include <termios.h>
# include <term.h>

typedef struct	s_data
{
	t_env		c;
	t_prompt	t;
}				t_data;

void    ft_set(int i);
void	ft_stati(t_data *h, int i);

#endif
