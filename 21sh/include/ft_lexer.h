/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:12:36 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 16:18:12 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

typedef struct	s_lexer
{
	int		ensemble;
	int 	sousensemble;
	int 	type;
	int 	case;
	char	*val;
	struct s_lexer	*next;
}				t_lexre;

#endif
