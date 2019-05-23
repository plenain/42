/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:52:02 by plenain           #+#    #+#             */
/*   Updated: 2019/02/12 18:36:08 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIERS_H
# define SPECIFIERS_H
# include "list.h"

int			parse_specifier(const char *start, t_spec **spec, int idx, int fd);
int			get_specifiers(const char *format, t_spec **spec, int fd);

#endif
