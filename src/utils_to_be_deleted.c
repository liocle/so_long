#include "../so_long.h"
#include <sys/wait.h>

void print_map(t_map *map)
{
	char **str = map->map;
	char **flood = map->flood_map;

	ft_printf("\n____regular map____\n");
	while (*str)
	{
		ft_printf("%s\n", *str);
		str++;
	}
	ft_printf("\n_____flood map____\n");
	while (*flood)
	{
		ft_printf("%s\n", *flood);
		flood++;
	}
}
