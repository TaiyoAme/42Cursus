/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:59:18 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/12 18:31:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../Libft/libft.h"
# include "../mlx_linux/mlx_int.h"
# include "../mlx_linux/mlx.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define WIN 1
# define LOOSE 0
//img size in Px (Image PiXel)
# define IPX 50
//ERROR_MESSAGE
# define MIN_SIZE_ERROR "Error\nYour map size is too small or empty\n"
# define INVALID_CHAR_FOUND "Error\nInvalid char found in map\n"
# define NO_WINNABLE_WAY "Error\nCollectible or exit can't be reach)\n"
# define IMG_PATH_NOT_FOUND "Error\nOne or more image path not found\n"
# define MAP_FORM_ERROR "Error\n Map form isn't a rectangle made of '1'\n"
# define MAP_ELEMENT_ERROR "Error\n Missing or more than 1 Exit, Collectible \
or Player\n"

typedef struct s_map
{
	char	**map;
	int		length;
	int		width;
	int		items;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	items;
}	t_player;

typedef struct s_animation
{
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	int		height;
	int		width;
	int		frame;
	void	*curr;
	int		img_index;
}	t_anim;

typedef struct s_step
{
	void	*step_img;
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*img9;
	int		width;
	int		height;
}	t_step;

typedef struct s_map_img
{
	void	*floor;
	void	*player;
	void	*items;
	void	*wall;
	void	*exit;
	void	*villain;
	int		height;
	int		width;

}	t_map_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*player;
	t_map		*xpm_map;
	t_map_img	*map_img;
	t_player	**villain;
	t_step		*s_img;
	t_anim		*p_anim;
	t_anim		*d_anim;
//ITEM = int[2] 0.X 1.Y
	int			**item_list;
}	t_data;

t_player	**get_villains(t_data *data);
void		switch_move(t_data *data, t_player *vil);
void		vil_step(t_data *data);
void		game_end(t_data *data, int win);
void		is_touched_by_vil(t_data *data);
int			check_step(t_data *data, int x, int y);
void		displ(t_data data);
void		add_vil(t_data *data);
void		displ_steps(t_data *data);
void		init_step(t_data *data);
t_player	*init_vil(int x, int y);
int			extension_check(char *path);

//UTILS
int			ft_find_occur(char *str, char elmt);
void		put_img(t_data *data, void *img, int x, int y);
int			destr(t_data *data);
t_data		*empty_data(void);

int			**get_items(t_data *data);
void		dsp_items(t_data *data);
int			is_collected(t_data *data);

//ERROR_FUNC
int			element_error(void);
int			min_size_error(void);
int			no_way_end(void);
int			map_form_error(void);
void		img_path_error(void);
//MAP CHECK
int			check_map(char	*filename);
t_data		*init_data(int fd);
int			check_flood_tab(t_data *data);
int			count_element(t_map map);

//PLAYER
t_player	*get_player(t_data *data);
void		up(t_data *data, t_player *pl_or_vil);
void		down(t_data *data, t_player *pl_or_vil);
void		left(t_data *data, t_player *pl_or_vil);
void		right(t_data *data, t_player *pl_or_vil);

//FREE
void		*free_str_tab(char **str, int len, int is_strtab);
void		*free_t_data(t_data *data);
void		*free_xmp_map(t_map *xpm_map);
void		*empty_map(t_data *data);
void		*free_item(int **item_list, int size);

//ANIMATION
void		display_map(t_data *data);
int			init_player_anim(t_data *data);
int			init_door_anim(t_data *data);
int			update_anim(t_data *data);

#endif
