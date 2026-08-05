/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:15:17 by tthwe             #+#    #+#             */
/*   Updated: 2026/07/24 22:24:32 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (error("allocation failed"));
	parse(table, ac, argv);
	table->philos = malloc(sizeof(t_philo) * table->n_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->philos || !table->forks)
    	return (error("allocation failed"));
}