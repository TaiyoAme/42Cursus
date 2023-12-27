/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:31:31 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/02 19:13:56 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	long	nl;
	char	*hexabase;
	char	digit;
	int		res;

	res = 0;
	hexabase = "0123456789ABCDEF";
	nl = n;
	if (nl >= 16)
		res += ft_puthexa((nl / 16), c);
	digit = hexabase[nl % 16];
	if (ft_isalpha(digit) && c == 'x')
		res += ft_putchar(ft_tolower(digit));
	else
		res += ft_putchar(digit);
	return (res);
}
