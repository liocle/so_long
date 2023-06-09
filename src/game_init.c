/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:21:11 by lclerc            #+#    #+#             */
/*   Updated: 2023/06/06 08:21:12 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_img(t_map *map, char c)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_empty, map->img_x, \
			map->img_y);
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall, \
				map->img_x, map->img_y);
	else if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_collectible, \
				map->img_x, map->img_y);
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_exit, \
				map->img_x, map->img_y);
	else if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_player, \
				map->img_x, map->img_y);
}

static void	print_map(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map->map[i])
	{
		x = 0;
		j = 0;
		while (map->map[i][j])
		{
			map->img_x = x;
			map->img_y = y;
			print_img(map, map->map[i][j]);
			j++;
			x = x + 60;
		}
		i++;
		y = y + 60;
	}
}

void	get_images_and_print_map(t_map *map)
{
	int	width;
	int	height;

	map->img_player_path = "./textures/player.xpm";
	map->img_wall_path = "./textures/wall.xpm";
	map->img_empty_path = "./textures/empty.xpm";
	map->img_collectible_path = "./textures/collectible.xpm";
	map->img_exit_path = "./textures/exit.xpm";
	map->img_player = mlx_xpm_file_to_image(map->mlx, map->img_player_path,
			&width, &height);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, map->img_wall_path, &width,
			&height);
	map->img_empty = mlx_xpm_file_to_image(map->mlx, map->img_empty_path,
			&width, &height);
	map->img_collectible = mlx_xpm_file_to_image(map->mlx, \
		map->img_collectible_path, &width, &height);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, map->img_exit_path, &width,
			&height);
	print_map(map);
}
