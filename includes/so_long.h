/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:49:54 by schahir           #+#    #+#             */
/*   Updated: 2025/03/21 21:40:48 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

#include <fcntl.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		player;
	int		player_x;
	int		player_y;
}	t_map;

/*--------------Map-Parsing--------------*/
void	check_path(t_map *map);
void	elements_count(t_map *map);
void	check_borders(t_map *map);
void	check_rectangular(t_map *map);
t_map	*read_map(char *map_path);

/*-------------Error-Handling-------------*/
void	exit_free(t_map *map, char *message);
void	free_map(t_map *map);
void	exit_error(char *message);

#endif