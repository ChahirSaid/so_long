/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:24:26 by schahir           #+#    #+#             */
/*   Updated: 2025/03/24 18:37:58 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static char	**create_copy(t_map *map)
{
	char **copy;
	int i;

	copy = ft_calloc(map->height, sizeof(char *));
	if (!copy)
		exit_free(map, "Memory allocation failed");
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			exit_free(map, "Memory allocation failed");
		}
		i++;
	}
	return (copy);
}

static void flood_fill(char **copy, int x, int y, int *c, int *e)
{
	if(copy[y][x] == '1' || copy[y][x] == 'M')
		return ;
	if(copy[y][x] == 'C')
		(*c)--;
	else if (copy[y][x] == 'E')
		*e = 1;
	copy[y][x] = '1';
	flood_fill(copy, x + 1, y, c, e);
	flood_fill(copy, x - 1, y, c, e);
	flood_fill(copy, x, y + 1, c, e);
	flood_fill(copy, x, y - 1, c, e);
}

void	check_path(t_map *map)
{
	char	**copy;
	int		collectibles;
	int		exit_found;
	int		i;
	
	copy = create_copy(map);
	collectibles = map->collectibles;
	exit_found = 0;
	flood_fill(copy, map->player_x, map->player_y, &collectibles, &exit_found);
	i = 0;
	while (i < map->height)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
	if (collectibles > 0 || !exit_found) 
		exit_free(map, "Invalid Path");
}
