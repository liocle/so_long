/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming_movement_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:21:16 by lclerc            #+#    #+#             */
/*   Updated: 2023/06/06 13:21:17 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	we_have_a_winner_lets_exit(t_map *map)
{
	free_2d_array(map, FLOOD_FILL_MAP);
	free_2d_array(map, MAP);
	ft_printf("⛰️ You were %d steps away from the other side🦉\n", map->counting_moves);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
}

static void	count_and_display_moves(t_map *map)
{
	char	*step_number;

	map->counting_moves++;
	mlx_string_put(map->mlx, map->mlx_win, 20, 30, 0x00FFFFFF, "ToTaL STePS: ");
	step_number = ft_itoa(map->counting_moves);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall, 2 * 60, 0);
	mlx_string_put(map->mlx, map->mlx_win, 120, 30, 0x00FFFFFF, step_number);
	ft_printf("🍒 You made %s step! 🍒\n", step_number);
	free(step_number);
}

static void	move(int moving, t_map *map, char action)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_empty, \
			map->player_x * 60, map->player_y * 60);
	if (moving == HORIZONTALLY)
		map->player_x = map->target_x;
	else if (moving == VERTICALLY)
		map->player_y = map->target_y;
	if (action == MOVE_AND_PICK || action == EXIT)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_empty, \
				map->player_x * 60, map->player_y * 60);
		map->map[map->player_y][map->player_x] = FLOOR;
		if (action == MOVE_AND_PICK)
			map->collectibles = count_characters(map, COLLECTIBLE);
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_player, \
			map->player_x * 60, map->player_y * 60);
	count_and_display_moves(map);
}

static void	move_to_exit(int keycode, t_map *map, char action)
{
	if (map->collectibles == 0)
	{
		if (keycode == KEY_A || keycode == KEY_D)
			move(HORIZONTALLY, map, action);
		else if (keycode == KEY_W || keycode == KEY_S)
			move(VERTICALLY, map, action);
		we_have_a_winner_lets_exit(map);
	}
	else
		ft_printf("Hep hep hep, where are you going?\n You collect stuff, \
				then exit!\n");
}

void	action(int keycode, t_map *map, char action)
{
	if (action == EXIT)
		move_to_exit(keycode, map, action);
	else if (keycode == KEY_A || keycode == KEY_D)
		move(HORIZONTALLY, map, action);
	else if (keycode == KEY_W || keycode == KEY_S)
		move(VERTICALLY, map, action);
}
