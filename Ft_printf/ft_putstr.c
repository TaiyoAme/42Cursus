/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:14:34 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/03 16:38:40 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	res;

	res = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (*s)
	{
		ft_putchar(*s);
		s++;
		res++;
	}
	return (res);
}
