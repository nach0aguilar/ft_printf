/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:57:34 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/11 18:01:43 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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

static void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void    ft_varprint(char c, void *ptr)
{
    if (c == 'c')
        ft_putchar_fd((char)ptr, 1);
    else if (c == 's')
        ft_putstr_fd((char *)ptr, 1);
    // else if (c == 'p')
    //     c;
    else if (c == 'd' || c == 'i')
        ft_putnbr_fd((int)ptr, 1);
    // else if (c == 'u')
    //     c;
    // else if (c == 'x')
    //     c;
    // else if (c == 'X')
    //     c;        
}