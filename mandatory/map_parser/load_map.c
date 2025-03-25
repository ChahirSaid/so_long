/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:19:11 by schahir           #+#    #+#             */
/*   Updated: 2025/03/24 16:36:55 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_map	*check_map(char *map_path)
{
	t_map	*map;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error("Opening file");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_error("Memory allocation failed");
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0)
		exit_free(map, "Empty map");
	map->grid = ft_calloc(map->height, sizeof(char *));
	if (!map->grid)
		exit_free(map, "Memmory allocation failed");
	return (map);
}

t_map	*read_map(char *map_path)
{
	t_map	*map;
	int		fd;
	int		i;
	char	*line;

	map = check_map(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_free(map, "Opening file");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->grid[i] = line;
		if (i == 0)
			map->width = ft_strlen(line);
		i++;
		line = get_next_line(fd);
	}
	return (map);
}
