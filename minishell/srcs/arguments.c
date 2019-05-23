/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:07:18 by plenain           #+#    #+#             */
/*   Updated: 2019/05/13 17:01:34 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "constants.h"

int		get_arg_letter(char c, int ac, char **av)
{
	int		i;
	int		x;

	i = 0;
	while (++i != ac && av[i])
	{
		if (av[i][0] != '-')
			continue ;
		x = 1;
		while (av[i][x])
		{
			if (av[i][x] == c)
				return (1);
			else if (av[i][x] == '-')
				break ;
			++x;
		}
	}
	return (0);
}

int		get_arg(char *arg, int ac, char **av)
{
	int		i;

	i = 1;
	while (i != ac && av[i])
	{
		if (ft_strcmp(av[i], arg) == 0)
			return (1);
		++i;
	}
	return (0);
}

void	show_help(void)
{
	ft_putendl("--- "SHELL_NAME" "SHELL_VERSION" ---");
	ft_putendl("Startup options:");
	ft_putendl("  -s, --no-log");
	ft_putendl("  -d, --no-shrc");
	ft_putendl("  -l, --shlvl");
	ft_putendl("  -G, --color");
	ft_putendl("  -i, --show-dir");
	ft_putendl("  -I, --show-dir-first");
}
