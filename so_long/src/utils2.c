/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:06:18 by hehuang           #+#    #+#             */
/*   Updated: 2024/03/18 17:00:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_step(t_data *data, int x, int y)
{
	t_player	**vil;
	int			i;

	vil = data->villain;
	i = 0;
	while (vil[i])
	{
		if (vil[i]->x == data->player->x && vil[i]->y == data->player->y)
		{
			if (vil[i]->items == -1 && vil[i]->moves == -1 && \
				vil[i]->x + 1 == x && vil[i]->y == y)
				return (0);
			else if (vil[i]->items == -1 && vil[i]->moves == 1 && \
				vil[i]->x - 1 == x && vil[i]->y == y)
				return (0);
			else if (vil[i]->items == 1 && vil[i]->moves == -1 && \
				vil[i]->x == x && vil[i]->y - 1 == y)
				return (0);
			else if (vil[i]->items == 1 && vil[i]->moves == 1 && \
				vil[i]->x == x && vil[i]->y + 1 == y)
				return (0);
		}
		i++;
	}
	return (1);
}

t_player	*init_vil(int x, int y)
{
	t_player	*res;

	res = malloc (sizeof(t_player));
	res->x = x;
	res->y = y;
	res->moves = 0;
	res->items = 0;
	return (res);
}

void	add_vil(t_data *data)
{
	t_player	**vil;
	int			i;

	vil = data->villain;
	i = -1;
	while (vil[++i])
		data->xpm_map->map[vil[i]->x][vil[i]->y] = 'V';
	data->xpm_map->map[data->player->x][data->player->y] = 'P';
}

void	*free_str_tab(char **str, int len, int is_strtab)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		free(str[i]);
	}
	if (is_strtab)
		free(str);
	else
		min_size_error();
	return (NULL);
}

void	*free_xmp_map(t_map *xpm_map)
{
	free_str_tab(xpm_map->map, xpm_map->width, 1);
	free(xpm_map);
	return (NULL);
}
