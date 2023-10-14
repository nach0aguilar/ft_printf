/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:57:34 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/14 20:38:30 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static int	ft_printstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	int			count;

	count = 1;
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
		count++;
	}
	if (num >= 10)
		count += ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
	return (count);
}

int	ft_varprint(char c, va_list arguments)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(arguments, int), 1));
	else if (c == 's')
		return (ft_printstr(va_arg(arguments, char *), 1));
	else if (c == 'p')
		return (ft_printptr(va_arg(arguments, uintptr_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(arguments, int), 1));
	else if (c == 'u')
		return (ft_printuns(va_arg(arguments, unsigned int)));
	else if (c == 'x')
		return (ft_printlowerhex(va_arg(arguments, unsigned int)));
	else if (c == 'X')
		return (ft_printupperhex(va_arg(arguments, unsigned int)));
	else
		return (0);
}
