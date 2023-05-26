#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "mlx/mlx.h"





//########## check libft object files after fclean, it seems ft_atol.o remains there








typedef struct t_map
{
	size_t	map_width;
	size_t	map_height;
	size_t	player_x;
	size_t	player_y;
	size_t	collectibles;
	size_t	empty;
	size_t	player;
	size_t	exit;
	size_t	walls;
	size_t	amount_characters;
	size_t	flood_collectibles;
	size_t	flood_exit;
	size_t  flood_valid;
	int		exit_code;
	char	*map_as_string;
	char	**map;
	char	**flood_map;
}					t_map;


# define FAILURE			0
# define SUCCESS			1
# define FOUND				1
# define MALLOC_FAIL		2
# define NOT_RECTANGULAR	3
# define WALL_IS_BREACHED	4
# define ONE_PLAYER_ONLY	5
# define ONE_EXIT_ONLY		6
# define NEED_COLLECTIBLES	7
# define ILLEGAL_CHARACTER	8
# define USE_BER_FILE		9 
# define FLOOD_FILL_FAILED  10

# define KEEP_STRING		42
# define DELETE_STRING		21

# define FLOOD_FILL_MAP		84
# define MAP				48

/**
 * In map_build.c
 */
int		build_and_validate_map(t_map *map, char **argv);

/**
 * in error_exit.c
 */
void	print_error(t_map *map, int exit_code);
void	free_2d_array(t_map *map, int array_to_free);

/**
 * Content of utils_to_be_deleted.c
 */
void	print_map(t_map  *map);

/**
 * Content map_validation.c
 */
void	validate_map(t_map *map);

/**
 * Content map_validation_2.c
 */
void	check_valid_path(size_t x, size_t y, t_map *map);

#endif
