/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:09:30 by plenain           #+#    #+#             */
/*   Updated: 2019/05/15 20:33:33 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "constants.h"

void	set_default_env(t_shell *shell, char **env)
{
	if (get_env_var("PATH", env) == NULL)
		set_env_var("PATH", DEFAULT_PATH, shell);
}
