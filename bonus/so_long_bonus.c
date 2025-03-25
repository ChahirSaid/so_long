/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:19:28 by schahir           #+#    #+#             */
/*   Updated: 2025/03/24 23:30:12 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	valid_name(char *map_path)
{
	int	len;

	if (!map_path)
		return (0);
	len = ft_strlen(map_path);
	if (len <= 4 || ft_strcmp(&map_path[len - 4], ".ber") != 0)
		return (0);
	if (ft_strcmp(&map_path[len - 5], "/.ber") == 0)
		return (0);
	return (1);
}

static void	ft_init(t_map *map)
{
	int	height;
	int	width;

	height = map->height * PIXEL_SIZE;
	width = map->width * PIXEL_SIZE;
	map->graphics.mlx = mlx_init();
	if (!map->graphics.mlx)
		exit_free(map, "Minilibx initialization failed");
	map->graphics.win = mlx_new_window(map->graphics.mlx, width, height,
			"So_long");
	if (!map->graphics.win)
		exit_free(map, "Window creation failed");
	load_textures(map);
	render_textures(map, 0);
	mlx_hook(map->graphics.win, 17, 0, exit_success, map);
	mlx_key_hook(map->graphics.win, &handle_input, map);
	mlx_loop(map->graphics.mlx);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		exit_error("Invalid arguments [./so_long maps/filename.ber]");
	if (!valid_name(av[1]))
		exit_error("Invalid map name or path");
	map = read_map(av[1]);
	check_rectangular(map);
	check_borders(map);
	elements_count(map);
	check_path(map);
	ft_init(map);
	free_map(map);
}
