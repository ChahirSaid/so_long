/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:05:25 by schahir           #+#    #+#             */
/*   Updated: 2025/03/23 18:15:11 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	exit_error(char *message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit (1);
}

void	exit_free(t_map *map, char *message)
{
	free_map(map);
    exit_error(message);
}

static void	destroy_images(t_map *map)
{
	if (map->graphics.img_wall)
		mlx_destroy_image(map->graphics.mlx, map->graphics.img_wall);
	if (map->graphics.img_floor)
		mlx_destroy_image(map->graphics.mlx, map->graphics.img_floor);
	if (map->graphics.img_player)
		mlx_destroy_image(map->graphics.mlx, map->graphics.img_player);
	if (map->graphics.img_collectible)
		mlx_destroy_image(map->graphics.mlx, map->graphics.img_collectible);
	if (map->graphics.img_exit)
		mlx_destroy_image(map->graphics.mlx, map->graphics.img_exit);
	if (map->graphics.img_on_exit)
		mlx_destroy_image(map->graphics.mlx, map->graphics.img_on_exit);
}

static void	destroy_window(t_map *map)
{
	mlx_clear_window(map->graphics.mlx, map->graphics.win);
	mlx_destroy_window(map->graphics.mlx, map->graphics.win);
}

void	free_map(t_map *map)
{
	int i;

	if(!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while(i < map->height)
		{
			if(map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	if (map->graphics.mlx)
	{
		destroy_images(map);
		if (map->graphics.win)
			destroy_window(map);
		mlx_destroy_display(map->graphics.mlx);
		free(map->graphics.mlx);
	}
	free(map);
}
