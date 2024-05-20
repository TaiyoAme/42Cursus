/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:57:18 by hehuang           #+#    #+#             */
/*   Updated: 2024/02/23 21:57:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_path_error(void)
{
	write(1, IMG_PATH_NOT_FOUND, ft_strlen(IMG_PATH_NOT_FOUND));
}

int	min_size_error(void)
{
	write(1, MIN_SIZE_ERROR, ft_strlen(MIN_SIZE_ERROR));
	return (0);
}

int	no_way_end(void)
{
	write(1, NO_WINNABLE_WAY, ft_strlen(NO_WINNABLE_WAY));
	return (0);
}

int	map_form_error(void)
{
	write(1, MAP_FORM_ERROR, ft_strlen(MAP_FORM_ERROR));
	return (0);
}

int	element_error(void)
{
	write(1, MAP_ELEMENT_ERROR, ft_strlen(MAP_ELEMENT_ERROR));
	return (0);
}
