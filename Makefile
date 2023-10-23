# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 11:24:06 by igaguila          #+#    #+#              #
#    Updated: 2023/10/23 08:50:46 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 			= 	ft_printf.c ft_varprint.c ft_printlowerhex.c \
					ft_printupperhex.c ft_printuns.c ft_printptr.c \
					ft_printchar.c ft_printnbr.c ft_printstr.c

OBJS			= 	${SRC:.c=.o}

NAME			= 	libftprintf.a

CC				= 	gcc

CFLAGS			= 	-Wall -Wextra -Werror

RM				= 	rm -f

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${OBJS}
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re