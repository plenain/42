/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:07:04 by plenain           #+#    #+#             */
/*   Updated: 2019/05/13 17:01:25 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

char	*replace_word(char *input, char **alias, int x)
{
	int		i;
	int		c;
	int		len;
	char	*tmp;

	i = -1;
	while (alias && alias[++i])
	{
		if ((c = ft_cfind(alias[i], '=')) == -1)
			continue ;
		alias[i][c] = '\0';
		len = ft_strlen(alias[i]);
		if ((x == 0 || input[x - 1] == ' ') && ft_strncmp(input + x,
			alias[i], len) == 0 && (input[x + len] == ' '
			|| input[x + len] == '\0'))
		{
			ft_strcut(input, x, x + len);
			tmp = input;
			input = ft_strins_malloc(input, alias[i] + c + 1, x);
			ft_strdel(&tmp);
		}
		alias[i][c] = '=';
	}
	return (input);
}

int		get_command_end(char *s)
{
	unsigned int	i;
	unsigned int	escape;

	i = 0;
	escape = 0;
	while (s[i])
	{
		if (escape && ++i && !(escape = 0))
			continue ;
		if (s[i] == '\\' && ++i && (escape = 1))
			continue ;
		if (quote_match(s, &i, NULL))
			continue ;
		if (s[i] == ';')
			break ;
		if (s[i] == '#' && (i == 0 || s[i - 1] == ' '))
			break ;
		++i;
	}
	return (i);
}

char	*replace_aliases(char *input, char **alias)
{
	int		x;
	char	*output;
	int		escape;

	if ((output = ft_strsub(input, 0, get_command_end(input))) == NULL)
		return (NULL);
	x = 0;
	escape = 0;
	while (output[x])
	{
		if (escape && !(escape = 0) && ++x)
			continue;
		if (output[x] == '\\' && (escape = 1) && ++x)
			continue ;
		if (quote_match(output, (unsigned int*)&x, NULL))
			continue ;
		output = replace_word(output, alias, x);
		++x;
	}
	return (output);
}
