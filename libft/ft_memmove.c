/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:39:37 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/23 15:28:05 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmpdest;
	const unsigned char	*tmpsrc;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tmpdest = dest;
	tmpsrc = src;
	if (dest > src)
	{
		while (n-- > 0)
			tmpdest[n] = tmpsrc[n];
	}
	else
	{
		while (i < n)
		{
			tmpdest[i] = tmpsrc[i];
			i++;
		}
	}
	return (dest);
}
