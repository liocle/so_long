#include "../so_long.h"
#include <stddef.h>

static	void	check_walls(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[0][j] != '1')
				print_error(map, WALL_IS_BREACHED);
			if (map->map[map->map_height - 1][j] != '1')
				print_error(map, WALL_IS_BREACHED);
			if (map->map[i][0] != '1')
				print_error(map, WALL_IS_BREACHED);
			if (map->map[i][map->map_width - 1] != '1')
				print_error(map, WALL_IS_BREACHED);
			j++;
		}
		i++;
	}
}

static int	count_characters(t_map *map, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == c && c == 'P')
			{
				map->player_x = j;
				map->player_y = i;
			}
			if (map->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return(count);
}

static void	check_rectangularity(t_map *map)
{
	size_t	length;
	char	**rectangle;

	rectangle = map->map;
	map->map_width = ft_strlen(*rectangle);
	if (map->map_width != 0)
		map->map_height = 1;
	rectangle++;
	while (*rectangle)
	{
		length = ft_strlen(*rectangle);
		if (length != map->map_width)
			print_error(map, NOT_RECTANGULAR);
		rectangle++;
		map->map_height++;
	}
	map->amount_characters = map->map_width * map->map_height;
}

void	validate_map(t_map *map)
{
	
	check_rectangularity(map);
	check_walls(map);
	map->walls = count_characters(map, '1');
	map->collectibles = count_characters(map, 'C');
	map->empty = count_characters(map, '0');
	map->player = count_characters(map, 'P');
	map->exit = count_characters(map, 'E');
	if (map->player != 1)
		print_error(map, ONE_PLAYER_ONLY ); 
	if (map->exit != 1)
		print_error(map, ONE_EXIT_ONLY);
	if (map->collectibles < 1)
		print_error(map, NEED_COLLECTIBLES);
	if (map->collectibles + map->exit + map->player + map->walls + map->empty != map->amount_characters)
		print_error(map, ILLEGAL_CHARACTER);
	check_valid_path(map->player_y, map->player_x, map);
	if (map->flood_valid == FAILURE)
		print_error(map, FLOOD_FILL_FAILED);
}
