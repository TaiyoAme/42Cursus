/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:15:55 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/15 11:16:58 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (s && *s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = NULL;
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	while (size * nmemb > i)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

void	*ft_realloc(char *dest, char *src)
{
	char	*res;
	int		destlen;

	res = NULL;
	if (!dest)
		return (ft_calloc(ft_strlen(src) + 1, sizeof(char)));
	else
	{
		destlen = ft_strlen(dest);
		res = ft_calloc (ft_strlen(src) + destlen + 1, sizeof(char));
	}
	return (res);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	char	*res;

	res = NULL;
	if (!src)
		return (dest);
	res = ft_realloc(dest, src);
	i = 0;
	while (dest && dest[i] != '\0')
	{
		res[i] = dest[i];
		i++;
	}
	j = -1;
	while (src && src[++j] != '\0')
		res[i + j] = src[j];
	res[i + j] = '\0';
	free(dest);
	return (res);
}
