/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:09:17 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/07 09:49:01 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE 32

// keycodes per OS
# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_LEFT 123
#  define KEY_DOWN 125
#  define KEY_RIGHT 124
#  define KEY_Q 12
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_LEFT 65361
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363
#  define KEY_Q 113
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
	int		player_row;
	int		player_col;
	int		total_collect;
	int		collected;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_game;

// parsing
char	**read_map(char *filepath, int *rows);
void	check_extension(char *filepath, char *extension);

// validating
int		validate_map(t_game *game);
int		check_walls(char **map, int rows, int cols);
int		count_elements(t_game *game, int *p, int *e, int *c);

//checking if solvable
char	**copy_map(char **map, int rows);
void	flood_fill(char **map, int row, int col, t_game *game);
int		check_path(t_game *game);

// rendering
int		load_textures(t_game *game);
void	render_map(t_game *game);

// game loop
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		close_game(t_game *game);

//clean/error
void	cleanup_game(t_game *game);
void	error_exit(char *msg);
void	free_map(char **map, int rows);

#endif
