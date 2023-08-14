/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:03:43 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 16:02:17 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk(t_vars *vars, void *img)
{
	vars->var_player.step_count++;
	ft_printf("step_count = %d\n", vars->var_player.step_count);
	vars->var_player.img = img;
	draw_char(vars->mlx, vars->win, &vars->var_player);
}

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
	if (vars->var_map->map[vars->var_player.pos.y/38 - 1][vars->var_player.pos.x/38] == 'E'\
	&& vars->var_game->door_status == 0)
	{
		return ;
	}
	if (vars->var_map->map[vars->var_player.pos.y/38 - 1][vars->var_player.pos.x/38] != '1')
	{
		if(vars->var_map->map[vars->var_player.pos.y/38 - 1][vars->var_player.pos.x/38] == 'C')
		{
			vars->var_map->map[vars->var_player.pos.y/38 - 1][vars->var_player.pos.x/38] = '0';
			vars->var_player.score++;
		}
		redraw_tile(vars->var_player.pos, vars);
		vars->var_player.pos.y -= 38;
		walk(vars, img);
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
	if (vars->var_map->map[vars->var_player.pos.y/38 + 1][vars->var_player.pos.x/38] == 'E'\
	&& vars->var_game->door_status == 0)
	{
		return ;
	}
	if (vars->var_map->map[vars->var_player.pos.y/38 + 1][vars->var_player.pos.x/38] != '1')
	{
		if(vars->var_map->map[vars->var_player.pos.y/38 + 1][vars->var_player.pos.x/38] == 'C')
		{
			vars->var_map->map[vars->var_player.pos.y/38 + 1][vars->var_player.pos.x/38] = '0';
			vars->var_player.score++;
		}
		redraw_tile(vars->var_player.pos, vars);
		vars->var_player.pos.y += 38;
		walk(vars, img);
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
	if (vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 - 1] == 'E'\
	&& vars->var_game->door_status == 0)
	{
		return ;
	}
	if (vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 - 1] != '1')
	{
		if(vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 - 1] == 'C')
		{
			vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 - 1] = '0';
			vars->var_player.score++;
		}
		redraw_tile(vars->var_player.pos, vars);
		vars->var_player.pos.x -= 38;
		walk(vars, img);
	}
}

void	move_right(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	pic_path = "./pics/bunny_right.xpm";
	if (vars->var_player.pos.x/38 == vars->var_map->width)
		return ;
	if (vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 + 1] == 'E'\
	&& vars->var_game->door_status == 0)
	{
		return ;
	}
	if (vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 + 1] != '1')
	{
		if(vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 + 1] == 'C')
		{
			vars->var_map->map[vars->var_player.pos.y/38][vars->var_player.pos.x/38 + 1] = '0';
			vars->var_player.score++;
		}
		img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
		redraw_tile(vars->var_player.pos, vars);
		vars->var_player.pos.x += 38;
		walk(vars, img);
	}
}

void	check_exit(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;
	
	if (vars->var_player.score == vars->var_game->all_cnum)
	{
		vars->var_game->door_status = 1;
		pic_path = "./pics/open_chest.xpm";
		img = mlx_xpm_file_to_image(vars->mlx, pic_path, &img_width, &img_height);
		redraw_exit(vars->mlx, vars->win, img, vars->var_map->e_pos);
	}
	if (vars->var_player.pos.x == vars->var_map->e_pos.x && \
	vars->var_player.pos.y == vars->var_map->e_pos.y)
	{
		ft_exit(vars);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	check_exit(vars);
	if (keycode == 126)
		move_up(vars);
	else if (keycode == 125)
		move_down(vars);
	else if (keycode == 123)
		move_left(vars);
	else if (keycode == 124)
		move_right(vars);
	else if (keycode == 53)
		ft_exit(vars);
	return (0);
}

void	test_hook(t_vars *v)
{
	mlx_key_hook(v->win, key_hook, v);
}