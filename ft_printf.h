/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:59:27 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/14 20:36:01 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printptr(uintptr_t n);
int	ft_printuns(unsigned int n);
int	ft_printupperhex(unsigned int n);
int	ft_printlowerhex(unsigned int n);
int	ft_varprint(char c, va_list arguments);
int	ft_printf(char const *s, ...);

#endif
