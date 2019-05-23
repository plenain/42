/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:23:07 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/03 22:23:07 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_pointers.h"
#include "libft.h"
#include "flags.h"
#include "utils.h"

t_func	g_func[SPECIFIER_COUNT] =
{
	{'c', &print_char},
	{'C', &print_char},
	{'%', &print_char},
	{'s', &print_string},
	{'S', &print_unicode_string},
	{'r', &print_string},
	{'d', &print_integer},
	{'D', &print_integer},
	{'i', &print_integer},
	{'u', &print_integer},
	{'U', &print_integer},
	{'x', &print_base},
	{'p', &print_base},
	{'X', &print_base},
	{'o', &print_base},
	{'O', &print_base},
	{'b', &print_base},
	{'f', &print_floats},
	{'F', &print_floats},
};

void	get_specifier_size(t_spec *spec)
{
	spec->size = sizeof(int);
	if (charset_match("pDO", spec->option))
		spec->size = sizeof(long);
	if (charset_match("douxXi", spec->option))
	{
		if (spec->flag & FLAG_S_Z)
			spec->size = sizeof(size_t);
		else if (spec->flag & FLAG_S_LL)
			spec->size = sizeof(long long int);
		else if (spec->flag & (FLAG_S_L | FLAG_S_J))
			spec->size = sizeof(long int);
		else if (spec->flag & FLAG_S_H)
			spec->size = sizeof(short);
		else if (spec->flag & FLAG_S_HH)
			spec->size = sizeof(char);
	}
	if (spec->option == 'U')
		spec->size = (spec->flag & FLAG_S_H) ? sizeof(long long)
			: sizeof(size_t);
	if (charset_match("fF", spec->option))
		spec->size = (spec->flag & FLAG_S_UPPER_L) ? sizeof(long double)
			: sizeof(double);
}

int		print_spec(t_spec *spec, va_list *arg)
{
	int	i;

	i = 0;
	get_specifier_size(spec);
	while (i < SPECIFIER_COUNT)
	{
		if (g_func[i].spec == spec->option)
			return (g_func[i].func(spec, arg));
		i++;
	}
	if (i == SPECIFIER_COUNT && spec->option != '\0')
		return (print_char(spec, arg));
	return (0);
}
