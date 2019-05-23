/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:42:28 by plenain           #+#    #+#             */
/*   Updated: 2019/02/24 16:42:32 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define ERR_NO_ERR			(0)
# define ERR_MALLOC_FAIL	(-1)
# define ERR_INVALID_ARG	(1)

void	list_files(t_args *args, t_folder *curr);

#endif
