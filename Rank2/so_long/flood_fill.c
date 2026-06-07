/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:12:36 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/07 06:44:17 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int rows)
{
	char	**copy;
	int		r;

	copy = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	r = 0;
	while (r < rows)
	{
		copy[r] = ft_strdup(map[r]);
		if (!copy[r])
		{
			while (r > 0)
				free(copy[--r]);
			free(copy);
			return (NULL);
		}
		r++;
	}
	copy[rows] = NULL;
	return (copy);
}

int	check_walls(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(char **map, int row, int col, t_game *game)
{
	if (row < 0 || row >= game->rows || col < 0 || col >= game->cols)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'V')
		return ;
	map[row][col] = 'V';
	flood_fill(map, row - 1, col, game);
	flood_fill(map, row + 1, col, game);
	flood_fill(map, row, col - 1, game);
	flood_fill(map, row, col + 1, game);
}

int	check_path(t_game *game)
{
	char	**copy;
	int		r;
	int		c;

	copy = copy_map(game->map, game->rows);
	if (!copy)
		return (0);
	flood_fill(copy, game->player_row, game->player_col, game);
	r = 0;
	while (r < game->rows)
	{
		c = 0;
		while (c < game->cols)
		{
			if (copy[r][c] == 'C' || copy[r][c] == 'E')
				return (free_map(copy, game->rows), 0);
			c++;
		}
		r++;
	}
	free_map(copy, game->rows);
	return (1);
}
