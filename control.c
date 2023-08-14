/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:03:43 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 17:15:12 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_vars *vars)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	if (vars->var_p.score == vars->var_game->all_cnum)
	{
		vars->var_game->door_status = 1;
		pic_path = "./pics/open_chest.xpm";
		img = mlx_xpm_file_to_image(vars->mlx, pic_path, \
		&img_width, &img_height);
		redraw_exit(vars->mlx, vars->win, img, vars->var_map->e_pos);
	}
	if (vars->var_p.pos.x == vars->var_map->e_pos.x && \
	vars->var_p.pos.y == vars->var_map->e_pos.y)
	{
		ft_printf("Bunny Jump Out!");
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
