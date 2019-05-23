/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:44:08 by plenain           #+#    #+#             */
/*   Updated: 2019/05/01 19:44:11 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		copy_line(char **line, char **prevbuffer)
{
	char	*tmp;

	*line = ft_strsub(*prevbuffer, 0,
		(size_t)ft_strchr(*prevbuffer, '\n') - (size_t)*prevbuffer);
	if (*line == NULL)
	{
		ft_strdel(prevbuffer);
		return (-1);
	}
	tmp = *prevbuffer;
	*prevbuffer = ft_strdup(ft_strchr(*prevbuffer, '\n') + 1);
	free(tmp);
	return (*prevbuffer == NULL ? -1 : 1);
}

static int		copy_rest(char **line, char **prevbuffer)
{
	if (*prevbuffer != NULL && ft_strlen(*prevbuffer) == 0)
	{
		ft_strdel(prevbuffer);
		return (0);
	}
	*line = *prevbuffer;
	*prevbuffer = NULL;
	return (1);
}

static int		copy_str(char **line, char **prevbuffer)
{
	if (ft_strchr(*prevbuffer, '\n') != NULL)
		return (copy_line(line, prevbuffer));
	return (copy_rest(line, prevbuffer));
}

static char		*ft_strjoinfree2(char *source, char *concat)
{
	char	*tmp;

	if (source == NULL)
		tmp = ft_strdup(concat);
	else
		tmp = ft_strjoin(source, concat);
	free(source);
	if (tmp == NULL)
		free(concat);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*buffer;
	static char		*prevbuffer = NULL;

	if (fd < 0 || line == 0 || BUFF_SIZE <= 0)
		return (-1);
	if ((!prevbuffer || ft_strchr(prevbuffer, '\n') == NULL) && (ret = 1))
	{
		buffer = ft_strnew(BUFF_SIZE);
		while (buffer != NULL && ft_strchr(prevbuffer, '\n') == NULL && ret > 0)
		{
			ret = read(fd, buffer, BUFF_SIZE);
			buffer[ft_floor(0, ret)] = '\0';
			if (ret >= 0 && !(prevbuffer = ft_strjoinfree2(prevbuffer, buffer)))
				return (-1);
		}
		if (buffer != NULL)
			free(buffer);
		if (ret == -1 || buffer == NULL)
		{
			ft_strdel(&prevbuffer);
			return (-1);
		}
	}
	return (copy_str(line, &prevbuffer));
}
