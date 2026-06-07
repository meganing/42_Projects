/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:13:14 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/06 02:30:00 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_map(char **map, int rows)
{
	int	r;

	if (!map)
		return ;
	r = 0;
	while (r < rows)
	{
		if (map[r])
			free(map[r]);
		r++;
	}
	free(map);
}
