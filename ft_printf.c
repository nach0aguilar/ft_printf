/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:27:56 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/13 16:18:37 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_printf(char const *s, ...)
{
	va_list	arguments;
	int		i;

	va_start(arguments, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '%')
        		ft_putchar_fd('%', 1);
			else
				ft_varprint(s[i], va_arg(arguments, void *));
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(arguments);
	return (0);
}

int	main(void)
{
	char chr = 'A';
	char *str = "Pepe";
	int num = 255;
	int* ptr = &num;
	ft_printf("hola %c que %p tal %s\n", chr, (void *)ptr, str);
	printf("hola %c que %p tal %s\n", chr, (void *)ptr, str);
	printf("hola %c que %p tal %s\n", chr, (void *)ptr, str);
}