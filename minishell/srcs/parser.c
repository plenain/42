/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:10:38 by plenain           #+#    #+#             */
/*   Updated: 2019/05/14 13:10:30 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "shell.h"
#include "constants.h"

int		count_arguments(char *input)
{
	unsigned int	count;
	unsigned int	e;
	unsigned int	escape;

	count = 0;
	while (++count && *input && !(escape = 0))
	{
		ignore_chars(&input, "\t ");
		if (*input == '\0' || (e = 0))
			break ;
		while (input[e])
		{
			if (escape && ++e && !(escape = 0))
				continue ;
			if (input[e] == '\t' || input[e] == ' ')
				break ;
			if ((input[e] == '\\' && ++e && (escape = 1))
				|| (quote_match(input, &e, NULL)))
				continue ;
			++e;
		}
		input += e;
	}
	return (count);
}

void	get_arg_end(char *input, unsigned int *quote, unsigned int *e)
{
	unsigned int	escape;

	escape = 0;
	*e = 0;
	while (input[*e])
	{
		if (escape && ++(*e) && !(escape = 0))
			continue ;
		if (input[*e] == '\t' || input[*e] == ' ')
			break ;
		if (input[*e] == '\\' && ++(*e) && (escape = 1))
			continue ;
		if (quote_match(input, e, quote))
			continue ;
		++(*e);
	}
}

void	fill_args(char **args, char *input, t_shell *shell)
{
	unsigned int	count;
	unsigned int	quote;
	unsigned int	e;

	count = 0;
	while (*input && !(quote = 0))
	{
		ignore_chars(&input, "\t ");
		if (*input == '\0')
			break ;
		get_arg_end(input, &quote, &e);
		if ((args[count++] = expand_argument(input, e, quote, shell)) == NULL)
		{
			reverse_free_tab(args, count - 1);
			return ;
		}
		input += e;
	}
	args[count] = NULL;
}

char	**parse_input(char *input, t_shell *shell)
{
	char			**args;
	unsigned int	count;

	if (!input || (input = replace_aliases(input, shell->alias)) == NULL)
	{
		ft_putstr_fd(SHELL_NAME": Parse error\n", 2);
		return (NULL);
	}
	count = count_arguments(input);
	if (count == 0 || !(args = ft_memalloc(sizeof(char*) * count)))
	{
		ft_putstr_fd(SHELL_NAME": Parse error\n", 2);
		return (NULL);
	}
	fill_args(args, input, shell);
	ft_strdel(&input);
	return (args);
}
