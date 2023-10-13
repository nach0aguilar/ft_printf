# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 11:24:06 by igaguila          #+#    #+#              #
#    Updated: 2023/10/13 13:58:16 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 			= 	ft_printf.c ft_varprint.c ft_printlowerhex.c \
					ft_printupperhex.c ft_printuns.c

OBJS			= 	${SRC:.c=.o}

NAME			= 	libftprintf.a

CC				= 	gcc

CFLAGS			= 	-Wall -Wextra -Werror

RM				= 	rm -f

