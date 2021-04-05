/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:14:01 by telias-p          #+#    #+#             */
/*   Updated: 2021/04/05 19:49:56 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspec(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

int	ft_handle_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_put_spec("%", 1);
	count += ft_handle_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_put_spec("%", 1);
	return (count);
}

int	ft_handle(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_handle_char(va_arg(args, int), flags);
	else if (c == '%')
		count += ft_handle_percent(flags);
	else if (c == 'p')
		count = ft_handle_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = ft_handle_string(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = ft_handle_int(va_arg(args, int), flags);
	else if (c == 'x')
		count += ft_handle_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_handle_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		count += ft_handle_unsigned((unsigned int)va_arg(args, unsigned int)
		, flags);
	return (count);
}
