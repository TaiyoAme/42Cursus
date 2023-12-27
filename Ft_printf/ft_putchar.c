/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:12:15 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/02 17:33:40 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	succes;

	succes = write(1, &c, 1);
	if (succes <= 0)
		return (0);
	return (1);
}
