/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:47:42 by schahir           #+#    #+#             */
/*   Updated: 2025/03/24 16:36:52 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_textures(t_map *map)
{
	int	ps;
	t_graphics *g;

	g = &map->graphics;
	ps = PIXEL_SIZE;
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "textures/w.xpm", &ps, &ps);
	if (!g->img_wall)
		exit_free(map, "Error loading wall");
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "textures/f.xpm", &ps, &ps);
	if (!g->img_floor)
		exit_free(map, "Error loading floor");
	g->img_player = mlx_xpm_file_to_image(g->mlx, "textures/p.xpm", &ps, &ps);
	if (!g->img_player)
		exit_free(map, "Error loading player");
	g->img_collectible = mlx_xpm_file_to_image(g->mlx, "textures/c.xpm", &ps, &ps);
	if (!g->img_collectible)
		exit_free(map, "Error loading collectible");
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "textures/e.xpm", &ps, &ps);
	if (!g->img_exit)
		exit_free(map, "Error loading exit");
	g->img_on_exit = mlx_xpm_file_to_image(g->mlx, "textures/pe.xpm", &ps, &ps);
	if (!g->img_on_exit)
		exit_free(map, "Error loading player on exit");
}

void	render_textures(t_map *map, int on_exit)
{
	int			x;
	int			y;
	void		*img;
	t_graphics *g;

	g = &map->graphics;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			img = g->img_floor;
			if (map->grid[y][x] == '1')
				img = g->img_wall;
			else if (map->grid[y][x] == 'C')
				img = g->img_collectible;
			else if (map->grid[y][x] == 'E')
				img = g->img_exit;
			else if (map->grid[y][x] == 'P')
			{
				if (on_exit)
					img = g->img_on_exit;
				else
					img = g->img_player;
			}
			mlx_put_image_to_window(g->mlx, g->win, img,x * PIXEL_SIZE, y * PIXEL_SIZE);
			x++;
		}
		y++;
	}
}
