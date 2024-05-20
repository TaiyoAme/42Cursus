/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:03:14 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/01 18:42:51 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_min_size(t_map map)
{
	if (map.width < 2 || map.length < 2)
		return (0);
	return (1);
}

int	check_form(t_map map)
{
	int	i;

	i = -1;
	while (++i < map.width)
	{
		if ((int)ft_strlen(map.map[i]) != map.length)
			return (0);
	}
	return (1);
}

int	check_wall(t_map map)
{
	int	i;

	i = -1;
	while (++i < map.width)
	{
		if (map.map[i][map.length - 1] != '1' || map.map[i][0] != '1')
			return (0);
	}
	i = -1;
	while (++i < map.length)
	{
		if (map.map[0][i] != '1' || map.map[map.width - 1][i] != '1')
			return (0);
	}
	return (1);
}

int	check_element_in(int c_exit, int c_start, int c_items, t_map map)
{
	int	i;
	int	j;

	if (c_exit != 1 || c_items < 1 || c_start != 1)
		return (element_error());
	if (!check_min_size(map))
		return (min_size_error());
	if (!check_form(map) || !check_wall(map))
		return (map_form_error());
	i = -1;
	while (++i < map.width)
	{
		j = -1;
		while (++j < map.length)
		{
			if (map.map[i][j] != '1' && map.map[i][j] != '0'
				&& map.map[i][j] != 'E' && map.map[i][j] != 'P'
				&& map.map[i][j] != 'C' && map.map[i][j] != 'V')
			{
				write(1, INVALID_CHAR_FOUND, ft_strlen(INVALID_CHAR_FOUND));
				return (0);
			}
		}
	}
	return (c_items);
}

int	count_element(t_map map)
{
	int	i;
	int	j;
	int	c_exit;
	int	c_items;
	int	c_start;

	i = -1;
	c_exit = 0;
	c_items = 0;
	c_start = 0;
	while (++i < map.width)
	{
		j = -1;
		while (++j < map.length)
		{
			if (map.map[i][j] == 'E')
				c_exit++;
			if (map.map[i][j] == 'C')
				c_items++;
			if (map.map[i][j] == 'P')
				c_start++;
		}
	}
	map.items = c_items;
	return (check_element_in(c_exit, c_start, c_items, map));
}
