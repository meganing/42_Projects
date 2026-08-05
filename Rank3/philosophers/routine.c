/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:50:25 by tthwe             #+#    #+#             */
/*   Updated: 2026/07/24 22:58:05 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("philosopher %d is at the table\n", philo->philo_id);
	return (NULL);
}

void	*create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				routine, &table->philos[i]) != 0)
			return (error("thread creation failed"));
		i++;
	}
	while (i >= 0)
	{
		pthread_join(table->philos[i].thread, NULL);
		i--;
	}
	return (1);
}

