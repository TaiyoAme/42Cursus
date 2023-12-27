/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:53:53 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/02 16:48:54 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nl;
	int		res;

	nl = n;
	res = 0;
	if (nl < 0)
	{
		ft_putchar('-');
		nl *= -1;
		res++;
	}
	if (nl >= 10)
		res += ft_putnbr((nl / 10));
	return (res + ft_putchar((nl % 10) + '0'));
}
