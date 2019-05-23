/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 02:34:28 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/08 02:34:29 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		find_next_end(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '}')
			return (i);
		i++;
	}
	return (-1);
}

int		is_hexa(char *str, int end)
{
	if (ft_strncmp(str, "RESET", end - 1) == 0
		|| ft_strncmp(str, "reset", end - 1) == 0)
		return (1);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		str += 2;
		end -= 2;
	}
	while (--end > 0)
	{
		if (!ft_ishex(*str))
			return (0);
		str++;
	}
	return (1);
}

void	put_color(char *str, int fd)
{
	ft_putstr_fd("\033[38;5;", fd);
	ft_putnbr_fd(ft_atoi_base(str, 16), fd);
	ft_putchar_fd('m', fd);
}

int		putstr_color(char *str, int maxlen, int fd)
{
	int		i;
	int		idx;
	int		last;

	i = 0;
	last = 0;
	while (i < maxlen && str[i])
	{
		if (str[i] == '{' && (idx = find_next_end(&str[i])) > 1
			&& is_hexa(str + i + 1, idx))
		{
			ft_putnstr_fd(str + last, i - last, fd);
			if (str[i + 1] == 'R' || str[i + 1] == 'r')
				ft_putstr_fd("\033[0m", fd);
			else
				put_color(&str[i + 1], fd);
			i += idx + 1;
			last = i;
		}
		else
			i++;
	}
	if (last != i)
		ft_putnstr_fd(str + last, i - last, fd);
	return (1);
}
