/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:18:03 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/12 18:38:26 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**get_items(t_data *data)
{
	int	**res;
	int	i;
	int	j;
	int	k;

	res = malloc(sizeof(int *) * data->xpm_map->items);
	i = -1;
	k = 0;
	while (++i < data->xpm_map->width)
	{
		j = -1;
		while (++j < data->xpm_map->length)
		{
			if (data->xpm_map->map[i][j] == 'C')
			{
				res[k] = malloc(sizeof(int) * 3);
				res[k][0] = i;
				res[k][1] = j;
				res[k][2] = 1;
				k++;
			}
		}
	}
	return (res);
}

void	dsp_items(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->xpm_map->items)
	{
		if (data->item_list[i][2])
			put_img(data, data->map_img->items, \
				data->item_list[i][1] * IPX, data->item_list[i][0] * IPX);
	}
}

int	is_collected(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->xpm_map->items)
	{
		if (data->item_list[i][0] == data->player->x
			&& data->item_list[i][1] == data->player->y
			&& data->item_list[i][2])
		{
			data->item_list[i][2] = 0;
			return (1);
		}
	}
	return (0);
}

void	*free_item(int	**item_list, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(item_list[i]);
	free(item_list);
	return (NULL);
}

//Check if the map is a .ber file
int	extension_check(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len > 4 && ft_strncmp(path + (len - 4), ".ber", 4) == 0)
		return (1);
	write(1, "Error :\nExtension error\n", 24);
	return (0);
}
