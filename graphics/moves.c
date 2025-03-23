/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:52:47 by schahir           #+#    #+#             */
/*   Updated: 2025/03/23 21:41:37 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_input(int key, t_map *map)
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
}

static void	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;
	int	on_exit;

	new_x = map->player_x + x;
	new_y = map->player_y + y;
	on_exit = 0;
	
	if (map->player_x == map->exit_x && map->player_y == map->exit_y)
		on_exit = 1;
	if (map->grid[new_x][new_y] == '1')
		return ;
	if (map->grid[new_x][new_y] == 'C')
		map->collectibles--;
	if(map->grid[new_x][new_y] == 'E')
	{
		if(map->collectibles == 0)
		{
			ft_putstr_fd("YOU WIN\n", 1);
			free_map(map);
			exit (0);
		}
		on_exit = 1;
		map->exit_x = new_x;
		map->exit_y = new_y;	
	}
	if (on_exit)
		map->grid[map->player_y][map->player_y] = 'E';
	else
		map->grid[map->player_y][map->player_x] = '0';
	map->grid[new_y][new_x] = 'P';
	map->player_x = new_x;
	map->player_y = new_y;
}
