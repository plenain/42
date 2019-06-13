/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:16:32 by bordenoy          #+#    #+#             */
/*   Updated: 2019/03/25 16:06:20 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_file	*newfile(t_file **tab, int fd)
{
	t_file *n;
	t_file *s;

	s = *tab;
	if (s)
		while (s != ((*tab) = (*tab)->next))
			if ((*tab)->fd == fd)
				return (*tab);
	if (!(n = malloc(sizeof(t_file))))
		return (NULL);
	n->next = n;
	n->prev = n;
	n->fd = fd;
	n->fin = NULL;
	if (!(s))
		return (n);
	n->next = s->next;
	n->next->prev = n;
	n->prev = s;
	s->next = n;
	return (n);
}

int		ft_getline(t_file *tab)
{
	char	*b;
	char	buff[BUFF_SIZE + 1];
	int		i;

	if ((i = read(tab->fd, buff, BUFF_SIZE)) < 1)
		return (0);
	buff[i] = '\0';
	if (!(tab->fin))
		tab->fin = ft_strdup(buff);
	else
	{
		b = ft_strjoin(tab->fin, buff);
		ft_memdel((void *)&tab->fin);
		tab->fin = b;
	}
	i = 0;
	while (tab->fin && tab->fin[i])
		if (tab->fin[i++] == '\n')
			return (0);
	return (i);
}

int		freeme(t_file **ta, int h)
{
	t_file *tab;

	tab = *ta;
	if (tab)
		if (h == 0)
		{
			return (0);
			if (tab->fin)
				free(tab->fin);
			if (tab->next == tab)
			{
				free(tab);
				*ta = NULL;
				return (0);
			}
			tab->next->prev = tab->prev;
			tab->prev->next = tab->next;
			*ta = tab->next;
			free(tab);
			return (0);
		}
	return (1);
}

int		make(t_file **ta, char **a)
{
	int		b;
	char	*ptr;
	t_file	*tab;

	tab = *ta;
	b = 0;
	*a = NULL;
	if (tab && tab->fin)
	{
		while (tab->fin[b] && tab->fin[b] != '\n')
			b++;
		*a = ft_strsub(tab->fin, 0, b);
		if (tab->fin[b] && tab->fin[b + 1] != '\0')
			ptr = ft_strdup(tab->fin + b + 1);
		else
			ptr = NULL;
		ft_memdel((void *)&tab->fin);
		tab->fin = ptr;
	}
	*ta = tab;
	return (freeme(ta, *a != NULL));
}

int		get_next_line(const int fd, char **line)
{
	int				b;
	int				n;
	static	t_file	*tab;

	b = 0;
	n = 1;
	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFF_SIZE < 0)
		return (-1);
	if (!tab || tab->fd != fd)
		if (!(tab = newfile(&tab, fd)))
			return (0);
	if (tab->fin)
		while (tab->fin[b] && (n = (tab->fin[b++] != '\n')) == 1)
			;
	while (n && (b = ft_getline(tab)))
		;
	b = make(&tab, line);
	return (b > 0);
}
