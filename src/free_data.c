/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:54:05 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/01 18:11:59 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_imgs(void *mlx_ptr, t_map_img *imgs)
{
	if (imgs->wall)
		mlx_destroy_image(mlx_ptr, imgs->wall);
	if (imgs->items)
		mlx_destroy_image(mlx_ptr, imgs->items);
	if (imgs->villain)
		mlx_destroy_image(mlx_ptr, imgs->villain);
	if (imgs->floor)
		mlx_destroy_image(mlx_ptr, imgs->floor);
	free(imgs);
	return (NULL);
}

void	*free_anim(void *mlx_ptr, t_anim *anim)
{
	if (anim->img0)
		mlx_destroy_image(mlx_ptr, anim->img0);
	if (anim->img1)
		mlx_destroy_image(mlx_ptr, anim->img1);
	if (anim->img2)
		mlx_destroy_image(mlx_ptr, anim->img2);
	if (anim->img3)
		mlx_destroy_image(mlx_ptr, anim->img3);
	if (anim->img4)
		mlx_destroy_image(mlx_ptr, anim->img4);
	free(anim);
	return (NULL);
}

void	*free_steps(void *mlx_ptr, t_step *step)
{
	if (step->img0)
		mlx_destroy_image(mlx_ptr, step->img0);
	if (step->img1)
		mlx_destroy_image(mlx_ptr, step->img1);
	if (step->img2)
		mlx_destroy_image(mlx_ptr, step->img2);
	if (step->img3)
		mlx_destroy_image(mlx_ptr, step->img3);
	if (step->img4)
		mlx_destroy_image(mlx_ptr, step->img4);
	if (step->img5)
		mlx_destroy_image(mlx_ptr, step->img5);
	if (step->img6)
		mlx_destroy_image(mlx_ptr, step->img6);
	if (step->img7)
		mlx_destroy_image(mlx_ptr, step->img7);
	if (step->img8)
		mlx_destroy_image(mlx_ptr, step->img8);
	if (step->img9)
		mlx_destroy_image(mlx_ptr, step->img9);
	if (step->step_img)
		mlx_destroy_image(mlx_ptr, step->step_img);
	free(step);
	return (NULL);
}

void	*free_vils(t_player **vils)
{
	int	i;

	i = -1;
	while (vils[++i])
		free(vils[i]);
	free(vils);
	return (NULL);
}

void	*free_t_data(t_data *data)
{
	if (data->player)
		free(data->player);
	if (data->map_img)
		free_imgs(data->mlx_ptr, data->map_img);
	if (data->item_list)
		free_item(data->item_list, data->xpm_map->items);
	if (data->xpm_map)
		free_xmp_map(data->xpm_map);
	if (data->s_img)
		free_steps(data->mlx_ptr, data->s_img);
	if (data->d_anim)
		free_anim(data->mlx_ptr, data->d_anim);
	if (data->p_anim)
		free_anim(data->mlx_ptr, data->p_anim);
	if (data->villain)
		free_vils(data->villain);
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
	}
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	free(data);
	return (NULL);
}
