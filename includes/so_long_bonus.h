/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:09:02 by schahir           #+#    #+#             */
/*   Updated: 2025/03/24 17:09:36 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
#include "/usr/include/minilibx-linux/mlx.h"

#include <fcntl.h>

# define PIXEL_SIZE 48

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364 
# define RIGHT 65363

typedef struct s_graphics
{
    void    *mlx;
    void    *win;
    void    *img_wall;
    void    *img_floor;
    void    *img_collectible;
    void    *img_player;
    void    *img_exit;
    void    *img_on_exit;
}   t_graphics;

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     collectibles;
    int     exit;
    int     exit_x;
    int     exit_y;
    int     player;
    int     player_x;
    int     player_y;
    
    t_graphics graphics;
}   t_map;

/*---------------Graphics---------------*/
int     handle_input(int key, t_map *map);
void	render_textures(t_map *map, int on_exit);
void	load_textures(t_map *map);

/*--------------Map-Parsing--------------*/
void	check_path(t_map *map);
void	elements_count(t_map *map);
void	check_borders(t_map *map);
void	check_rectangular(t_map *map);
t_map	*read_map(char *map_path);

/*-------------Error-Handling-------------*/
void	exit_free(t_map *map, char *message);
void	free_map(t_map *map);
int     exit_success(t_map *map);
void	exit_error(char *message);

#endif