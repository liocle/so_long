
#include "../so_long.h"
#include <fcntl.h>
#include <unistd.h>

static void build_map(t_map *map, int flag)
{
	if (flag == KEEP_STRING)
	{
		map->map = ft_split(map->map_as_string, '\n');
		if (!map->map)
			print_error(map, MALLOC_FAIL);
	}
	else 
	{
		map->flood_map = ft_split(map->map_as_string, '\n');
		if (!map->flood_map)
			print_error(map, MALLOC_FAIL);
		//free (map->map_as_string);
	}
	if (flag == DELETE_STRING)
		free (map->map_as_string);
}

static int	map_as_string(t_map *map, char **argv)
{
	int fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = "";
	while (line) 
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (map->map_as_string == NULL)
			map->map_as_string = ft_strdup(line);
		else
		{
			char *temp = ft_strdup(map->map_as_string);
			free(map->map_as_string);
			map->map_as_string = ft_strjoin(temp, line);
			free (temp);
			if (map->map_as_string == NULL)
				print_error(map, MALLOC_FAIL);
		}
		free(line);
	}
	close(fd);
	return (SUCCESS);
}



int	build_and_validate_map(t_map *map, char **argv)
{
	map_as_string(map, argv);
	build_map(map, KEEP_STRING);
	build_map(map, DELETE_STRING);
	validate_map(map);
	ft_printf("build and validated\n");
	return (SUCCESS);
}

