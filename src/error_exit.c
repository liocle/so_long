/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:17:26 by lclerc            #+#    #+#             */
/*   Updated: 2023/06/06 08:17:37 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_2d_array(t_map *map, int array_to_free)
{
	int	i;

	i = 0;
	if (array_to_free == FLOOD_FILL_MAP)
	{
		if (map->flood_map != NULL)
		{
			while (map->flood_map[i])
				free(map->flood_map[i++]);
			free(map->flood_map);
			map->flood_map = NULL;
		}
	}
	else if (map->map != NULL)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
		map->map = NULL;
	}
}

static void	free_map_as_string(t_map *map)
{
	if (map->map_as_string != NULL)
		free(map->map_as_string);
	map->map_as_string = NULL;
}

static int	exit_gracefully(int exit_code)
{
	if (exit_code == MALLOC_FAIL)
		exit(MALLOC_FAIL);
	else if (exit_code == NOT_RECTANGULAR)
		exit(NOT_RECTANGULAR);
	else if (exit_code == WALL_IS_BREACHED)
		exit(WALL_IS_BREACHED);
	else if (exit_code == ONE_PLAYER_ONLY)
		exit(ONE_PLAYER_ONLY);
	else if (exit_code == ONE_EXIT_ONLY)
		exit(ONE_EXIT_ONLY);
	else if (exit_code == NEED_COLLECTIBLES)
		exit(NEED_COLLECTIBLES);
	else if (exit_code == ILLEGAL_CHARACTER)
		exit(ILLEGAL_CHARACTER);
	else if (exit_code == USE_BER_FILE)
		exit(USE_BER_FILE);
	else if (exit_code == FLOOD_FILL_FAILED)
		exit(FLOOD_FILL_FAILED);
	return (SUCCESS);
}

void	print_error(t_map *map, int exit_code)
{
	free_2d_array(map, MAP);
	if (exit_code >= 2)
		ft_printf("Error\n");
	if (exit_code == MALLOC_FAIL)
	{
		free_map_as_string(map);
		ft_printf("MALLOC_FAIL\n");
	}
	else if (exit_code == NOT_RECTANGULAR)
		ft_printf("NOT_RECTANGULAR\n");
	else if (exit_code == WALL_IS_BREACHED)
		ft_printf("WALL_IS_BREACHED\n");
	else if (exit_code == ONE_PLAYER_ONLY)
		ft_printf("ONE_PLAYER_ONLY\n");
	else if (exit_code == ONE_EXIT_ONLY)
		ft_printf("ONE_EXIT_ONLY\n");
	else if (exit_code == NEED_COLLECTIBLES)
		ft_printf("NEED_COLLECTIBLES\n");
	else if (exit_code == ILLEGAL_CHARACTER)
		ft_printf("ILLEGAL_CHARACTER\n");
	else if (exit_code == FLOOD_FILL_FAILED)
		ft_printf("FLOOD_FILL_FAILED\n");
	exit_gracefully(exit_code);
}
