/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:02:30 by plenain           #+#    #+#             */
/*   Updated: 2019/04/16 21:02:33 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_cfind(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c ? i : -1);
}

int		ft_rcfind(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
