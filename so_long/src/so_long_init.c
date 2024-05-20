/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:41:00 by hehuang           #+#    #+#             */
/*   Updated: 2024/03/26 19:15:35 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_map(int fd)
{
	char	*line;
	char	*file_str;
	t_map	*tmap;

	line = get_next_line(fd);
	if (line == NULL || (line[0] >= '\t' && line[0] <= '\r') || line[0] == ' ')
		return (free_str_tab(&line, 1, 0));
	file_str = NULL;
	while (line != NULL)
	{
		file_str = ft_strcat(file_str, line);
		free(line);
		line = get_next_line(fd);
	}
	tmap = malloc(sizeof(t_map));
	if (!tmap)
		return (NULL);
	tmap->map = ft_split(file_str, '\n');
	tmap->width = ft_find_occur(file_str, '\n');
	tmap->length = ft_strlen(tmap->map[0]);
	tmap->items = count_element(*tmap);
	free(file_str);
	if (!tmap->items)
		return (free_xmp_map(tmap));
	return (tmap);
}

t_player	*get_player(t_data *data)
{
	t_player	*res;
	int			i;
	int			j;

	res = malloc(sizeof(t_player));
	i = -1;
	while (++i < data->xpm_map->width)
	{
		j = -1;
		while (++j < data->xpm_map->length)
		{
			if (data->xpm_map->map[i][j] == 'P')
			{
				res->x = i;
				res->y = j;
				res->items = 0;
				res->moves = 0;
				return (res);
			}
		}
	}
	free(res);
	return (NULL);
}

t_map_img	*get_map_img(t_data *data)
{
	t_map_img	*imgs;

	imgs = malloc(sizeof(t_map_img));
	if (!imgs)
		return (NULL);
	imgs->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall.xpm", \
								&(imgs->width), &(imgs->height));
	imgs->items = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/item.xpm", \
								&(imgs->width), &(imgs->height));
	imgs->villain = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/player.xpm", \
								&(imgs->width), &(imgs->height));
	imgs->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/floor.xpm", \
								&(imgs->width), &(imgs->height));
	if (!imgs->wall || !imgs->items || !imgs->villain || !imgs->floor)
	{
		free_t_data(data);
		img_path_error();
		return (NULL);
	}
	return (imgs);
}

void	display_map(t_data *d)
{
	int			i;
	int			j;
	t_map_img	*img;

	i = -1;
	img = d->map_img;
	dsp_items(d);
	while (++i < d->xpm_map->width)
	{
		j = -1;
		while (++j < d->xpm_map->length)
		{
			if (d->xpm_map->map[i][j] == '1')
				put_img(d, img->wall, j * img->height, i * img->width);
			else if (d->xpm_map->map[i][j] == 'V')
				put_img(d, img->villain, j * img->height, i * img->width);
			else if (d->xpm_map->map[i][j] == 'C')
				put_img(d, img->items, j * img->height, i * img->width);
			else if (d->xpm_map->map[i][j] == 'P')
				put_img(d, d->p_anim->curr, j * img->height, i * img->width);
			else if (d->xpm_map->map[i][j] == 'E')
				put_img(d, d->d_anim->curr, j * img->height, i * img->width);
		}
	}
	displ_steps(d);
}

t_data	*init_data(int fd)
{
	t_data	*data;

	data = empty_data();
	if (!data)
		return (NULL);
	data->xpm_map = get_map(fd);
	if (!data->xpm_map)
		return (free_t_data(data));
	data->player = get_player(data);
	if (!check_flood_tab(data))
		return (free_t_data(data));
	data->mlx_ptr = mlx_init();
	data->map_img = get_map_img(data);
	init_step(data);
	data->item_list = get_items(data);
	if (!data->map_img)
		return (free_t_data(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->xpm_map->length * IPX \
								, (data->xpm_map->width + 1) * IPX, "Rock dj");
	data->villain = get_villains(data);
	init_player_anim(data);
	init_door_anim(data);
	display_map(data);
	displ_steps(data);
	return (data);
}
