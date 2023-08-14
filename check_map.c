/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:09:48 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 16:57:05 by pleepago         ###   ########.fr       */
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

int	valid_char(t_map *m)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;

	i = -1;
	p_count = 0;
	e_count = 0;
	while (m->map[++i] != NULL)
	{
		j = 0;
		while (m->map[i][j] != '\0')
		{
			if (!(in_list_char(m->map[i][j])))
				return (0);
			if (m->map[i][j] == 'P')
				p_count++;
			if (m->map[i][j] == 'E')
				e_count++;
			j++;
		}
	}
	if (p_count != 1 || e_count != 1)
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
