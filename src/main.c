#include "../so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void map_init(t_map *map)
{
	map->map = NULL;
	map->flood_map = NULL;
	map->map_as_string = NULL;
	map->map_height = 0;
	map->map_width = 0;
	map->exit = 0;
	map->player = 0;
	map->empty = 0;
	map->walls = 0;
	map->amount_characters = 0;	
	map->flood_collectibles = 0;
	map->flood_exit = 0;
}

static void check_file_type(char **argv)
{
	char	*path;
	char	*type;
	size_t	length;

	path = argv[1];
	length = ft_strlen(path);
	type = ft_substr(path, length - 4, 4);
	if (ft_strncmp(".ber", type, 4) == 0)
	{
		free (type);
		return;
	}
	free (type);
	ft_printf("USE_BER_FILE\n");
	exit(USE_BER_FILE);
}

int	main(int argc, char **argv)
{
	t_map map;
	
	if (argc != 2)
		return (1);
	check_file_type(argv);
	map_init(&map);
	build_and_validate_map(&map, argv);
	print_map(&map);
	free_2d_array(&map, FLOOD_FILL_MAP);
	free_2d_array(&map, MAP);
	return (0);
}
