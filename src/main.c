/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:25:57 by lclerc            #+#    #+#             */
/*   Updated: 2023/06/06 13:22:11 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_init(t_map *map)
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
	map->mlx = NULL;
	map->mlx_win = NULL;
	map->img_x = 0;
	map->img_y = 0;
	map->has_won = 0;
	map->counting_moves = 0;
}

static void	check_file_type(char **argv)
{
	char	*path;
	char	*type;
	size_t	length;

	type = NULL;
	path = NULL;
	path = argv[1];
	if (*path != '\0')
	{
		length = ft_strlen(path);
		type = ft_substr(path, length - 4, 4);
		if (ft_strncmp(".ber", type, 4) == 0)
		{
			free(type);
			return ;
		}
	}
	free(type);
	ft_printf("Error\nUSE_BER_FILE\n");
	exit(USE_BER_FILE);
}

static void	initialize_game(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->map_width * 60, map->map_height
			* 60, "So_long");
	get_images_and_print_map(map);
	ft_printf("The owls are not what they seem!\n");
	start_game(map);
	mlx_loop(map->mlx);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Error\nUSE_BER_FILE\n");
		exit(USE_BER_FILE);
	}
	check_file_type(argv);
	map_init(&map);
	build_and_validate_map(&map, argv);
	initialize_game(&map);
	free_2d_array(&map, FLOOD_FILL_MAP);
	free_2d_array(&map, MAP);
	return (0);
}
