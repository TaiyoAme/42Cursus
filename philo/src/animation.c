/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:35:02 by hehuang           #+#    #+#             */
/*   Updated: 2024/03/21 15:36:08 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_player_anim(t_data *data)
{
	data->p_anim = malloc(sizeof(t_anim));
	if (!data->p_anim)
		return (0);
	data->p_anim->img0 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/Idle0.xpm", \
		&(data->p_anim->width), &(data->p_anim->height));
	data->p_anim->img1 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/Idle1.xpm", \
		&(data->p_anim->width), &(data->p_anim->height));
	data->p_anim->img2 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/Idle2.xpm", \
		&(data->p_anim->width), &(data->p_anim->height));
	data->p_anim->img3 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/Idle3.xpm", \
		&(data->p_anim->width), &(data->p_anim->height));
	data->p_anim->img4 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/Idle4.xpm", \
		&(data->p_anim->width), &(data->p_anim->height));
	data->p_anim->curr = data->p_anim->img0;
	data->p_anim->img_index = 0;
	data->p_anim->frame = -1;
	return (1);
}

int	init_door_anim(t_data *data)
{
	data->d_anim = malloc(sizeof(t_anim));
	if (!data->d_anim)
		return (0);
	data->d_anim->img0 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/open_door0.xpm", \
		&(data->d_anim->width), &(data->d_anim->height));
	data->d_anim->img1 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/open_door1.xpm", \
		&(data->d_anim->width), &(data->d_anim->height));
	data->d_anim->img2 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/open_door2.xpm", \
		&(data->d_anim->width), &(data->d_anim->height));
	data->d_anim->img3 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/animation/open_door3.xpm", \
		&(data->d_anim->width), &(data->d_anim->height));
	data->d_anim->img4 = NULL;
	data->d_anim->curr = data->d_anim->img0;
	data->d_anim->img_index = 0;
	data->d_anim->frame = -1;
	return (1);
}

int	updated_player(t_data *data)
{
	data->p_anim->frame ++;
	if (data->p_anim->frame % 5000 == 0)
	{
		data->p_anim->img_index++;
		if (data->p_anim->img_index == 0)
			data->p_anim->curr = data->p_anim->img0;
		else if (data->p_anim->img_index == 1)
			data->p_anim->curr = data->p_anim->img1;
		else if (data->p_anim->img_index == 2)
			data->p_anim->curr = data->p_anim->img2;
		else if (data->p_anim->img_index == 3)
			data->p_anim->curr = data->p_anim->img3;
		else if (data->p_anim->img_index == 4)
		{
			data->p_anim->curr = data->p_anim->img4;
			data->p_anim->frame = -1;
			data->p_anim->img_index = 0;
		}
		put_img(data, data->p_anim->curr, data->player->y * IPX, \
			data->player->x * IPX);
	}
	return (0);
}

int	updated_door(t_data *data)
{
	if (data->xpm_map->items == data->player->items)
	{
		data->d_anim->frame ++;
		if (data->d_anim->frame % 10000 == 0
			&& data->d_anim->img_index != 3)
		{
			data->d_anim->img_index++;
			if (data->d_anim->img_index == 0)
				data->d_anim->curr = data->d_anim->img0;
			else if (data->d_anim->img_index == 1)
				data->d_anim->curr = data->d_anim->img1;
			else if (data->d_anim->img_index == 2)
				data->d_anim->curr = data->d_anim->img2;
			else if (data->d_anim->img_index == 3)
				data->d_anim->curr = data->d_anim->img3;
			display_map(data);
		}
	}
	return (0);
}

int	update_anim(t_data *data)
{
	updated_player(data);
	updated_door(data);
	return (0);
}
