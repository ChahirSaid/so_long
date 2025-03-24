/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:19:11 by schahir           #+#    #+#             */
/*   Updated: 2025/03/24 16:36:58 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_rectangular(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->grid[i]);
		if (len != map->width)
			exit_free(map, "Map must be recatngular");
		i++;
	}
}

void	check_borders(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while(j < map->width)
	{
		if (map->grid[0][j] != '1' || map->grid[map->height - 1][j] != '1')
			exit_free(map, "Map must be surrounded by walls");
		j++;
	}
	while (i < map->height)
	{
		if(map->grid[i][0] != '1' || map->grid[i][map->width -1] != '1')
			exit_free(map, "Map must be surrounded by walls");
		i++;
	}
}

static void	populate_element(t_map *map, int i, int j, char element)
{
	if (element == 'P')
	{
		map->player++;
		map->player_x = j;
		map->player_y = i;
	}
	else if (element == 'E')
	{
		map->exit++;
		map->exit_x = j;
		map->exit_y = i;
	}
}

static void	check_elements(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	while(i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
				populate_element(map, i, j, 'P');
			else if (map->grid[i][j] == 'C')
				map->collectibles++;
			else if (map->grid[i][j] == 'E')
				populate_element(map, i, j, 'E');
			else if (map->grid[i][j] != '0' && map->grid[i][j] != '1')
				exit_free(map, "Map can only have (P) (C) (E) (0) (1)");
			j++;
		}
		i++;
	}
}

void	elements_count(t_map *map)
{
	check_elements(map);
	if (map->player != 1)
		exit_free(map, "Map must have exactly one Player (P)");
	if (map->collectibles < 1)
		exit_free(map, "Map Mmust have at least one Collectible (C)");
	if (map->exit != 1)
		exit_free(map, "Map must have exactly one Exit (E)");
}
