/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser_helper_strings.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:16:31 by plenain           #+#    #+#             */
/*   Updated: 2019/09/09 17:14:28 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int	shell_parser_helper_strings_whitespaces(
	char **p_input, char *end, char *search)
{
	char *tmp;

	tmp = *p_input;
	while (tmp < end && ft_strchr(WHITESPACES, *tmp))
		tmp++;
	*p_input = tmp;
	return (*tmp && ft_strchr(search, *tmp));
}

int	shell_parser_helper_strings_scan_pipes(char **p_input, char *end,
	char **new_cmd, char **new_cmd_end)
{
	char *tmp;

	tmp = *p_input;
	while (tmp < end && ft_strchr(WHITESPACES, *tmp))
		tmp++;
	*new_cmd = tmp;
	while (tmp < end && !ft_strchr("|", *tmp))
		tmp++;
	*new_cmd_end = tmp;
	*p_input = tmp;
	return (tmp != end);
}
