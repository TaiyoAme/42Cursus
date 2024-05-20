/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:49:38 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/01 18:13:01 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*empty_data(void)
{
	t_data	*res;

	res = malloc(sizeof(t_data));
	if (!res)
		return (NULL);
	res->mlx_ptr = NULL;
	res->win_ptr = NULL;
	res->xpm_map = NULL;
	res->s_img = NULL;
	res->d_anim = NULL;
	res->p_anim = NULL;
	res->player = NULL;
	res->map_img = NULL;
	res->villain = NULL;
	res->item_list = NULL;
	return (res);
}

void	*empty_map(t_data *data)
{
	write(1, "Error : map empty or first line empty\n", 38);
	return (free_t_data(data));
}

void	init_step(t_data *data)
{
	data->s_img = malloc(sizeof(t_step));
	data->s_img->img0 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/0.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img1 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/1.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img2 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/2.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img3 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/3.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img4 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/4.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img5 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/5.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img6 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/6.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img7 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/7.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img8 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/8.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->img9 = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./assets/step/9.xpm", &data->s_img->width, &data->s_img->height);
	data->s_img->step_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/step/steps.xpm", &data->s_img->width, &data->s_img->height);
}

void	put_step_nb(t_data *data, int pos, int nb)
{
	if (nb == 0)
		put_img(data, data->s_img->img0, pos, data->xpm_map->width * IPX);
	else if (nb == 1)
		put_img(data, data->s_img->img1, pos, data->xpm_map->width * IPX);
	else if (nb == 2)
		put_img(data, data->s_img->img2, pos, data->xpm_map->width * IPX);
	else if (nb == 3)
		put_img(data, data->s_img->img3, pos, data->xpm_map->width * IPX);
	else if (nb == 4)
		put_img(data, data->s_img->img4, pos, data->xpm_map->width * IPX);
	else if (nb == 5)
		put_img(data, data->s_img->img5, pos, data->xpm_map->width * IPX);
	else if (nb == 6)
		put_img(data, data->s_img->img6, pos, data->xpm_map->width * IPX);
	else if (nb == 7)
		put_img(data, data->s_img->img7, pos, data->xpm_map->width * IPX);
	else if (nb == 8)
		put_img(data, data->s_img->img8, pos, data->xpm_map->width * 50);
	else if (nb == 9)
		put_img(data, data->s_img->img9, pos, data->xpm_map->width * 50);
}

//150 is ./assets/steps size in px (50 * 150);
void	displ_steps(t_data *data)
{
	int		i;
	char	*numbers;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->s_img->step_img, 0, data->xpm_map->width * IPX);
	i = 0;
	numbers = ft_itoa(data->player->moves);
	while (numbers[i])
	{
		put_step_nb(data, 150 + (IPX * i), numbers[i] - '0');
		i++;
	}
	free(numbers);
}
