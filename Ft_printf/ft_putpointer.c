/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:59:27 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/03 16:39:18 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlonghexa(unsigned long long nl)
{
	char	*hexabase;
	char	digit;
	int		res;

	res = 0;
	hexabase = "0123456789abcdef";
	if (nl >= 16)
		res += ft_putlonghexa((nl / 16));
	digit = hexabase[nl % 16];
	res += ft_putchar(digit);
	return (res);
}

int	ft_putpointer(unsigned long long p)
{
	int	res;

	if (p == 0)
		return (ft_putstr("(nil)"));
	res = ft_putstr("0x");
	res += ft_putlonghexa(p);
	return (res);
}
