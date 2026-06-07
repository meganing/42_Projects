/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 00:12:25 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/07 06:43:56 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangular(char **map, int rows, int cols)
{
	int	r;

	r = 0;
	while (r < rows)
	{
		if ((int)ft_strlen(map[r]) != cols)
			return (0);
		r++;
	}
	return (1);
}

int	count_elements(t_game *game, int *p, int *e, int *c)
{
	int	r;
	int	col;

	*p = 0;
	*e = 0;
	*c = 0;
	r = 0;
	while (r < game->rows)
	{
		col = 0;
		while (game->map[r][col])
		{
			if (game->map[r][col] == 'P')
				(*p)++;
			else if (game->map[r][col] == 'E')
				(*e)++;
			else if (game->map[r][col] == 'C')
				(*c)++;
			else if (game->map[r][col] != '0' && game->map[r][col] != '1')
				return (0);
			col++;
		}
		r++;
	}
	return (1);
}

static int	find_player(t_game *game)
{
	int	r;
	int	col;

	r = 0;
	while (r < game->rows)
	{
		col = 0;
		while (game->map[r][col])
		{
			if (game->map[r][col] == 'P')
			{
				game->player_row = r;
				game->player_col = col;
				return (1);
			}
			col++;
		}
		r++;
	}
	return (0);
}

int	validate_map(t_game *game)
{
	int	p;
	int	e;
	int	c;

	game->cols = ft_strlen(game->map[0]);
	if (game->cols == 0)
		return (0);
	if (!check_rectangular(game->map, game->rows, game->cols))
		return (0);
	if (!check_walls(game->map, game->rows, game->cols))
		return (0);
	if (!count_elements(game, &p, &e, &c))
		return (0);
	if (p != 1 || e != 1 || c < 1)
		return (0);
	game->total_collect = c;
	if (!find_player(game))
		return (0);
	if (!check_path(game))
		return (0);
	game->map[game->player_row][game->player_col] = '0';
	return (1);
}
