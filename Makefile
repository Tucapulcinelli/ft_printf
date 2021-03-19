# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 14:15:33 by telias-p          #+#    #+#              #
#    Updated: 2021/03/18 16:16:10 by telias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 		ft_printf.c \
			ft_handle_flags.c \
			ft_handle_hex.c \
			ft_handle_int.c \
			ft_handle_ptr_str_char.c \
			ft_handle_unsigned.c \
			ft_handle.c \
			ft_printf_utils.c \
			ft_printf_utils2.c

OBJECTS = 	ft_printf.o \
			ft_handle_flags.o \
			ft_handle_hex.o \
			ft_handle_int.o \
			ft_handle_ptr_str_char.o \
			ft_handle_unsigned.o \
			ft_handle.o \
			ft_printf_utils.o \
			ft_printf_utils2.o

INCLUDES = ft_printf.h


all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
