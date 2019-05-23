/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:46:06 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/05 01:46:07 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_pointers.h"
#include "libft.h"

int		print_unsigned_nbr(t_spec *spec, void *n)
{
	char				output[32];
	int					i;
	unsigned long long	nbr;

	nbr = get_unbr(spec, n);
	i = 30;
	ft_memset(output, '\0', 32);
	if (nbr == 0)
		return (ft_putstr_fd("0", spec->fd));
	while (nbr > 0)
	{
		output[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	return (ft_putstr_fd(&output[i + 1], spec->fd));
}

int		print_nbr(t_spec *spec, void *n)
{
	char				output[32];
	int					i;
	long long			nbr;
	unsigned long long	tmp;

	if (spec->option == 'u' || spec->option == 'U')
		return (print_unsigned_nbr(spec, n));
	nbr = get_nbr(spec, n);
	tmp = nbr;
	i = 30;
	if (nbr < 0)
		tmp = -nbr;
	else if (nbr == 0)
		return (ft_putstr_fd("0", spec->fd));
	ft_memset(output, '\0', 32);
	while (tmp > 0)
	{
		output[i] = '0' + tmp % 10;
		tmp /= 10;
		i--;
	}
	return (ft_putstr_fd(&output[i + 1], spec->fd));
}

int		ft_putllnbr(long long n, int fd)
{
	int i;

	i = 1;
	if (n < 0)
		n = -n;
	if (n >= 10)
		i += ft_putllnbr(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
	return (i);
}

int		print_nbr_base(unsigned long long nbr, char *base, int fd)
{
	char	output[256];
	int		i;
	int		base_len;

	i = 254;
	base_len = ft_strlen(base);
	ft_memset(output, '\0', 256);
	if (nbr == 0)
		output[i--] = base[0];
	while (nbr > 0)
	{
		output[i--] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (ft_putstr_fd(&output[i + 1], fd));
}
