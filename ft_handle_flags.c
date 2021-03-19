/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:12:56 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/18 20:32:09 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_minus(t_flags flags) // atribui valor na struct
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_digit(char c, t_flags flags) // atribui valor na struct
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}

t_flags	ft_width(va_list args, t_flags flags) // atribui valor na struct
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int		ft_dot(const char *str, int start, t_flags *flags, va_list args) // atribui valor na struct
{
	int i;

	i = start;
	i = i + 1;
	if (str[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i = i + 1;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
		{
			flags->dot = (flags->dot * 10) + (str[i] - 48);
			i = i + 1;
		}
	}
	return (i);
}

int	ft_handle_width(int width, int minus, int zero) // atribui valor na struct
{
	int count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}
