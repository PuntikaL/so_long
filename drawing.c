/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:21:07 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 17:05:28 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pillar(t_vars *g, int pos_x, int pos_y)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	if ((pos_x % 5 + pos_y % 3) % 3 == 0)
		pic_path = "./pics/barrel_wall.xpm";
	else
		pic_path = "./pics/pillar_wall.xpm";
	img = mlx_xpm_file_to_image(g->mlx, pic_path, &img_width, &img_height);
	mlx_put_image_to_window(g->mlx, g->win, img, pos_x, pos_y);
}

void	draw_tree(t_vars *g, int pos_x, int pos_y)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	g->var_game->all_cnum++;
	pic_path = "./pics/tree_collect.xpm";
	img = mlx_xpm_file_to_image(g->mlx, pic_path, &img_width, &img_height);
	mlx_put_image_to_window(g->mlx, g->win, img, pos_x, pos_y);
}

void	draw_exit(t_vars *g, int pos_x, int pos_y)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	g->var_map->e_pos.x = pos_x;
	g->var_map->e_pos.y = pos_y;
	pic_path = "./pics/close_chest.xpm";
	img = mlx_xpm_file_to_image(g->mlx, pic_path, &img_width, &img_height);
	mlx_put_image_to_window(g->mlx, g->win, img, pos_x, pos_y);
}

void	set_char(t_vars *g, int x, int y)
{
	void		*pic;
	t_player	*p1;
	int			img_width;
	int			img_height;

	p1 = &g->var_p;
	pic = mlx_xpm_file_to_image(g->mlx, "./pics/bunny.xpm", \
	&img_width, &img_height);
	p1->img = pic;
	p1->score = 0;
	p1->step_count = 0;
	p1->pos.x = x;
	p1->pos.y = y;
	draw_char(g->mlx, g->win, p1);
}

void	set_game(t_game *game)
{
	game->game_status = 1;
	game->door_status = 0;
	game->all_cnum = 0;
}
