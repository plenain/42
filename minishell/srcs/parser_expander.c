/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:10:53 by plenain           #+#    #+#             */
/*   Updated: 2019/05/14 14:01:32 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "parsing.h"
#include "libft.h"

char	*expand_variables(char *input, t_shell *shell)
{
	int		i;
	int		escape;

	i = -1;
	escape = 0;
	while (input[++i])
	{
		if (escape && !(escape = 0))
			continue ;
		if (input[i] == '\\')
		{
			escape = 1;
			ft_strcpy(input + i, input + i + 1);
			--i;
		}
		else if (input[i] == '$' && input[i + 1] != '\0')
		{
			if ((input = insert_variable_value(input, i, shell)) == NULL)
				return (NULL);
		}
	}
	return (input);
}

char	*expand_argument(char *input, int len, int quote_type, t_shell *shell)
{
	char			*tmp;

	if ((input = ft_strsub(input, 0, len)) == NULL)
		return (NULL);
	if (quote_type == 0 || quote_type == 1)
	{
		if (input[0] == '~' && quote_type == 0)
		{
			tmp = input;
			input = ft_strins_malloc(tmp + 1,
								get_env_var("HOME", shell->env), 0);
			ft_strdel(&tmp);
			if (input == NULL)
				return (NULL);
		}
		input = expand_variables(input, shell);
	}
	return (input);
}

int		get_var_end(char *var)
{
	int i;

	i = 0;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '-' || var[i] == '_'))
		++i;
	return (i);
}

char	*insert_variable_value(char *input, int i, t_shell *shell)
{
	int		var_end;
	char	*tmp;
	char	*var_value;
	char	memory;

	var_end = get_var_end(input + i + 1);
	memory = input[i + 1 + var_end];
	input[i + 1 + var_end] = '\0';
	var_value = get_env_var(input + i + 1, shell->env);
	input[i + 1 + var_end] = memory;
	ft_strcut(input, i, i + var_end + 1);
	tmp = input;
	input = ft_strins_malloc(input, var_value, i);
	ft_strdel(&tmp);
	return (input);
}
