/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:14:28 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/18 20:32:38 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}				t_flags;

int				ft_handle_char(char c, t_flags flags);
int				ft_isflag(int c);
int				ft_isspec(int c);
t_flags			ft_minus(t_flags flags);
t_flags			ft_digit(char c, t_flags flags);
t_flags			ft_width(va_list args, t_flags flags);
int				ft_dot(const char *str, int start,
t_flags *flags, va_list args);
int				ft_handle_hex(unsigned int number,
int lowercase, t_flags flags);
int				ft_handle_int(int i, t_flags flags);
int				ft_handle_percent(t_flags flags);
int				ft_handle_pointer(unsigned long long num, t_flags flags);
int				ft_handle_string(char *str, t_flags flags);
int				ft_handle_unsigned(unsigned int nbr, t_flags flags);
int				ft_handle_width(int width, int minus, int zero);
int				ft_handle(int c, t_flags flags, va_list args);
int				ft_printf(const char *fmt, ...);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
int				ft_putchar(char c);
int				ft_put_spec(char *str, int precision);
char			*ft_str_tolower(char *str);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
int				ft_tolower(int c);
char			*ft_unsigned_itoa(unsigned int n);
char			*ft_utl_base(unsigned long long number, int base);

#endif
