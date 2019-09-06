/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:45:14 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 22:45:17 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <libft.h>
# include "prompt.h"
# include "parser.h"
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

# define UNUSED(x) (void)(x)
# define PATH_MAX 4096

typedef int	(*t_func)(void *sh, t_list *environ, char **cmds);

typedef struct stat		t_stat;

typedef struct		s_builtin
{
	char			*name;
	t_func			func;
}					t_builtin;

typedef struct		s_generic_options
{
	char			options[256];
	int				start;
	int				error;
	int				error_char;
	int				options_counter;
}					t_generic_options;

typedef struct		s_env
{
	char			*var;
	char			*value;
}					t_env;

typedef struct		s_sh
{
	int				prompt_enabled;
	char			*term_name;
	int				tty;
	t_termios		term;
	t_termios		default_term;
	t_winsize		win;
	t_list			*env_list;
	int				last_res;
	t_list			*history;
	int				prompt_position;
	t_prompt		*c_prompt;
	int				signals_disabled;
}					t_sh;

t_sh				*shell_recover(void);
void				shell_exit(void);
int					shell_exec(t_cmd *cmd);
int					shell_launch_cmd(t_sh *sh, t_list *environ,
									char *cmd, char **args);
char				*shell_autocompletion(char *search);
void				shell_env_to_list(t_list **list, char **environ);
void				shell_env_show(t_list *list);
char				**shell_env_from_list(t_list *list);
char				*shell_env_get(t_list *list, char *var);
char				**shell_copy_env(char **env);
int					shell_count_env(char **env);
void				shell_signals(void);
int					shell_boot(t_sh *sh, t_list *environ, char **cmds);
int					shell_builtins_exit(void *sh_, t_list *environ,
									char **cmds);
int					shell_builtins_help(void *sh_, t_list *environ,
									char **cmds);
int					shell_builtins_pwd(void *sh_, t_list *environ,
									char **cmds);
int					shell_builtins_cd(void *sh, t_list *environ,
									char **cmds);
int					shell_builtins_env(void *sh_, t_list *environ,
									char **cmds);
int					shell_builtins_setenv_set(t_list **list,
									char *var, char *value);
void				shell_builtins_setenv_add(t_list **list, char *var,
									char *value);
int					shell_builtins_setenv(void *sh_,
									t_list *environ, char **cmds);
int					shell_builtins_unsetenv(void *sh_, t_list *environ,
								char **cmds);
void				shell_builtins_unsetenv_free(void *content,
								size_t content_size);
int					shell_is_builtin(t_sh *sh, char **cmds);
int					shell_boot_builtin(t_sh *sh, t_list *environ,
								char **cmds);
int					shell_boot_cmd(t_sh *sh, t_list *environ,
								char **cmds);
void				shell_errors_is_directory(char *cmd);
void				shell_errors_not_found(char *cmd);
void				shell_errors_no_file_directory(char *cmd);
t_generic_options	shell_builtins_options_parser(char **cmds,
							char *managed_options);
int					shell_builtins_cd_change_directory(t_sh *sh,
							t_list **environ, char *curpath, int is_physical);
void				shell_builtins_cd_update_path(t_sh *sh,
							t_list **environ, char *old_path, char *path);
char				*shell_builtins_cd_assert_multiple_args(t_sh *sh,
							char **cmds, t_generic_options *options);
char				*shell_builtins_cd_assert_home(t_sh *sh,
							t_list *environ);
int					shell_builtins_cd_error(int type, char *path);

#endif
