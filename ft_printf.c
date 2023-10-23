/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:27:56 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/23 08:49:47 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_printf(char const *s, ...)
{
	va_list			arguments;
	unsigned int	i;
	int				count;

	count = 0;
	va_start(arguments, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[++i] == '%')
				count += ft_putchar_fd('%', 1);
			else
				count += ft_varprint(s[i], arguments);
		}
		else
			count += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(arguments);
	return (count);
}
