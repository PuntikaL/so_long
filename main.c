/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:38:50 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/06 16:11:19 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv){
	t_map	m;
	t_game	g;
	t_vars	v;

	if (argc != 2)
	{
		printf("syntex is bash program name follow by map name : ./so_long maps/ex_map");
		return (0);
	}
	if (!get_size(&m, argv[1]))
	{
		printf("fail to get size");
		return (0);
	}
	if(get_map(&m, argv[1]) == 0)
		return (0);
	set_game(&g);
	v.var_game = &g;
	v.var_map = &m;
	printf("no error\n");
	create_window(v.var_map, &v);
	return (0);
}