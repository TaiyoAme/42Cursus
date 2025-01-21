/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:18:09 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/21 19:18:26 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lilen;
	size_t	i;

	i = 0;
	lilen = ft_strlen(little);
	if (lilen == 0)
		return ((char *)big);
	while (big[i] && lilen + i <= len && i < len)
	{
		if (big[i] == little[0] && ft_strncmp(&big[i], little, lilen) == 0)
			return ((char *)&big[i]);
		else
			i++;
	}
	return (NULL);
}
