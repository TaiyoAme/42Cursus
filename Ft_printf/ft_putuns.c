/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:38:38 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/02 18:47:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int n)
{
	long	nl;
	int		res;

	nl = n;
	res = 0;
	if (nl >= 10)
		res += ft_putnbr((nl / 10));
	return (res + ft_putchar((nl % 10) + '0'));
}
