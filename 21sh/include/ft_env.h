/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:37:49 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/04 12:25:53 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_env
{
	size_t		*i;
	size_t		*c;
	char		**b;
}				t_env;

char    **ft_create_env(int i);
size_t  ft_eg(char *c);
int     ft_fet(char *a, char *b);
char	**make_env(char **str, t_env *env, int pp);

#endif
