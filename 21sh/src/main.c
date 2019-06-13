/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:29:49 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 13:17:22 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21.h"
#include <stdio.h>

t_data	*g_data;

void init_env(t_env *c, char **env)
{
	size_t  a;
	size_t  cc;

	c->b = NULL;
	a = 0;
	cc = 0;
	c->i = &a;
	c->c = &cc;
	c->b = make_env(env, c, 0);
}

int main(int ac, char **av, char **env)
{
	t_env		c;
	t_prompt    ar;
	t_data		r;

	if (ac && av)
		;
	grab_sign();
	init_env(&c, env);
	init_prompt(&ar);
	ft_set(0);
	r.c = c;
	r.t = ar;
	g_data = &r;
	ft_prompt(&g_data->t);
	return (0);
}
