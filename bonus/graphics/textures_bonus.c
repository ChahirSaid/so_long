/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:47:42 by schahir           #+#    #+#             */
/*   Updated: 2025/03/25 04:30:16 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	load_more_textures(t_map *map, int ps)
{
	t_graphics	*g;

	g = &map->graphics;
	g->img_collectible = mlx_xpm_file_to_image(g->mlx, "textures/c.xpm", &ps,
			&ps);
	if (!g->img_collectible)
		exit_free(map, "Error loading collectible");
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "textures/e.xpm", &ps, &ps);
	if (!g->img_exit)
		exit_free(map, "Error loading exit");
	g->img_on_exit = mlx_xpm_file_to_image(g->mlx, "textures/pe.xpm", &ps, &ps);
	if (!g->img_on_exit)
		exit_free(map, "Error loading player on exit");
	g->img_enemy = mlx_xpm_file_to_image(g->mlx, "textures/b.xpm", &ps, &ps);
	if (!g->img_enemy)
		exit_free(map, "Error loading enemy");
}

void	load_textures(t_map *map)
{
	int			ps;
	t_graphics	*g;

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
	load_more_textures(map, ps);
}

void	*get_texture(t_map *map, char element, int on_exit)
{
	if (element == '1')
		return (map->graphics.img_wall);
	if (element == 'C')
		return (map->graphics.img_collectible);
	if (element == 'E')
		return (map->graphics.img_exit);
	if (element == 'B')
		return (map->graphics.img_enemy);
	if (element == 'P')
	{
		if (on_exit)
			return (map->graphics.img_on_exit);
		return (map->graphics.img_player);
	}
	return (map->graphics.img_floor);
}

void	render_textures(t_map *map, int on_exit)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			img = get_texture(map, map->grid[y][x], on_exit);
			mlx_put_image_to_window(map->graphics.mlx, map->graphics.win, img, x
				* PIXEL_SIZE, y * PIXEL_SIZE);
			x++;
		}
		y++;
	}
}
