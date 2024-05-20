/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:58:05 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/12 18:35:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destr(t_data *data)
{
	free_t_data(data);
	exit(0);
	return (0);
}

void	game_end(t_data *data, int win)
{
	write(1, "---------------\n", 16);
	if (win)
		write(1, "|  YOU WIN !  |\n", 16);
	else
		write(1, "| YOU LOOSE ! |\n", 16);
	write(1, "---------------\n", 16);
	destr(data);
}

void	is_touched_by_vil(t_data *data)
{
	int	i;

	i = 0;
	while (data->villain[i])
	{
		if (data->villain[i]->x == data->player->x
			&& data->villain[i]->y == data->player->y)
			game_end(data, 0);
		i++;
	}
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		destr(data);
	else if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
	{
		vil_step(data);
		if (keysym == 119)
			up(data, NULL);
		else if (keysym == 97)
			left(data, NULL);
		else if (keysym == 115)
			down(data, NULL);
		else if (keysym == 100)
			right(data, NULL);
		add_vil(data);
		display_map(data);
	}
	is_touched_by_vil(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*d;
	int		fd;

	if (argc == 2 && extension_check(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			write (1, "Error:\nPath error\n", 18);
			return (1);
		}
		d = init_data(fd);
		close(fd);
		if (d)
		{
			mlx_hook(d->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, d);
			mlx_hook(d->win_ptr, DestroyNotify, StructureNotifyMask, &destr, d);
			mlx_loop_hook(d->mlx_ptr, &update_anim, d);
			mlx_loop(d->mlx_ptr);
		}
	}
	else if (argc != 2)
		write (1, "Error:\nArg number error\n", 24);
	return (0);
}
