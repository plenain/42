/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:10:16 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:10:18 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	shell_errors_is_directory(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": is a directory\n", 2);
}

void	shell_errors_not_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	shell_errors_no_file_directory(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}
