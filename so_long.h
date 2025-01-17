/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:16:38 by lclerc            #+#    #+#             */
/*   Updated: 2023/06/06 09:17:55 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>


# define FAILURE 0
# define SUCCESS 1
# define FOUND 1
# define MALLOC_FAIL 2
# define NOT_RECTANGULAR 3
# define WALL_IS_BREACHED 4
# define ONE_PLAYER_ONLY 5
# define ONE_EXIT_ONLY 6
# define NEED_COLLECTIBLES 7
# define ILLEGAL_CHARACTER 8
# define USE_BER_FILE 9
# define FLOOD_FILL_FAILED 10
# define USER_QUIT 11

# define KEEP_STRING 42
# define DELETE_STRING 21

# define FLOOD_FILL_MAP 84
# define MAP 48

//# define KEY_ESC 53
//# define KEY_W 13
//# define KEY_A 0
//# define KEY_S 1
//# define KEY_D 2

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define A_WALL '1'
# define A_COLLECTIBLE 'C'
# define COLLECTIBLE 'C'
# define THE_EXIT 'E'
# define EXIT 'E'
# define START_POSITION 'P'
# define THE_FLOOR '0'
# define FLOOR '0'

# define HORIZONTALLY 0
# define VERTICALLY 1
# define MOVE 'M'
# define MOVE_AND_PICK 'P'

# define NOT_YET 0
# define MLX_NEED_THAT_INT 42

typedef struct t_map
{
	size_t	map_width;
	size_t	map_height;
	size_t	player_x;
	size_t	player_y;
	size_t	target_x;
	size_t	target_y;
	size_t	collectibles;
	size_t	empty;
	size_t	player;
	size_t	exit;
	size_t	walls;
	size_t	amount_characters;
	size_t	flood_collectibles;
	size_t	flood_exit;
	size_t	flood_valid;

	size_t	img_x;
	size_t	img_y;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*img_player_path;
	char	*img_wall_path;
	char	*img_empty_path;
	char	*img_collectible_path;
	char	*img_exit_path;
	void	*img_player;
	void	*img_wall;
	void	*img_empty;
	void	*img_collectible;
	void	*img_exit;

	int		exit_code;
	int		has_won;
	int		counting_moves;

	char	*map_as_string;
	char	**map;
	char	**flood_map;
}			t_map;

/**
 * Content of map_build.c
 */
int			build_and_validate_map(t_map *map, char **argv);

/**
 * Content of error_exit.c
 */
void		print_error(t_map *map, int exit_code);
void		free_2d_array(t_map *map, int array_to_free);

/**
 * Content map_validation.c
 */
void		validate_map(t_map *map);
size_t		count_characters(t_map *map, char c);

/**
 * Content map_validation_2.c
 */
void		check_valid_path(size_t x, size_t y, t_map *map);

/**
 * Content of game_init.c
 */
void		get_images_and_print_map(t_map *map);

/**
 * Content of gaming movement.c
 */
void		start_game(t_map *map);

/**
 * Content of gaming_movement_2.c
 */
void		action(int keycode, t_map *map, char action);

#endif
