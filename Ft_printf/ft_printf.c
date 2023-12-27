/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:55:00 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/02 19:18:35 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_format(va_list params, char c)
{
	if (c == 'c')
		return (ft_putchar((int) va_arg(params, int)));
	if (c == 's')
		return (ft_putstr(va_arg(params, char *)));
	if (c == 'p')
		return (ft_putpointer(va_arg(params, unsigned long long)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(params, int)));
	if (c == 'u')
		return (ft_putuns(va_arg(params, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthexa(va_arg(params, unsigned int), c));
	if (c == '%')
		return (ft_putchar('%'));
	else
		return (putchar(c));
}

int	ft_printf(const char *s, ...)
{
	va_list		params;
	int			res;

	res = 0;
	va_start(params, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			res += ft_find_format(params,*s);
			s++;
		}
		else
		{
			ft_putchar(*s);
			s++;
			res++;
		}
	}
	va_end(params);
	return (res);
}
