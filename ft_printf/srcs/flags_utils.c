/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:53:18 by plenain           #+#    #+#             */
/*   Updated: 2019/02/12 18:37:01 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_utils.h"
#include "libft.h"

int		is_valid_flag(char c)
{
	return (c == ' ' || c == '.' || c == '#' || c == '+' || c == '-'
			|| c == 'h' || c == 'l' || c == 'L' || ft_isdigit(c)
			|| c == 'z' || c == 'j' || c == 't');
}

int		is_valid_size_flag(char c)
{
	return (c == 'h' || c == 'l' || c == 'L'
			|| c == 'j' || c == 't' || c == 'z');
}