/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:28:15 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/02 19:13:44 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_puthexa(unsigned int n, char c);
int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_isalpha(int c);
int	ft_tolower(int c);
int	ft_putpointer(unsigned long long p);
int	ft_putuns(unsigned int c);

#endif
