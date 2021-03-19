/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr_str_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:13:33 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/18 20:32:09 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** responsáveis por tratar os ponteiros e suas flags
*/

static int	ft_get_pointer(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count += ft_put_spec("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_handle_width(flags.dot, ft_strlen(pointer), 1);
		count += ft_put_spec(pointer, flags.dot);
	}
	else
		count += ft_put_spec(pointer, ft_strlen(pointer));
	return (count);
}

int			ft_handle_pointer(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	if (flags.dot == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
			(((count += ft_handle_width(flags.width - 2, 0, 0))
			|| 1) && ((count += ft_put_spec("0x", 2)) || 1));
		else
			(((count += ft_put_spec("0x", 2)) || 1) &&
			((count += ft_handle_width(flags.width - 2, 0, 0)) || 1));
		return (count);
	}
	p = ft_utl_base(num, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		count += ft_get_pointer(p, flags);
	count += ft_handle_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		count += ft_get_pointer(p, flags);
	free(p);
	return (count);
}

/*
** responsáveis por tratar as strings e suas flags
*/

static int	ft_get_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_handle_width(flags.dot, ft_strlen(str), 0);
		count += ft_put_spec(str, flags.dot);
	}
	else
		count += ft_put_spec(str, ft_strlen(str));
	return (count);
}

int			ft_handle_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_get_string(str, flags);
	if (flags.dot >= 0)
		count += ft_handle_width(flags.width, flags.dot, 0);
	else
		count += ft_handle_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_get_string(str, flags);
	return (count);
}

/*
** responsáveis por tratar cada caracter e suas flags
*/

int	ft_handle_char(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = ft_handle_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
