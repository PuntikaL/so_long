/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:38:50 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 17:48:42 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_map(vars->var_map->map);
	exit(0);
}

int	early_check(t_map *m, char **argv)
{
	if (!get_size(m, argv[1]))
	{
		ft_printf("Error\n	fail to get size\n");
		return (0);
	}
	if (!(ft_filename_ok(argv[1])))
	{
		ft_printf("Error\n	Wrong file type\n");
		return (0);
	}
	if (get_map(m, argv[1]) == 0)
		return (0);
	if (!(valid_char(m)))
	{
		ft_printf("Error\n	not valid components");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	m;
	t_game	g;
	t_vars	v;

	if (argc != 2)
	{
		ft_printf("Error\n	syntex is bash program name follow by map\
name : ./so_long map_name.ber\n");
		return (0);
	}
	if (!(early_check(&m, argv)))
		return (0);
	set_game(&g);
	v.var_game = &g;
	v.var_map = &m;
	ft_printf("Finish rendering map\n");
	if (!(valid_play(&v)))
	{
		ft_printf("Error\n	Map not valid\n");
		free_map(v.var_map->map);
		exit(0);
	}
	create_window(v.var_map, &v);
	return (0);
}
