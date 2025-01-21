/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:36:02 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/29 13:40:18 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_number(int n)
{
	int		res;
	long	nl;

	res = 1;
	nl = n;
	if (nl < 0)
	{
		res += 1;
		nl *= -1;
	}
	while (nl >= 10)
	{
		nl /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*res;
	long	nl;

	nl = n;
	digits = digit_number(nl);
	res = malloc((digits + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[digits] = '\0';
	if (nl < 0)
	{
		res[0] = '-';
		nl *= -1;
	}
	while (nl >= 10)
	{
		res[--digits] = (nl % 10) + '0';
		nl /= 10;
	}
	res[--digits] = nl + '0';
	return (res);
}
