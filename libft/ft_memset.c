/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:33:29 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/19 20:09:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char				*tmps;
	long unsigned int	i;

	i = 0;
	tmps = s;
	while (i < n)
	{
		tmps[i] = c;
		i++;
	}
	return (s);
}
