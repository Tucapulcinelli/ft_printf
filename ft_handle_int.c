/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:13:18 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/18 20:32:09 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** responsáveis por tratar os inteiros e suas flags
*/

static int	ft_get_int(char *str, int num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0 && num < 0 && num != -2147483648)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_handle_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count += ft_put_spec(str, ft_strlen(str));
	return (count);
}

static int	ft_put_int(char *str, int num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_get_int(str, num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_handle_width(flags.width, 0, 0);
	}
	else
		count += ft_handle_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_get_int(str, num, flags);
	return (count);
}

int			ft_handle_int(int i, t_flags flags)
{
	int		count;
	int		num;
	char	*str;

	count = 0;
	num = i;
	if (flags.dot == 0 && i == 0)
	{
		count += ft_handle_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1) && num != -2147483648)
	{
		if (flags.dot <= -1 && flags.zero == 1)
			ft_put_spec("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	str = ft_itoa(i);
	count += ft_put_int(str, num, flags);
	free(str);
	return (count);
}
