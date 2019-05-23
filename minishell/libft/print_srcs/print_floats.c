/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 00:54:00 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/04 00:54:01 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "list.h"
#include "libft.h"
#include "function_pointers.h"

int			print_invalid_floats(t_spec *spec, long double *nbr, int *prnt_cnt)
{
	if (!ft_adv_memcmp(nbr, "0000 0000 0000 0080 ff7f 0000 0100 0000"))
	{
		ft_putstr_fd(spec->option == 'F' ? "INF" : "inf", spec->fd);
		*prnt_cnt += 3;
	}
	else if (!ft_adv_memcmp(nbr, "0000 0000 0000 0080 ffff 0000 0100 0000"))
	{
		ft_putstr_fd(spec->option == 'F' ? "-INF" : "-inf", spec->fd);
		*prnt_cnt += 4;
	}
	else if (!ft_adv_memcmp(nbr, "0000 0000 0000 00c0 ff7f 0000 0100 0000")
		|| !ft_adv_memcmp(nbr, "0000 0000 0000 00c0 ffff 0000 0100 0000"))
	{
		ft_putstr_fd(spec->option == 'F' ? "NAN" : "nan", spec->fd);
		*prnt_cnt += 3;
	}
	else
		return (0);
	return (1);
}

int			ft_print_float(long double nbr, int precision, int fd)
{
	long long	n;
	int			i;

	i = 0;
	n = (long long)nbr;
	if (nbr < 0 && ++i)
		ft_putchar_fd('-', fd);
	i += ft_putllnbr(n, fd);
	if (precision == 0)
		return (i);
	i += precision + 1;
	ft_putchar_fd('.', fd);
	nbr -= (long long)nbr;
	while (precision-- != 0)
	{
		nbr *= 10;
		n = (long long)nbr % 10;
		nbr -= (long long)nbr;
		ft_putchar_fd('0' + ft_abs(n), fd);
	}
	return (i);
}

long double	round_up(long double nbr, int precision)
{
	long long	tmp;
	long double	tmp2;
	int			idx;
	int			last;

	if (precision == 0)
	{
		tmp = nbr * 10;
		return (nbr + (tmp % 10 >= 5));
	}
	tmp2 = (nbr - (long long)nbr) * 10;
	idx = 0;
	last = -1;
	while (precision-- > 0 && ++idx)
	{
		if ((int)tmp2 == 9 || (int)tmp2 == -9)
			last = idx;
		tmp2 = tmp2 - (long long)tmp2;
		tmp2 *= 10;
	}
	tmp2 = last == -1 ? 0 : 0.1;
	tmp2 = nbr <= -0.0 ? -tmp2 : tmp2;
	while (last-- > 0)
		tmp2 /= 10;
	return (nbr + tmp2);
}

int			print_floats(t_spec *spec, va_list *args)
{
	int				prnt_cnt;
	int				precision;
	long double		nbr;

	prnt_cnt = 0;
	precision = 6;
	if (spec->maxlen != NULL)
		precision = ft_atoi(spec->maxlen);
	if (spec->size <= sizeof(double))
		nbr = va_arg(*args, double);
	else
		nbr = va_arg(*args, long double);
	nbr = round_up(nbr, precision);
	if (print_invalid_floats(spec, &nbr, &prnt_cnt) == 0)
		prnt_cnt += ft_print_float(nbr, precision, spec->fd);
	return (prnt_cnt);
}
