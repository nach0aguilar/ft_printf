/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:00:09 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/23 08:50:16 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_len(uintptr_t n)
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

static char	*ft_converter(uintptr_t n)
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

int	ft_printptr(uintptr_t n)
{
	char	*s;

	if (n == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	s = ft_converter(n);
	ft_putstr_fd(s, 1);
	free(s);
	return (ft_len(n) + 2);
}
