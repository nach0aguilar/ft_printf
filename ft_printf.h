/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:59:27 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/12 23:27:30 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
//# include "libft/libft.h"

void    ft_printupperhex(int n);
void    ft_printlowerhex(int n);
void    ft_varprint(char c, void *ptr);
int     ft_printf(char const *s, ...);

#endif