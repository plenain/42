/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:17:58 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/03 22:17:59 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIERS_H
# define SPECIFIERS_H
# include "list.h"

int			parse_specifier(const char *start, t_spec **spec, int idx, int fd);
int			get_specifiers(const char *format, t_spec **spec, int fd);

#endif
