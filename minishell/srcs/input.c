/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:09:57 by plenain           #+#    #+#             */
/*   Updated: 2019/04/15 21:09:59 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "constants.h"
#include "utils.h"
#include <termios.h>

void	move_cursor(int *x, int *max_x, int code)
{
	if (code == INPUT_RIGHT && *x < *max_x)
	{
		*x += 1;
		ft_putstr("\x1B\x5B\x43");
	}
	else if (code == INPUT_LEFT && *x > 0)
	{
		*x -= 1;
		ft_putstr("\x1B\x5B\x44");
	}
}

void	delete_char(char *buffer, int *cursor_x, int *offset)
{
	*cursor_x -= 1;
	*offset -= 1;
	ft_strcut(buffer, *cursor_x, *cursor_x + 1);
	ft_putstr("\b \b");
	ft_putstr(buffer + *cursor_x);
	ft_print_char(' ', *offset - *cursor_x);
	ft_print_char('\b', *offset - *cursor_x);
	ft_print_char('\b', *offset - *cursor_x);
}

void	insert_char(char buf, char *buffer,
		int *cursor_x, int *offset)
{
	ft_strnins(buffer, &buf, 1, (*cursor_x)++);
	ft_putstr(buffer + *cursor_x - 1);
	ft_print_char('\b', ++(*offset) - *cursor_x);
}

int		get_escape_mode(int escapemode, char buf)
{
	if (escapemode == 0 && buf == 27)
		return (1);
	if (escapemode == 1 && buf == 91)
		return (2);
	return (0);
}

int		read_input(t_shell *shell, unsigned int bufsize)
{
	char			buf;
	int				escapemode;

	ft_bzero(shell->buf, bufsize);
	shell->offset = 0;
	shell->cursor = 0;
	escapemode = 0;
	while ((buf = 1) && read(0, &buf, 1) > 0 && buf != '\n')
	{
		if (shell->offset + 1 >= (int)bufsize
			&& (shell->buf = ft_realloc(shell->buf, bufsize *= 2)) == NULL)
			return (0);
		if (buf == 127 && shell->cursor > 0 && shell->offset > 0)
			delete_char(shell->buf, &shell->cursor, &shell->offset);
		else if (buf == 27 || (escapemode == 1 && buf == 91))
			escapemode = get_escape_mode(escapemode, buf);
		else if (escapemode == 2 && !(escapemode = 0))
			move_cursor(&shell->cursor, &shell->offset, buf);
		else if (ft_isprint(buf))
			insert_char(buf, shell->buf, &shell->cursor, &shell->offset);
	}
	log_input(shell);
	return (buf == 1 ? 0 : 1);
}
