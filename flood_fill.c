/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:30:30 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 16:34:47 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walking(char **new_map, int i, int j, t_pair size)
{
	new_map[i][j] = 'X';
	if (i >= size.x || i < 1)
		return ;
	if (j >= size.y || j < 1)
		return ;
	if (new_map[i + 1][j] != '1' && new_map[i + 1][j] != 'X')
		walking(new_map, i + 1, j, size);
	if (new_map[i][j + 1] != '1' && new_map[i][j + 1] != 'X')
		walking(new_map, i, j + 1, size);
	if (new_map[i - 1][j] != '1' && new_map[i - 1][j] != 'X')
		walking(new_map, i - 1, j, size);
	if (new_map[i][j - 1] != '1' && new_map[i][j - 1] != 'X')
		walking(new_map, i, j - 1, size);
}

int	copy_map(char **new_map, char **old_map)
{
	int	i;

	i = 0;
	while (old_map[i] != NULL)
	{
		new_map[i] = ft_strjoin("", old_map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (1);
}

int	pass(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	get_p_pos(t_vars *vars)
{
	int	i;
	int	j;

	i = 1;
	while (vars->var_map->map[i] != NULL)
	{
		j = 1;
		while (vars->var_map->map[i][j] != '\0')
		{
			if (vars->var_map->map[i][j] == 'P')
			{
				vars->var_map->p_pos.x = i;
				vars->var_map->p_pos.y = j;
			}
			j++;
		}
		i++;
	}
}

int	valid_play(t_vars *vars)
{
	char	**new_map;
	t_pair	size;

	size.y = vars->var_map->width;
	size.x = vars->var_map->height;
	new_map = malloc(sizeof(char *) * (vars->var_map->height + 1));
	copy_map(new_map, vars->var_map->map);
	get_p_pos(vars);
	walking(new_map, vars->var_map->p_pos.x, vars->var_map->p_pos.y, size);
	if (pass(new_map))
	{
		free_map(new_map);
		return (1);
	}
	free_map(new_map);
	return (0);
}
