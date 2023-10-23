/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:45:51 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/23 08:50:11 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printnbr(int n)
{
	long int	num;
	int			count;

	count = 1;
	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		count++;
	}
	if (num >= 10)
		count += ft_printnbr(num / 10);
	ft_putchar((num % 10) + '0');
	return (count);
}
