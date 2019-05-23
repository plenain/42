/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:53:19 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:53:21 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "libft.h"
#include "ft_ls.h"

int		validate_parameters(t_args *args, char *str)
{
	int		i;

	if (str == 0 || *str == '\0')
		return (0);
	i = 0;
	while (FLAGS[i] != '\0')
	{
		if (*str == FLAGS[i])
		{
			args->flags |= (1 << i);
			return (validate_parameters(args, str + 1));
		}
		i++;
	}
	return (*str);
}

void	complete_arguments(t_args *args)
{
	if (args->flags & FLAG_NUMERIC_ID || args->flags & FLAG_OMIT_GID
		|| args->flags & FLAG_OMIT_UID)
		args->flags |= FLAG_LIST;
	if (args->flags & FLAG_NON_SORT || args->flags & FLAG_UPPER_A)
		args->flags |= FLAG_ALL;
}

void	init_variables(int *i, int *nonargs, int *endargs)
{
	*i = 0;
	*endargs = 0;
	*nonargs = 0;
}

int		double_dash_arg(int *nonargs, int *endargs, char *s)
{
	if (!(*nonargs) && ft_strcmp("--", s) == 0 && (*endargs = 1))
	{
		*nonargs = 1;
		return (1);
	}
	return (0);
}

int		validate_arguments(t_args *args, int ac, char **av)
{
	int			i;
	char		tmp;
	int			endargs;
	int			nonargs;
	t_folder	*newfolder;

	init_variables(&i, &nonargs, &endargs);
	while (++i < ac)
	{
		if (double_dash_arg(&nonargs, &endargs, av[i]))
			continue ;
		if (!endargs && !nonargs && av[i][0] == '-' && av[i][1] != '\0')
		{
			if ((tmp = validate_parameters(args, av[i] + 1)) == 0)
				continue ;
			ft_printf("ft_ls: illegal option -- %c\n", tmp);
			return (ERR_INVALID_ARG);
		}
		folder_lst_push(args->flags, &args->search_folder,
			(newfolder = folder_lst_new(av[i], ft_strdup(""))));
		nonargs = 1;
	}
	if (args->search_folder == NULL)
		args->search_folder = folder_lst_new("./", ft_strdup(""));
	return (args->search_folder == NULL ? ERR_MALLOC_FAIL : ERR_NO_ERR);
}
