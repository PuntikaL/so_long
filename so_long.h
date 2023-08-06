/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:41:20 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/06 12:37:48 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "./ft_gnl/get_next_line.h"

typedef	struct s_pair
{
	int	x;
	int	y;
}t_pair;

typedef struct s_player
{
	void	*img;
	int		score;
	int		step_count;
	t_pair	pos;
}t_player;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	t_pair	p_pos;
	t_pair	e_pos;
}t_map;

typedef struct s_game
{
	t_map	g_map;
	int	game_status;
	int	door_status;
	int	all_cnum;
}t_game;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_player	var_player;
	t_map	*var_map;
	t_game	*var_game;
}t_vars;


int	get_size(t_map	*p, char *str);
int	count_char(const char *s);
int	get_map(t_map *p, char *str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	*request_tile(void	*mlx, int select);
void	create_window(t_map *p, t_vars *g);
void	draw_char(void *mlx, void *mlx_win, t_player *p1);
int	valid_wall(t_map *p);
void	draw_pillar(t_vars *g, int pos_x, int pos_y);
void	draw_tree(t_vars *g, int pos_x, int pos_y);
void	draw_exit(t_vars *g, int pos_x, int pos_y);
int	get_pos_all(t_vars *g, t_map *p);
void	set_char(t_vars *g, int x, int y);
void	draw_tile(t_vars *g, int width, int height);
void	set_game();
void	render_wall(t_vars *g, int w, int h);
//TO-DO
int	key_hook(int keycode, t_vars *vars);
void	test_hook(t_vars *v);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	redraw_tile(t_pair pos, t_vars *vars);
#endif