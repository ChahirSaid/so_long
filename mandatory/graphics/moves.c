/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:52:47 by schahir           #+#    #+#             */
/*   Updated: 2025/03/24 18:29:28 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void print_moves(t_map *map, char c)
{
	static int count;
	if (c == 'W' && map->grid[map->player_y - 1][map->player_x] != '1')
		ft_printf("moves: %d\n", ++count);
	if (c == 'A' && map->grid[map->player_y][map->player_x - 1] != '1')
		ft_printf("moves: %d\n", ++count);
	if (c == 'S' && map->grid[map->player_y + 1][map->player_x] != '1')
		ft_printf("moves: %d\n", ++count);
	if (c == 'D' && map->grid[map->player_y][map->player_x + 1] != '1')
		ft_printf("moves: %d\n", ++count);
}

static void	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;
	int on_exit;

	new_x = map->player_x + x;
	new_y = map->player_y + y;
	
	on_exit = 0;
	if (map->grid[new_y][new_x] == '1')
		return ;
	if (map->grid[new_y][new_x] == 'C')
		map->collectibles--;
	if(map->grid[new_y][new_x] == 'E')
	{
		if(map->collectibles == 0)
		{
			ft_putstr_fd("Game over\n", 1);
			free_map(map);
			exit (0);
		}
		on_exit = 1;
		map->exit_x = new_x;
		map->exit_y = new_y;	
	}
	if (map->player_y == map->exit_y && map->player_x == map->exit_x)
		map->grid[map->player_y][map->player_x] = 'E';
	else
		map->grid[map->player_y][map->player_x] = '0';
	map->grid[new_y][new_x] = 'P';
	map->player_x = new_x;
	map->player_y = new_y;
	render_textures(map, on_exit);
}

int	handle_input(int key, t_map *map)
{
	if (key == ESC)
		exit_success(map);
	if (key == W || key == UP)
	{
		print_moves(map, 'W');
		move_player(map, 0, -1);
	}
	if (key == A || key == LEFT)
	{
		print_moves(map, 'A');
		move_player(map, -1, 0);
	}
	if (key == S || key == DOWN)
	{
		print_moves(map, 'S');
		move_player(map, 0, 1);
	}
	if (key == D || key == RIGHT)
	{
		print_moves(map, 'D');
		move_player(map, 1, 0);
	}
	return (0);
}

