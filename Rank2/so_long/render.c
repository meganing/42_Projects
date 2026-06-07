/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:12:44 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/07 10:13:08 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collect || !game->img_exit)
		return (0);
	return (1);
}

static void	*pick_tile(t_game *game, int r, int c)
{
	if (game->map[r][c] == '1')
		return (game->img_wall);
	if (game->map[r][c] == 'C')
		return (game->img_collect);
	if (game->map[r][c] == 'E')
		return (game->img_exit);
	return (NULL);
}

static void	draw_cell(t_game *game, int r, int c)
{
	void	*img;
	int		x;
	int		y;

	x = c * TILE;
	y = r * TILE;
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x, y);
	img = pick_tile(game, r, c);
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x, y);
	if (r == game->player_row && c == game->player_col)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x, y);
}

void	render_map(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (r < game->rows)
	{
		c = 0;
		while (c < game->cols)
		{
			draw_cell(game, r, c);
			c++;
		}
		r++;
	}
}
