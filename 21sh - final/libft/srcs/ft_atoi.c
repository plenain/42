/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plenain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:32:37 by plenain           #+#    #+#             */
/*   Updated: 2019/08/11 23:32:39 by plenain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	char	*ptr;
	int		is_neg;
	int		result;

	result = 0;
	ptr = (char *)str;
	is_neg = 0;
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'
			|| *ptr == '\n' || *ptr == '\f' || *ptr == '\r')
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			is_neg = 1;
		ptr++;
	}
	while (*ptr && *ptr >= '0' && *ptr <= '9')
	{
		result *= 10;
		result += *ptr - '0';
		ptr++;
	}
	if (is_neg)
		result *= -1;
	return (result);
}
