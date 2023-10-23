/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:57:34 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/23 08:50:38 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_varprint(char c, va_list arguments)
{
	if (c == 'c')
		return (ft_printchar(va_arg(arguments, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(arguments, char *)));
	else if (c == 'p')
		return (ft_printptr(va_arg(arguments, uintptr_t)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(arguments, int)));
	else if (c == 'u')
		return (ft_printuns(va_arg(arguments, unsigned int)));
	else if (c == 'x')
		return (ft_printlowerhex(va_arg(arguments, unsigned int)));
	else if (c == 'X')
		return (ft_printupperhex(va_arg(arguments, unsigned int)));
	else
		return (0);
}
