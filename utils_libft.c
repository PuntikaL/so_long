/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:48:27 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 16:49:20 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_filename_ok(char *file_name)
{
	int			len;
	const char	*start;

	len = ft_strlen(file_name);
	start = (const char *) &file_name[(len - 4)];
	if (ft_strncmp(start, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;	

	i = 0;
	j = 0;
	while ((s1[i] != '\0' || s2[j] != '\0') && n > 0)
	{
		if (s1[i] != s2[j])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
			break ;
		}
		i ++;
		j ++;
		n --;
	}
	return (0);
}

void	redraw_tile(t_pair pos, t_vars *vars)
{
	void	*img;

	img = request_tile(vars->mlx, pos.y / 38 + ((pos.x + pos.y) / 38));
	mlx_put_image_to_window(vars->mlx, vars->win, img, pos.x, pos.y);
}

void	draw_char(void *mlx, void *mlx_win, t_player *p1)
{
	mlx_put_image_to_window(mlx, mlx_win, p1->img, p1->pos.x, p1->pos.y);
}

void	redraw_exit(void *mlx, void *mlx_win, void *img, t_pair exit_pos)
{
	mlx_put_image_to_window(mlx, mlx_win, img, exit_pos.x, exit_pos.y);
}
