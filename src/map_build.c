/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:27:12 by lclerc            #+#    #+#             */
/*   Updated: 2023/06/06 13:39:35 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	build_map(t_map *map, int flag)
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
	}
	if (flag == DELETE_STRING)
	{
		free(map->map_as_string);
		map->map_as_string = NULL;
	}
}

static void	get_string(t_map *map, char *temp, char *line)
{
	temp = ft_strdup(map->map_as_string);
	free(map->map_as_string);
	map->map_as_string = ft_strjoin(temp, line);
	free(temp);
	if (map->map_as_string == NULL)
		print_error(map, MALLOC_FAIL);
}

static void	map_as_string(t_map *map, char **argv)
{
	int		fd;
	char	*line;
	char	*temp;

	temp = NULL;
	fd = open(argv[1], O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (map->map_as_string == NULL)
		{
			map->map_as_string = ft_strdup(line);
			if (!map->map_as_string)
				print_error(map, MALLOC_FAIL);
		}
		else
			get_string(map, temp, line);
		free(line);
	}
	close(fd);
}

int	build_and_validate_map(t_map *map, char **argv)
{
	map_as_string(map, argv);
	build_map(map, KEEP_STRING);
	build_map(map, DELETE_STRING);
	validate_map(map);
	return (SUCCESS);
}
