/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:52:13 by plenain           #+#    #+#             */
/*   Updated: 2019/02/12 18:36:17 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define OPTIONS ("cCsSpdDioOuUxXfFbr")
# include "specifiers.h"

int		is_option(char c);
int		charset_match(char *s, char c);
int		search_reverse(char *str, char c, int start);
int		flag(int nbr, int flags);
int		is_valid_size_flag(char c);
int		is_printable(int print, t_spec *spec, int *maxlen);

#endif
