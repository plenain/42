/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:51:40 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/29 18:51:41 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "colors.h"
#include "specifiers.h"
#include "function_pointers.h"

int		print_format_content(const char *format, t_spec *spec,
								const int formatlen, const int fd)
{
	static int			idx = 0;
	int					length;

	length = spec != 0 ? (spec->idx - idx) : (formatlen - idx);
	if (idx >= 0 && idx < formatlen
		&& putstr_color((char*)&format[idx], length, fd) == -1)
		ft_putnstr_fd((char*)&format[idx], length, fd);
	idx += length;
	if (spec != 0)
		idx += spec->len;
	else
		idx = 0;
	return (ft_floor(0, length));
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_spec		*spec;
	t_spec		*spec_start;
	int			print_count;
	const int	formatlen = ft_strlen(format);

	spec = NULL;
	print_count = 0;
	if (get_specifiers(format, &spec, 1) == -1)
	{
		spec_lst_clear(spec);
		return (-1);
	}
	va_start(args, format);
	spec_start = spec;
	while (spec != NULL)
	{
		print_count += print_format_content(format, spec, formatlen, 1);
		print_count += print_spec(spec, &args);
		spec = spec->next;
	}
	print_count += print_format_content(format, NULL, formatlen, 1);
	va_end(args);
	spec_lst_clear(spec_start);
	return (print_count);
}

int		ft_printf_fd(const int fd, const char *format, ...)
{
	va_list		args;
	t_spec		*spec;
	t_spec		*spec_start;
	int			print_count;
	const int	formatlen = ft_strlen(format);

	spec = NULL;
	print_count = 0;
	if (fd < 0 || get_specifiers(format, &spec, fd) == -1)
	{
		spec_lst_clear(spec);
		return (-1);
	}
	va_start(args, format);
	spec_start = spec;
	while (spec != NULL)
	{
		print_count += print_format_content(format, spec, formatlen, fd);
		print_count += print_spec(spec, &args);
		spec = spec->next;
	}
	print_count += print_format_content(format, NULL, formatlen, fd);
	va_end(args);
	spec_lst_clear(spec_start);
	return (print_count);
}
