/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:58:18 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/20 19:34:09 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			dstlen;
	unsigned int	i;
	unsigned int	j;

	dstlen = ft_strlen(dst);
	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (dstlen >= size)
		return (ft_strlen(src) + size);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size - dstlen - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (size >= dstlen)
		dst[i + j] = '\0';
	return (dstlen + ft_strlen(src));
}
