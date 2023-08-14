/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:09:48 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 17:39:02 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	in_list_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E'\
	|| c == 'P' || c == '\n')
		return (1);
	else
		return (0);
}

static void	declear_valid(t_pair *loop, t_pair *a, int *c_count)
{
	loop->x = -1;
	a->x = 0;
	a->y = 0;
	*c_count = 0;
}

//a.x is p_count and a.y is e_count both have to be only 1
int	valid_char(t_map *m)
{
	t_pair	loop;
	t_pair	a;
	int		c_count;

	declear_valid(&loop, &a, &c_count);
	while (m->map[++loop.x] != NULL)
	{
		loop.y = 0;
		while (m->map[loop.x][loop.y] != '\0')
		{
			if (!(in_list_char(m->map[loop.x][loop.y])))
				return (0);
			if (m->map[loop.x][loop.y] == 'P')
				a.x++;
			if (m->map[loop.x][loop.y] == 'E')
				a.y++;
			if (m->map[loop.x][loop.y] == 'C')
				c_count++;
			loop.y++;
		}
	}
	if (a.x != 1 || a.y != 1 || c_count < 1)
		return (0);
	return (1);
}

int	get_pos_all(t_vars *g, t_map *p)
{
	int	i;
	int	j;

	i = 1;
	while (i < p->height - 1)
	{
		j = 1;
		while (j < p->width - 1)
		{
			if (p->map[i][j] == '1')
				draw_pillar(g, j * 38, i * 38);
			else if (p->map[i][j] == 'C')
				draw_tree(g, j * 38, i * 38);
			else if (p->map[i][j] == 'P')
				set_char(g, j * 38, i * 38);
			else if (p->map[i][j] == 'E')
				draw_exit(g, j * 38, i * 38);
			j++;
		}
		i++;
	}
	return (1);
}
