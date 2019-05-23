/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:10:10 by plenain           #+#    #+#             */
/*   Updated: 2019/04/15 21:10:12 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "shell.h"
#include "libft.h"
#include "constants.h"

void	log_input(t_shell *shell)
{
	int	fd;

	if (shell->no_log || ft_strcmp(shell->buf, "") == 0)
		return ;
	fd = open(LOG_FILE, O_RDWR | O_CREAT | O_APPEND, 448);
	if (fd < 0)
	{
		shell->no_log = 1;
		ft_putstr_fd(SHELL_NAME": error: could not write logs to file "LOG_FILE
		". Disabling logs.\n", 2);
		return ;
	}
	write(fd, shell->buf, ft_strlen(shell->buf));
	write(fd, "\n", 1);
	close(fd);
}

char	*get_log_line(unsigned int line)
{
	int		fd;
	int		tmp;
	char	buf[256];

	fd = open(LOG_FILE, O_RDONLY);
	if (fd < 0)
		return (NULL);
	(void)line;
	lseek(fd, -1, SEEK_END);
	while (line--)
	{
		while (read(fd, buf, 1) && buf[0] != '\n')
			lseek(fd, -2, SEEK_CUR);
		if (lseek(fd, -2, SEEK_CUR) < 0)
		{
			close(fd);
			return (NULL);
		}
	}
	tmp = read(fd, buf, 256);
	buf[tmp] = 0;
	close(fd);
	if (ft_strchr(buf, '\n') == NULL)
		return (ft_strdup(buf));
	return (ft_strcdup(ft_strchr(buf, '\n') + 1, '\n'));
}
