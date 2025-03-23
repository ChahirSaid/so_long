/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:47:42 by schahir           #+#    #+#             */
/*   Updated: 2025/03/23 21:50:28 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	g->img_exit = mlx_xpm_file_to_image(g->img_exit, "textures/e.xpm", &ps, &ps);
	if (!g->img_exit)
		exit_free(map, "Error loading exit");
	g->img_on_exit = mlx_xpm_file_to_image(g->mlx, "textures/pe.xpm", &ps, &ps);
	if (!g->img_on_exit)
		exit_free(map, "Error loading player on exit");
}

void	render_textures(t_map *map)
{
	int			x;
	int			y;
	t_graphics *g;

	g = &map->graphics;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_put_image_to_window(g->mlx,g->win,g->img_floor,x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (map->grid[x][y] == '1')
				mlx_put_image_to_window(g->mlx,g->win,g->img_wall,x * PIXEL_SIZE, y * PIXEL_SIZE);
			else if (map->grid[x][y] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->img_collectible, x * PIXEL_SIZE, y * PIXEL_SIZE);
			else if (map->grid[x][y] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->img_exit, x * PIXEL_SIZE, y * PIXEL_SIZE);
			else if (map->grid[x][y] == 'P')
			{
				if (x == map->exit_x && y == map->exit_y)
					mlx_put_image_to_window(g->mlx, g->win, g->img_on_exit, x * PIXEL_SIZE, y * PIXEL_SIZE);
				else
					mlx_put_image_to_window(g->mlx, g->win, g->img_player, x * PIXEL_SIZE, y * PIXEL_SIZE);
			}
			x++;
		}
		y++;
	}
}
