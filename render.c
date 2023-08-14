/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:31:21 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 16:49:07 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	*request_tile(void	*mlx, int select)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;

	if (select % 11 != 0)
		pic_path = "./pics/tile_grass.xpm";
	else
		pic_path = "./pics/tile_flower.xpm";
	img = mlx_xpm_file_to_image(mlx, pic_path, &img_width, &img_height);
	return (img);
}

void	render_wall(t_vars *g, int w, int h)
{
	void	*img;
	char	*pic_path;
	int		img_width;
	int		img_height;
	int		i;

	pic_path = "./pics/stone_wall.xpm";
	img = mlx_xpm_file_to_image(g->mlx, pic_path, &img_width, &img_height);
	i = 0;
	while (i < h)
	{
		mlx_put_image_to_window(g->mlx, g->win, img, 0, i);
		mlx_put_image_to_window(g->mlx, g->win, img, w - 38, i);
		i += 38;
	}
	i = 0;
	while (i < w)
	{
		mlx_put_image_to_window(g->mlx, g->win, img, i, 0);
		mlx_put_image_to_window(g->mlx, g->win, img, i, h - 38);
		i += 38;
	}
}

void	create_window(t_map *p, t_vars *g)
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;

	width = p->width * 38;
	height = p->height * 38;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Happy Bunny");
	g->mlx = mlx;
	g->win = mlx_win;
	draw_tile(g, width, height);
	render_wall(g, width, height);
	get_pos_all(g, p);
	test_hook(g);
	mlx_loop(mlx);
}

void	draw_tile(t_vars *g, int width, int height)
{
	int		i;
	int		j;
	int		c;
	void	*img;

	i = 0;
	c = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			c += 7;
			img = request_tile(g->mlx, j / 38 + (c / 38));
			mlx_put_image_to_window(g->mlx, g->win, img, i, j);
			j += 38;
		}
		i += 38;
	}
}
