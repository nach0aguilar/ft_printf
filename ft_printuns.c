/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:52:28 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/13 13:56:55 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void    ft_printuns(unsigned int n)
{
	if (n >= 10)
		ft_printuns(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}