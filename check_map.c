/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:09:48 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 16:51:15 by pleepago         ###   ########.fr       */
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
