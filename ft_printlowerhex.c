/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowerhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:33:10 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/15 20:09:08 by igaguila         ###   ########.fr       */
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

static int	ft_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static char	*ft_converter(unsigned int n)
{
	char	*hex;
	char	*s;
	int		len;

	hex = "0123456789abcdef";
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (--len >= 0)
	{
		s[len] = hex[n % 16];
		n /= 16;
	}
	return (s);
}

int	ft_printlowerhex(unsigned int n)
{
	char	*s;

	if (n == 0)
		return (ft_putchar_fd('0', 1));
	s = ft_converter(n);
	ft_putstr_fd(s, 1);
	free(s);
	return (ft_len(n));
}
