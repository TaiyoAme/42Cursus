/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:49:53 by hehuang           #+#    #+#             */
/*   Updated: 2023/11/14 21:33:18 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buffer)
{
	int		r;
	char	*tmp_buff;

	r = 1;
	tmp_buff = NULL;
	tmp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (r > 0 && !ft_strchr(tmp_buff, '\n'))
	{
		r = read(fd, tmp_buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			free(tmp_buff);
			return (NULL);
		}
		tmp_buff[r] = '\0';
		buffer = ft_strcat(buffer, tmp_buff);
	}
	free(tmp_buff);
	return (buffer);
}

char	*ft_getline(char *buffer)
{
	char	*myline;
	int		i;

	i = 0;
	myline = NULL;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	myline = ft_calloc(i + 2, sizeof(char));
	if (!myline)
		return (NULL);
	i = -1;
	while (buffer[++i] != '\n' && buffer[i])
		myline[i] = buffer[i];
	if (buffer[i] == '\n')
		myline[i] = '\n';
	return (myline);
}

char	*ft_clean_buffer(char *buffer)
{
	char	*new_buffer;
	int		j;
	int		i;

	i = 0;
	j = 0;
	new_buffer = NULL;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] == '\n')
		i++;
	new_buffer = ft_calloc(ft_strlen1(buffer) - i + 1, sizeof(char));
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*myline;
	static char	*buffer = NULL;

	myline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
	{
		buffer = NULL;
		return (NULL);
	}
	if (buffer[0] == '\0' || buffer[0] == '\n')
	{
		free(buffer);
		return (NULL);
	}
	myline = ft_getline(buffer);
	buffer = ft_clean_buffer(buffer);
	return (myline);
}
