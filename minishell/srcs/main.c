/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:10:20 by plenain           #+#    #+#             */
/*   Updated: 2019/05/14 14:05:38 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "arguments.h"
#include "parsing.h"
#include "constants.h"
#include "commands.h"
#include "libft.h"
#include "shell.h"
#include "utils.h"

void	config_shell_input(t_shell *shell, int mode)
{
	struct termios	termios_p;

	if (mode == 0)
		tcgetattr(0, &(shell->termios_p));
	if (mode == 0 || mode == 1)
	{
		ft_memcpy(&termios_p, &(shell->termios_p), sizeof(struct termios));
		termios_p.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(0, 0, &termios_p);
	}
}

int		get_env_vars(t_shell *shell, char **env)
{
	char	*tmp;

	if ((shell->env = copy_env(env, NULL)) == NULL)
		return (-1);
	set_default_env(shell, shell->env);
	get_cwd(shell, 1);
	shell->shlvl = ft_atoi(get_env_var("SHLVL", env)) + 1;
	if ((tmp = ft_itoa(shell->shlvl)) == NULL)
		return (-1);
	set_env_var("SHLVL", tmp, shell);
	ft_strdel(&tmp);
	return (1);
}

void	write_prompt(t_shell *shell)
{
	if (shell->showdir == 2)
		shell->color ? ft_printf(DIR_COLOR"%s/\033[0m ",
			get_cwd(shell, 0)) : ft_printf("%s/ ",
			get_cwd(shell, 0));
	if (shell->shlvl == 1 || shell->show_shlvl == 0)
		ft_putstr(shell->color ? PROMPT_COLOR : PROMPT);
	else
		ft_printf(shell->color ? PROMPT_SHLVL_COLOR : PROMPT_SHLVL,
			shell->shlvl);
	if (shell->showdir == 1)
		shell->color ? ft_printf(DIR_COLOR"%s/\033[0m ",
			get_cwd(shell, 0)) : ft_printf("%s/ ",
			get_cwd(shell, 0));
}

int		config_shell(t_shell *shell, int ac, char **av, char **env)
{
	ft_bzero(shell, sizeof(t_shell));
	if (get_arg("--help", ac, av) || get_arg_letter('h', ac, av))
	{
		show_help();
		return (0);
	}
	if (get_env_vars(shell, env) == -1
		|| (shell->buf = ft_strnew(BUF_SIZE)) == 0)
	{
		ft_free_tab(shell->env);
		return (0);
	}
	config_shell_input(shell, 0);
	shell->show_shlvl = get_arg("--shlvl", ac, av)
			|| get_arg_letter('l', ac, av);
	shell->no_log = get_arg("--no-log", ac, av) || get_arg_letter('s', ac, av);
	shell->no_shrc = get_arg("--no-shrc", ac, av)
			|| get_arg_letter('d', ac, av);
	shell->color = get_arg("--color", ac, av)
			|| get_arg_letter('G', ac, av);
	shell->showdir = (get_arg("--show-dir", ac, av)
			|| get_arg_letter('i', ac, av));
	if (get_arg("--show-dir-first", ac, av) || get_arg_letter('I', ac, av))
		shell->showdir = 2;
	return (1);
}

int		main(int ac, char **av, char **env)
{
	char	**args;
	t_shell	shell;

	signal_init(&shell);
	if (config_shell(&shell, ac, av, env) == 0)
		return (0);
	exec_shrc(&shell);
	while (1)
	{
		args = 0;
		write_prompt(&shell);
		if (read_input(&shell, BUF_SIZE) == 0)
			break ;
		ft_putchar('\n');
		if ((args = parse_input(shell.buf, &shell)) == NULL)
			break ;
		if (exec_command(&shell, args) == -1)
			break ;
		ft_free_tab(args);
	}
	b_exit(&shell, args);
	return (0);
}
