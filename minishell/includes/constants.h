/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:05:21 by plenain           #+#    #+#             */
/*   Updated: 2019/05/13 17:00:25 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define SHELL_NAME				"My_Minishell"
# define SHELL_VERSION			"0.1"
# define DIR_COLOR				"\033[38;5;49m"
# define PROMPT_BASE			SHELL_NAME"-"SHELL_VERSION
# define PROMPT_END 			"-$> "
# define PROMPT_END_COLOR 		"-\033[38;5;9m$>\033[0m "
# define PROMPT_BASE_COLOR		"\033[38;5;80m"PROMPT_BASE
# define PROMPT 				PROMPT_BASE PROMPT_END
# define PROMPT_SHLVL			PROMPT_BASE"-%d"PROMPT_END
# define PROMPT_COLOR 			PROMPT_BASE_COLOR PROMPT_END_COLOR
# define PROMPT_SHLVL_COLOR		PROMPT_BASE_COLOR"-%d\033[0m"PROMPT_END_COLOR

# define BUILTINS_AMOUNT		(18)

# define BUF_SIZE				(5)

# define LOG_FILE				"/Users/plenain/.My_Minishell_history"

# define SHRC_FILE				"/Users/plenain/.My_Minishellshrc"

# define FORBIDDEN_ALIAS_CHARS 	"()\\'\";><|&[]+/"

# define DEFAULT_PATH			"/usr/bin:/bin"

# define INPUT_UP				(65)
# define INPUT_DOWN				(66)
# define INPUT_LEFT				(68)
# define INPUT_RIGHT			(67)

#endif
