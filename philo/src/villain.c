/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:21:07 by hehuang           #+#    #+#             */
/*   Updated: 2024/02/22 18:21:41 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_villains_nb(t_data *data)
{
	int			res;
	int			i;
	int			j;

	res = 0;
	i = -1;
	while (++i < data->xpm_map->width)
	{
		j = -1;
		while (++j < data->xpm_map->length)
		{
			if (data->xpm_map->map[i][j] == 'V')
				res ++;
		}
	}
	return (res);
}

int	vil_direction(char **map, int x, int y)
{
	int	v;
	int	h;

	v = 0;
	h = 0;
	if (map[x][y + 1] == '0')
		v++;
	if (map[x][y - 1] == '0')
		v++;
	if (map[x + 1][y] == '0')
		h++;
	if (map[x - 1][y] == '0')
		h++;
	if (h > v)
		return (-1);
	return (1);
}

t_player	**get_villains(t_data *data)
{
	t_player	**res;
	int			i;
	int			j;
	int			k;

	res = malloc(sizeof(t_player *) * (get_villains_nb(data) + 1));
	i = -1;
	k = 0;
	while (++i < data->xpm_map->width)
	{
		j = -1;
		while (++j < data->xpm_map->length)
		{
			if (data->xpm_map->map[i][j] == 'V')
			{
				res[k] = init_vil(i, j);
				res[k]->items = vil_direction(data->xpm_map->map, i, j);
				k++;
			}
		}
	}
	res[k] = NULL;
	return (res);
}

void	switch_move(t_data *data, t_player *vil)
{
	vil->moves *= -1;
	if (vil->items == -1 && vil->moves == -1)
		up(data, vil);
	else if (vil->items == -1 && vil->moves == 1)
		down(data, vil);
	else if (vil->items == 1 && vil->moves == -1)
		right(data, vil);
	else if (vil->items == 1 && vil->moves == 1)
		left(data, vil);
}
//item = -1 (up|down)	| item = 1(right | left)
//move = -1 (righ | up)	| moves = 1(left | down)

void	vil_step(t_data *data)
{
	int			i;
	t_player	**vil;

	i = 0;
	vil = NULL;
	vil = data->villain;
	while (vil[i])
	{
		if (vil[i]->moves == 0)
			vil[i]->moves = -1;
		if (vil[i]->items == -1 && vil[i]->moves == -1)
			up(data, vil[i]);
		else if (vil[i]->items == -1 && vil[i]->moves == 1)
			down(data, vil[i]);
		else if (vil[i]->items == 1 && vil[i]->moves == -1)
			right(data, vil[i]);
		else if (vil[i]->items == 1 && vil[i]->moves == 1)
			left(data, vil[i]);
		i++;
	}
}
