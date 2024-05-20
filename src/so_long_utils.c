/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:58:05 by hehuang           #+#    #+#             */
/*   Updated: 2024/03/18 18:10:38 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_occur(char *str, char elmt)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == elmt)
			count ++;
		str ++;
	}
	return (count);
}

char	**map_dup(t_data data)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * data.xpm_map->width);
	if (!res)
		return (NULL);
	while (i < data.xpm_map->width)
	{
		res[i] = ft_strdup(data.xpm_map->map[i]);
		i++;
	}
	return (res);
}

void	f_fill(char ***tab, int width, int col, int row)
{
	if (row < 0 || col < 0 || row >= width || col >= (int)ft_strlen((*tab)[0]))
		return ;
	if ((*tab)[row][col] == '1' || (*tab)[row][col] == 'K')
		return ;
	(*tab)[row][col] = 'K';
	f_fill(tab, width, col, row - 1);
	f_fill(tab, width, col, row + 1);
	f_fill(tab, width, col - 1, row);
	f_fill(tab, width, col + 1, row);
}

int	check_flood_tab(t_data *data)
{
	char	**tab;
	int		i;
	int		j;

	tab = map_dup(*data);
	f_fill(&tab, data->xpm_map->width, data->player->y, data->player->x);
	i = 0;
	while (i < data->xpm_map->width)
	{
		j = 0;
		while (j < data->xpm_map->length)
		{
			if (tab[i][j] == 'C' || tab[i][j] == 'E')
			{
				free_str_tab(tab, data->xpm_map->width, 1);
				no_way_end();
				return (0);
			}
			j++;
		}
		i++;
	}
	free_str_tab(tab, data->xpm_map->width, 1);
	return (1);
}

void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		img, x, y);
}
