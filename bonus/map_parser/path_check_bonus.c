/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:24:26 by schahir           #+#    #+#             */
/*   Updated: 2025/03/25 02:06:25 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static char	**create_copy(t_map *map)
{
	char	**copy;
	int		i;

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

static void	flood_fill(char **copy, int x, int y)
{
	if (copy[y][x] == '1' || copy[y][x] == 'B')
		return ;
	copy[y][x] = '1';
	flood_fill(copy, x + 1, y);
	flood_fill(copy, x - 1, y);
	flood_fill(copy, x, y + 1);
	flood_fill(copy, x, y - 1);
}

static int	has_element(char **copy, t_map *map)
{
	int	i;
	int	j;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (copy[i][j] != '0' || copy[i][j] != '1' || copy[i][j] != 'B')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_path(t_map *map)
{
	char	**copy;
	int		i;
	int		valid;

	copy = create_copy(map);
	flood_fill(copy, map->player_x, map->player_y);
	valid = has_element(copy, map);
	i = 0;
	while (i < map->height)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
	if (valid)
		exit_free(map, "Invalid Path");
}
