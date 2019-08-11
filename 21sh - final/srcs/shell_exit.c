/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:10:38 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:10:41 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	shell_exit(void)
{
	t_sh *sh;

	sh = shell_recover();
	if (sh->env_list)
	{
		ft_lstdel(&sh->env_list, &shell_builtins_unsetenv_free);
		free(sh->env_list);
	}
	shell_prompt_reset();
	exit(sh->last_res);
}
