/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:12:36 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/13 13:16:56 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H
# include "libft.h"
# include "ft_env.h"

# define ESCAPE		8
# define ENTER		10
# define TAB		9
# define ESC_KEY	27
# define RIGHT_KEY	4414235
# define LEFT_KEY	4479771
# define UP_KEY		4283163
# define DOWN_KEY	4348699
# define SPACE		32
# define DEL		127
# define DD			2117294875
# define MODE		5921563
# define CTRLD		4
# define HOME       4741915
# define END        4610843
# define PU			3496731
# define PD			3562267
# define NOT		77194440301339
# define NIT		79393463556891
# define CEND		-5

# define kl			"kl"

typedef struct s_esc
{
}				t_esc;

typedef struct	s_prompt
{
	int			i;
	size_t		y;
	size_t		read;
	char		c[2];
	char		p[ESCAPE];
	size_t	 	pos;
	size_t      oui;
	size_t 		size;
	char		*com;
}				t_prompt;

typedef struct s_seq
{
	unsigned long d;
	int			(*ptf)(t_prompt *ar, unsigned long c);
}				t_seq;

typedef struct s_action
{
	int			d;
	int			(*ptf)(t_prompt *ar, char c);
}				t_action;


void ft_add(t_prompt *ar, char c);
int	ft_escape(t_prompt *ar, char c);
int ft_letter(t_prompt *ar, char c);
void    ft_prompt(t_prompt *ar);
void    clean(t_prompt *v, int a);
void ft_action(t_prompt *ar, char c);
int ft_seqence(t_prompt *ar, unsigned long  c);
int ft_ctrld(t_prompt *ar, char c);
int ft_enter(t_prompt *ar, char c);
int ft_del(t_prompt *ar, char c);
int ft_dd(t_prompt *ar, unsigned long c);
int ft_home(t_prompt *ar, unsigned long c);
int ft_end(t_prompt *ar, unsigned long c);
int ft_pu(t_prompt *ar, unsigned long c);
int ft_pd(t_prompt *ar, unsigned long c);
int ft_up(t_prompt *ar, unsigned long c);
int ft_down(t_prompt *ar, unsigned long c);
int ft_left(t_prompt *ar, unsigned long c);
int ft_right(t_prompt *ar, unsigned long c);
char	*make_cursor();
void    ft_alpha(t_prompt *ac, char c);
int    ft_tab(t_prompt *ac, char c);
void init_prompt(t_prompt *ar);

#endif
