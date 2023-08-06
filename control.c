/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:03:43 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/06 17:04:40 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	pic_path = "./pics/bunny_up.xpm";
	img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
	if (vars->var_player.pos.y/38 == 0)
		return ;
	if (vars->var_map->map[vars->var_player.pos.y/38 - 1][vars->var_player.pos.x/38] != '1')
	{
		redraw_tile(vars->var_player.pos, vars);
		vars->var_player.img = img;
		vars->var_player.pos.y -= 38;
		draw_char(vars->mlx, vars->win, &vars->var_player);
		vars->var_player.step_count += 1;
	}
}

void	move_down(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	pic_path = "./pics/bunny.xpm";
	img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
	if (vars->var_player.pos.y/38 == vars->var_map->height)
		return ;
	if (vars->var_map->map[vars->var_player.pos.y/38 + 1][vars->var_player.pos.x/38] != '1')
	{
		redraw_tile(vars->var_player.pos, vars);
		vars->var_player.img = img;
		vars->var_player.pos.y += 38;
		draw_char(vars->mlx, vars->win, &vars->var_player);
		vars->var_player.step_count += 1;
	}
}

void	move_left(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	pic_path = "./pics/bunny_left.xpm";
	img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
	if (vars->var_player.pos.x/38 == 0)
		return ;
	if (vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 - 1] != '1')
	{
		redraw_tile(vars->var_player.pos, vars);
		vars->var_player.img = img;
		vars->var_player.pos.x -= 38;
		draw_char(vars->mlx, vars->win, &vars->var_player);
		vars->var_player.step_count += 1;
	}
}

void	move_right(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	pic_path = "./pics/bunny_right.xpm";
	//if (vars->var_player.pos.x/38 == vars->var_map->width)
	//	return ;
	printf("UP: x = %d  y = %d\n", vars->var_player.pos.y / 38 , vars->var_player.pos.x / 38 + 1);
	printf("UP_MAP = %c", vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 + 1]);
	if (vars->var_map->map[vars->var_player.pos.x/38][vars->var_player.pos.y/38 + 1] != '1')
	{
		img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
		redraw_tile(vars->var_player.pos, vars);
		vars->var_player.img = img;
		vars->var_player.pos.x += 38;
		draw_char(vars->mlx, vars->win, &vars->var_player);
		vars->var_player.step_count += 1;
	}
}


int	key_hook(int keycode, t_vars *vars)
{
	vars->var_player.step_count += 1;
	printf("x = %d   ", vars->var_player.pos.x/38);
	printf("y = %d\n", vars->var_player.pos.y/38);
	printf("map = %c\n", vars->var_map->map[vars->var_player.pos.x/38][vars->var_player.pos.y/38]);
	if (keycode == 126)
		move_up(vars);
	else if (keycode == 125)
		move_down(vars);
	else if (keycode == 123)
		move_left(vars);
	else if (keycode == 124)
		move_right(vars);
	return (0);
}

void	test_hook(t_vars *v)
{
	printf("test = %c\n", v->var_map->map[1][6]);
	mlx_key_hook(v->win, key_hook, v);
}