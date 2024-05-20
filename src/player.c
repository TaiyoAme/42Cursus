/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:31:54 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/01 18:20:54 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_step(int x, int y, t_data *data, t_player *pl_or_vil)
{
	t_player	*tplay_entity;

	if (!pl_or_vil && !check_step(data, x, y))
		game_end(data, LOOSE);
	if (!pl_or_vil)
		tplay_entity = data->player;
	else
		tplay_entity = pl_or_vil;
	if (data->xpm_map->map[x][y] != '1' && data->xpm_map->map[x][y] != 'E')
	{
		if (!pl_or_vil)
			tplay_entity->moves++;
		data->xpm_map->map[tplay_entity->x][tplay_entity->y] = '0';
		tplay_entity->x = x;
		tplay_entity->y = y;
		if (!pl_or_vil && is_collected(data))
			data->player->items++;
	}
	else if (pl_or_vil)
		switch_move(data, pl_or_vil);
	if (!pl_or_vil && data->xpm_map->map[x][y] == 'E'
			&& data->xpm_map->items == data->player->items)
		game_end(data, WIN);
}

void	up(t_data *data, t_player *pl_or_vil)
{
	if (!pl_or_vil)
	{
		ft_step(data->player->x - 1, data->player->y, data, NULL);
		pl_or_vil = data->player;
	}
	else
		ft_step(pl_or_vil->x - 1, pl_or_vil->y, data, pl_or_vil);
	if (data->xpm_map->map[pl_or_vil->x + 1][pl_or_vil->y] == '0')
		put_img(data, data->map_img->floor, pl_or_vil->y * IPX, \
			(pl_or_vil-> x + 1) * IPX);
	dsp_items(data);
}

void	down(t_data *data, t_player *pl_or_vil)
{
	if (!pl_or_vil)
	{
		ft_step(data->player->x + 1, data->player->y, data, NULL);
		pl_or_vil = data->player;
	}
	else
		ft_step(pl_or_vil->x + 1, pl_or_vil->y, data, pl_or_vil);
	if (data->xpm_map->map[pl_or_vil->x - 1][pl_or_vil->y] == '0')
		put_img(data, data->map_img->floor, pl_or_vil->y * IPX, \
			(pl_or_vil-> x - 1) * IPX);
	dsp_items(data);
}

void	left(t_data *data, t_player *pl_or_vil)
{
	if (!pl_or_vil)
	{
		ft_step(data->player->x, data->player->y - 1, data, NULL);
		pl_or_vil = data->player;
	}
	else
		ft_step(pl_or_vil->x, pl_or_vil->y - 1, data, pl_or_vil);
	if (data->xpm_map->map[pl_or_vil->x][pl_or_vil->y + 1] == '0')
		put_img(data, data->map_img->floor, (pl_or_vil->y + 1) * IPX, \
			pl_or_vil-> x * IPX);
	dsp_items(data);
}

void	right(t_data *data, t_player *pl_or_vil)
{
	if (!pl_or_vil)
	{
		ft_step(data->player->x, data->player->y + 1, data, NULL);
		pl_or_vil = data->player;
	}
	else
		ft_step(pl_or_vil->x, pl_or_vil->y + 1, data, pl_or_vil);
	if (data->xpm_map->map[pl_or_vil->x][pl_or_vil->y - 1] == '0')
		put_img(data, data->map_img->floor, (pl_or_vil->y - 1) * IPX, \
			pl_or_vil-> x * IPX);
	dsp_items(data);
}
