/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:27:56 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/10 19:24:05 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_printf(char const *s, ...)
{
    va_list arguments;
    va_start(arguments, s);
    int i;
    
    i = 0;
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            ft_varprint(s[i]);
        }
        else
            ft_putchar_fd(s[i], 1);
        i++;
    }
    
    va_end(arguments);
    return (0);
}

int main()
{
    char chr = 'A';
    char *str = "Hola";
    int num = 345;
    ft_printf("hola esto es una prueba %c %% %s %d\n", chr, str, num);
}