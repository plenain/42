/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:05:47 by plenain           #+#    #+#             */
/*   Updated: 2019/05/13 17:00:38 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <termios.h>

typedef struct	s_shell
{
	char			**env;
	char			**alias;
	char			*pwd;
	char			*buf;
	char			*history_line;
	int				cursor;
	int				bufsize;
	int				offset;
	int				shlvl;
	int				show_shlvl;
	int				no_log;
	int				color;
	int				showdir;
	int				running_command;
	int				no_shrc;
	int				history_idx;
	struct termios	termios_p;
}				t_shell;

char			**copy_env(char **env, char *newelem);
char			*get_env_var(char *name, char **env);
void			set_env_var(char *name, char *value, t_shell *shell);
int				remove_env_var(char *name, char **env);

void			set_default_env(t_shell *shell, char **env);

char			*get_log_line(unsigned int line);
void			log_input(t_shell *shell);

void			exec_shrc(t_shell *shell);

void			write_prompt(t_shell *shell);

void			signal_init(t_shell *shell);

#endif
