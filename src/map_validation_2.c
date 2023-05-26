#include "../so_long.h"

void check_valid_path(size_t y, size_t x, t_map *map)
{
	if ((map->flood_exit == FOUND) && (map->flood_collectibles == map->collectibles))
		map->flood_valid = SUCCESS;
	if (map->flood_map[y][x] == 'E')
		map->flood_exit = FOUND;
	if ((map->flood_map[y][x] == '0') || (map->flood_map[y][x] == 'C') || (map->flood_map[y][x] == 'P'))
	{
		if (map->flood_map[y][x] == 'C')
			map->flood_collectibles++;
		map->flood_map[y][x] = 'V';
		if (y < (map->map_height - 1))
			check_valid_path(y + 1, x, map);
		if (y > 0)
			check_valid_path(y - 1, x, map);
		if (x < (map->map_width - 1))
			check_valid_path(y, x + 1, map);
		if (x > 0)
			check_valid_path(y, x - 1, map);
	}
}
