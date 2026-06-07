/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:11:52 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/07 06:44:33 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game, char *path)
{
	ft_bzero(game, sizeof(*game));
	game->map = read_map(path, &game->rows);
	if (!game->map || game->rows == 0)
	{
		cleanup_game(game);
		error_exit("Error\nInvalid map file\n");
	}
	if (!validate_map(game))
	{
		cleanup_game(game);
		error_exit("Error\nInvalid map\n");
	}
}

static void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		cleanup_game(game);
		error_exit("Error\nFailed to initialize MiniLibX\n");
	}
	game->win = mlx_new_window(game->mlx, game->cols * TILE,
			game->rows * TILE, "so_long");
	if (!game->win)
	{
		cleanup_game(game);
		error_exit("Error\nFailed to open window\n");
	}
	if (!load_textures(game))
	{
		cleanup_game(game);
		error_exit("Error\nFailed to load textures\n");
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Error\nUsage: ./so_long map.ber\n");
	check_extension(argv[1], ".ber");
	init_game(&game, argv[1]);
	init_window(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
