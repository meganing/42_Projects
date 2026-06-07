/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:13:06 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/07 09:21:35 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(int moves)
{
	char	*number;

	number = ft_itoa(moves);
	if (!number)
		return ;
	ft_putstr_fd("Moves: ", 1);
	ft_putstr_fd(number, 1);
	ft_putstr_fd("\n", 1);
	free(number);
}

void	move_player(t_game *game, int x_move, int y_move)
{
	int		new_r;
	int		new_c;
	char	next;

	new_r = game->player_row + y_move;
	new_c = game->player_col + x_move;
	next = game->map[new_r][new_c];
	if (next == '1')
		return ;
	if (next == 'C')
	{
		game->collected++;
		game->map[new_r][new_c] = '0';
	}
	game->player_row = new_r;
	game->player_col = new_c;
	game->moves++;
	print_moves(game->moves);
	render_map(game);
	if (next == 'E' && game->collected == game->total_collect)
	{
		ft_putendl_fd("You win!", 1);
		close_game(game);
	}
}
