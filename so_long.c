/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:19:28 by schahir           #+#    #+#             */
/*   Updated: 2025/03/21 21:40:19 by schahir          ###   ########.fr       */
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

void free_map(t_map *map)
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
	free(map);
}

static int	valid_name(char *map_path)
{
	int i;
	int len;
	
	if(!map_path || ft_strncmp(map_path, "maps/", 5) != 0)
	return (0);
	len = ft_strlen(map_path);
	if (len <= 9)
		return (0);
	i = 4;
	while (map_path[i])
	{
		if(map_path[i] == '/' && map_path[i + 1] == '/')
			return (0);
		i++;
	}
	return (1);
}

void print_map(t_map *map)
{
    int i = 0;
    
	ft_printf("Height: %d\nWidth : %d\nGrid :\n", map->height, map->width);
	while(i < map->height)
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	t_map *map;

	if (ac != 2)
		exit_error("Invalid Arguments [./so_long maps/filename.ber]");
	if(!valid_name(av[1]))
		exit_error("Invalid Map Name Or Path");
	map = read_map(av[1]);
	check_rectangular(map);
	check_borders(map);
	elements_count(map);
	check_path(map);
	print_map(map);
	free_map(map);
}
