/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:52:47 by schahir           #+#    #+#             */
/*   Updated: 2025/03/25 04:13:26 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	print_moves(t_map *map)
{
	static int	count;
	char		*str;

	str = ft_itoa(count);
	mlx_string_put(map->graphics.mlx, map->graphics.win, 24, 24, 0xffffffff,
		"moves:");
	mlx_string_put(map->graphics.mlx, map->graphics.win, 24, 44, 0xffffffff,
		str);
	free(str);
	count++;
}

static int	handle_exit(t_map *map, int new_x, int new_y)
{
	if (map->collectibles == 0)
	{
		ft_putstr_fd("STAGE CLEARED\n", 1);
		free_map(map);
		exit(0);
	}
	map->exit_x = new_x;
	map->exit_y = new_y;
	return (1);
}

static void	end_game(t_map *map)
{
	ft_putstr_fd("YOU DIED\n", 1);
	free_map(map);
	exit(0);
}

static void	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;
	int	on_exit;

	new_x = map->player_x + x;
	new_y = map->player_y + y;
	on_exit = 0;
	if (map->grid[new_y][new_x] == '1')
		return ;
	if (map->grid[new_y][new_x] == 'B')
		end_game(map);
	if (map->grid[new_y][new_x] == 'C')
		map->collectibles--;
	if (map->grid[new_y][new_x] == 'E')
		on_exit = handle_exit(map, new_x, new_y);
	if (map->player_y == map->exit_y && map->player_x == map->exit_x)
		map->grid[map->player_y][map->player_x] = 'E';
	else
		map->grid[map->player_y][map->player_x] = '0';
	map->grid[new_y][new_x] = 'P';
	map->player_x = new_x;
	map->player_y = new_y;
	render_textures(map, on_exit);
	print_moves(map);
}

int	handle_input(int key, t_map *map)
{
	if (key == ESC)
		exit_success(map);
	if (key == W || key == UP)
		move_player(map, 0, -1);
	if (key == A || key == LEFT)
		move_player(map, -1, 0);
	if (key == S || key == DOWN)
		move_player(map, 0, 1);
	if (key == D || key == RIGHT)
		move_player(map, 1, 0);
	return (0);
}
