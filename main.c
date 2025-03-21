#include "includes/so_long.h"

void exit_error()
{
	ft_putstr_fd("Error: Openning File\n",2);
	exit(1);
}
int map_len(char *map_path)
{
    int len = 0;
    int fd = open(map_path, O_RDONLY);
	
	if (fd == -1)
		exit_error();
    char *line = get_next_line(fd);
    while (line && *line != '\n')
    {
        len++;
        free(line);
        line = get_next_line(fd);
    }
    if (line)
        free(line);
    close(fd);
    return (len);
}

void check_map(char *map_path)
{
    int fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error();
    char *line = get_next_line(fd);
    int line_len = 0;
    int current_len;

    if (line)
    {
        line_len = ft_strlen(line);
        free(line);
    }
	line = get_next_line(fd);
    while (line)
    {
        current_len = ft_strlen(line);
        if (current_len != line_len && *line != '\n')
        {
            free(line);
            close(fd);
			ft_putstr_fd("Error: Map must be rectangular\n", 2);
            exit(1);
        }
        free(line);
		line = get_next_line(fd);
    }
    close(fd);
}
void print_map(char *map_path)
{
    int fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error();
    char *line = get_next_line(fd);

    while (line)
    {
        ft_printf("%s", line);
        free(line);
		line = get_next_line(fd);
    }
    close(fd);
}
int valid_name(char *map_path)
{
    int len = 0;
    int i;

    if (!map_path || ft_strncmp(map_path, "maps/", 5) != 0)
        return 0;
    len = ft_strlen(map_path);
    if (len <= 9)
        return 0;
     if (ft_strcmp(&map_path[len - 4], ".ber") != 0)
         return 0;
    i = 5;
    while (map_path[i])
    {
        if (map_path[i] == '/')
            return 0;
        i++;
    }
    return 1;
}

void check_borders(char *map_path)
{
    char *line;
    int cline = 0;
    int line_len = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    char **map = NULL;
    int fd = open("map_path", O_RDONLY);
    if (fd == -1)
        exit_error();
    cline = map_len(map_path);
    map = malloc(sizeof(char *) * (cline + 1));
    if (!map)
        exit(1);
    line = get_next_line(fd);
    while (line)
    {
        map[i++] = line;
        if(i == 1)
            line_len = ft_strlen(line);
    }
    map[i] = NULL;
    close(fd);
    while (j < line_len - 1)
    {
        if (map[0][j] != '1' || map[cline -1][j] != '1')
        {
            ft_putstr_fd("Error: Map Must Be Surrounded By Walls\n", 2);
            while (k++ < cline)
                free(map[k]);
            free(map);
            exit(1);
        }
        j++;
    }
    j = 0;
    while(j++ < cline)
        free(map[j]);
    free(map);
}

void check_elements(char *map_path)
{
    int fd = open(map_path, O_RDONLY);
    if (fd == -1)
        exit_error();
    
    char *line;
    int player_count = 0;
    int collect_count = 0;
    int exit_count = 0;
    int i;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        i = 0;
        while (line[i])
        {
            if (line[i] == 'P')
                player_count++;
            else if (line[i] == 'C')
                collect_count++;
            else if (line[i] == 'E')
                exit_count++;
            else if (line[i] != '0' && line[i] != '1' && line[i] != '\n')
            {
                free(line);
                close(fd);
                ft_putstr_fd("Error: Invalid character in map\n", 2);
                exit(1);
            }
            i++;
        }
        free(line);
    }
    close(fd);
    if (player_count != 1)
    {
        ft_putstr_fd("Error: Map must have exactly one player (P)\n", 2);
        exit(1);
    }
    if (collect_count < 1)
    {
        ft_putstr_fd("Error: Map must have at least one collectible (C)\n", 2);
        exit(1);
    }
    if (exit_count != 1)
    {
        ft_putstr_fd("Error: Map must have exactly one exit (E)\n", 2);
        exit(1);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
		exit(1);
	if (!valid_name(av[1]))
	{
		ft_putstr_fd("Error: Invalid map\n",2);
		exit(1);
	}
    check_map(av[1]);
    check_borders(av[1]);
    check_elements(av[1]);
    //flood_fill(av[1]);
	print_map(av[1]);
}