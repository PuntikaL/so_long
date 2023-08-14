/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:55:14 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 16:48:59 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char(const char *s)
{
	int	i;

	if (*s == '\0' || s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	get_size_plus(t_map *p, char *buffer, int fd)
{
	int		height;
	int		width;

	height = 0;
	width = count_char(buffer);
	while (buffer != NULL)
	{
		height++;
		if (width != count_char(buffer))
		{
			free(buffer);
			ft_printf("Map pattern not recognize");
			return (0);
		}
		width = count_char(buffer);
		free(buffer);
		buffer = get_next_line(fd);
		p->width = width;
		p->height = height;
	}
	return (1);
}

int	get_size(t_map	*p, char *str)
{
	int		fd;
	char	*buffer;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Can not open map");
		return (0);
	}
	buffer = get_next_line(fd);
	if (!(get_size_plus(p, buffer, fd)))
		return (0);
	close(fd);
	return (1);
}

int	valid_wall(t_map *p)
{
	int	i;

	i = -1;
	while (++i < p->width)
	{
		if (p->map[0][i] != '1')
			return (0);
		if (p->map[p->height - 1][i] != '1')
			return (0);
	}
	i = -1;
	while (++i < p->height)
	{
		if (p->map[i][0] != '1')
			return (0);
		if (p->map[i][p->width - 1] != '1')
			return (0);
	}
	return (1);
}

int	get_map(t_map *p, char *str)
{
	int		fd;
	char	*buffer;
	int		i;

	fd = open(str, O_RDONLY);
	buffer = get_next_line(fd);
	p->map = malloc(sizeof(char *) * (p->height + 1));
	i = 0;
	while (buffer != NULL)
	{
		p->map[i] = buffer;
		buffer = get_next_line(fd);
		i++;
	}
	p->map[i] = NULL;
	close(fd);
	if (!valid_wall(p))
	{
		ft_printf("Map error");
		return (0);
	}
	return (1);
}
