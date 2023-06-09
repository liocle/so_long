/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:23:43 by lclerc            #+#    #+#             */
/*   Updated: 2023/06/06 08:25:33 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	close_window(t_map *map)
{
	free_2d_array(map, FLOOD_FILL_MAP);
	free_2d_array(map, MAP);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
}

static void	determine_target_position(int keycode, t_map *map)
{
	if (keycode == KEY_W || keycode == KEY_S)
	{
		if (keycode == KEY_S)
			map->target_y = map->player_y + 1;
		else if (keycode == KEY_W)
			map->target_y = map->player_y - 1;
		map->target_x = map->player_x;
	}
	if (keycode == KEY_A || keycode == KEY_D)
	{
		if (keycode == KEY_A)
			map->target_x = map->player_x - 1;
		else if (keycode == KEY_D)
			map->target_x = map->player_x + 1;
		map->target_y = map->player_y;
	}
}

static char	moving_to(t_map *map)
{
	return (map->map[map->target_y][map->target_x]);
}

static int	check_target_position(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_window(map);
	if (map->has_won == NOT_YET)
	{
		determine_target_position(keycode, map);
		if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S || \
			keycode == KEY_W)
		{
			if (moving_to(map) == START_POSITION)
				map->map[map->target_y][map->target_x] = '0';
			if (moving_to(map) == THE_FLOOR)
				action(keycode, map, MOVE);
			if (moving_to(map) == A_COLLECTIBLE)
				action(keycode, map, MOVE_AND_PICK);
			if (moving_to(map) == THE_EXIT)
				action(keycode, map, EXIT);
		}
	}
	return (1);
}

void	start_game(t_map *map)
{
	mlx_key_hook(map->mlx_win, check_target_position, map);
	mlx_hook(map->mlx_win, 17, 0L, close_window, map);
}
