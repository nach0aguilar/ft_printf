/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowerhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:33:10 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/12 23:27:13 by igaguila         ###   ########.fr       */
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

static int		ft_len(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char		*ft_converter(int n)
{
	char	*hex;
	char 	*s;
	int		len;
	
	if (n < 0)
		n *= -1;
	hex = "0123456789abcdef";
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len >= 0)
	{
		s[len - 1] = hex[n % 16];
		n /= 16;
		len--;
	}
	s[len] = hex[n];
	return (s);
}

void    ft_printlowerhex(int n)
{
	char	*hex;
	char	*s;
	
	hex = "0123456789abcdef";
	s = ft_converter(n);
	if (n < 0 || n > 15)
		ft_putstr_fd(s, 1);
	else
		ft_putchar_fd(hex[n], 1);
	
}
