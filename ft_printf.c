/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:14:22 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/18 20:32:09 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** reseta a struct
*/

static t_flags			ft_reset_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	return (flags);
}

/*
** faz a checagem das flags e distribui pra função especifica tratar.
*/

static int				ft_flag_options(const char *str, int i,
t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isspec(str[i]) && !ft_isflag(str[i]) && !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width(args, *flags);
		if (str[i] == '.')
			i = ft_dot(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_digit(str[i], *flags);
		if (ft_isspec(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

/*
** Inicia a struct, acha o porcento, chama funcao que classifica as flags
** imprime direto se não acha porcento.
*/

static int				ft_find_percent(const char *str, va_list args)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (!0)
	{
		flags = ft_reset_flags();
		if (!str[i]) // condição de start
			break ;
		else if (str[i] != '%')
			count += ft_putchar(str[i]); // imprime dirteo se não acha o porcento
		else if (str[i] == '%' && str[i + 1])// verifica o caractere seguinte ao porcento
		{
			i = ft_flag_options(str, ++i, &flags, args);// verifica as flags
			if (ft_isspec(str[i])) // verifica os specificadores
				count += ft_handle((char)flags.type, flags, args);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}

/*
** carrega os argumentos e passa pra função find_percent, libera a mem após final
*/

int						ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*str;
	int			count;

	count = 0;
	if (!(str = ft_strdup(format)))
		return (0);
	va_start(args, format);
	count += ft_find_percent
(str, args);
	va_end(args);
	free((char*)str);
	return (count);
}
