/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:13:46 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/18 20:32:09 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** responsáveis por tratar os unsigned e suas flags
*/

static int	ft_get_unsigned(char *u_num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_handle_width(flags.dot - 1, ft_strlen(u_num) - 1, 1);
	count += ft_put_spec(u_num, ft_strlen(u_num));
	return (count);
}

static int	ft_put_unsigned(char *u_num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_get_unsigned(u_num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(u_num))
		flags.dot = ft_strlen(u_num);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_handle_width(flags.width, 0, 0);
	}
	else
		count += ft_handle_width(flags.width, ft_strlen(u_num), flags.zero);
	if (flags.minus == 0)
		count += ft_get_unsigned(u_num, flags);
	return (count);
}

int			ft_handle_unsigned(unsigned int nbr, t_flags flags)
{
	int		count;
	char	*u_num;

	count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.dot == 0 && nbr == 0)
	{
		count += ft_handle_width(flags.width, 0, 0);
		return (count);
	}
	u_num = ft_unsigned_itoa(nbr);
	count = ft_put_unsigned(u_num, flags);
	free(u_num);
	return (count);
}
