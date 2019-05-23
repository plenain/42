/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:05:34 by plenain           #+#    #+#             */
/*   Updated: 2019/05/16 22:24:45 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "shell.h"

void	config_shell_input(t_shell *shell, int mode);
int		read_input(t_shell *shell, unsigned int bufsize);

int		look_for_char(char *dest, char c);
void	ignore_chars(char **dest, char *charset);
int		quote_match(char *input, unsigned int *e, unsigned int *quote);

int		get_var_end(char *var);
char	*insert_variable_value(char *input, int i, t_shell *shell);
char	*expand_argument(char *input, int len, int quote_type, t_shell *shell);

char	*replace_aliases(char *input, char **alias);

char	**parse_input(char *input, t_shell *shell);

#endif
