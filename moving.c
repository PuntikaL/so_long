/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:12:55 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 17:13:15 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk(t_vars *vars, void *img)
{
	vars->var_p.step_count++;
	ft_printf("step_count = %d\n", vars->var_p.step_count);
	vars->var_p.img = img;
	draw_char(vars->mlx, vars->win, &vars->var_p);
}

void	move_up(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;
	char	**m;

	m = vars->var_map->map;
	pic_path = "./pics/bunny_up.xpm";
	img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
	if (vars->var_p.pos.y / 38 == 0)
		return ;
	if (m[vars->var_p.pos.y / 38 - 1][vars->var_p.pos.x / 38] == 'E'\
	&& vars->var_game->door_status == 0)
		return ;
	if (m[vars->var_p.pos.y / 38 - 1][vars->var_p.pos.x / 38] != '1')
	{
		if (m[vars->var_p.pos.y / 38 - 1][vars->var_p.pos.x / 38] == 'C')
		{
			m[vars->var_p.pos.y / 38 - 1][vars->var_p.pos.x / 38] = '0';
			vars->var_p.score++;
		}
		redraw_tile(vars->var_p.pos, vars);
		vars->var_p.pos.y -= 38;
		walk(vars, img);
	}
}

void	move_down(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;
	char	**m;

	m = vars->var_map->map;
	pic_path = "./pics/bunny.xpm";
	img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
	if (vars->var_p.pos.y / 38 == vars->var_map->height)
		return ;
	if (m[vars->var_p.pos.y / 38 + 1][vars->var_p.pos.x / 38] == 'E'\
	&& vars->var_game->door_status == 0)
		return ;
	if (m[vars->var_p.pos.y / 38 + 1][vars->var_p.pos.x / 38] != '1')
	{
		if (m[vars->var_p.pos.y / 38 + 1][vars->var_p.pos.x / 38] == 'C')
		{
			m[vars->var_p.pos.y / 38 + 1][vars->var_p.pos.x / 38] = '0';
			vars->var_p.score++;
		}
		redraw_tile(vars->var_p.pos, vars);
		vars->var_p.pos.y += 38;
		walk(vars, img);
	}
}

void	move_left(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;
	char	**m;

	m = vars->var_map->map;
	pic_path = "./pics/bunny_left.xpm";
	img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
	if (vars->var_p.pos.x / 38 == 0)
		return ;
	if (m[vars->var_p.pos.y / 38][vars->var_p.pos.x / 38 - 1] == 'E'\
	&& vars->var_game->door_status == 0)
		return ;
	if (m[vars->var_p.pos.y / 38][vars->var_p.pos.x / 38 - 1] != '1')
	{
		if (m[vars->var_p.pos.y / 38][vars->var_p.pos.x / 38 - 1] == 'C')
		{
			m[vars->var_p.pos.y / 38][vars->var_p.pos.x / 38 - 1] = '0';
			vars->var_p.score++;
		}
		redraw_tile(vars->var_p.pos, vars);
		vars->var_p.pos.x -= 38;
		walk(vars, img);
	}
}

void	move_right(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;
	char	**m;

	m = vars->var_map->map;
	pic_path = "./pics/bunny_right.xpm";
	img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
	if (vars->var_p.pos.x / 38 == vars->var_map->width)
		return ;
	if (m[vars->var_p.pos.y / 38][vars->var_p.pos.x / 38 + 1] == 'E'\
	&& vars->var_game->door_status == 0)
		return ;
	if (m[vars->var_p.pos.y / 38][vars->var_p.pos.x / 38 + 1] != '1')
	{
		if (m[vars->var_p.pos.y / 38][vars->var_p.pos.x / 38 + 1] == 'C')
		{
			m[vars->var_p.pos.y / 38][vars->var_p.pos.x / 38 + 1] = '0';
			vars->var_p.score++;
		}
		redraw_tile(vars->var_p.pos, vars);
		vars->var_p.pos.x += 38;
		walk(vars, img);
	}
}
