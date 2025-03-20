#include "includes/so_long.h"

void exit_error()
{
	ft_putstr_fd("Error: Openning File\n",2);
	exit(1);
}
int map_len(char *map)
{
    int len = 0;
    int fd = open(map, O_RDONLY);
	
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

void check_map(char *map)
{
    int fd = open(map, O_RDONLY);
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
			ft_printf("error");
            exit(1);
        }
        free(line);
		line = get_next_line(fd);
    }
    close(fd);
}
void print_map(char *map)
{
    int fd = open(map, O_RDONLY);
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
int valid_name(char *av)
{
    int len = 0;
    int i;

    if (!av || ft_strncmp(av, "maps/", 5) != 0)
        return 0;
    i = 5;
    if(!av[i])
        return 0;
    while (av[i])
    {
        if (av[i] == '/')
            return 0;
        if (av[i] == '.')
            len = i;
        i++;
    }
    if (len <= 5 || ft_strcmp(&av[len], ".ber") != 0)
        return 0;
    return 1;
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
	print_map(av[1]);
}