/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:04:51 by plenain           #+#    #+#             */
/*   Updated: 2019/05/13 17:00:07 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

int		get_arg_letter(char c, int ac, char **av);
int		get_arg(char *arg, int ac, char **av);
void	show_help(void);

#endif
