/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:27:08 by tthwe             #+#    #+#             */
/*   Updated: 2026/07/24 22:46:05 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	table_setup(int ac, char *av[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (error("allocation failed"));
	parse(table, ac, av);
	table->philos = malloc(sizeof(t_philo) * table->n_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->philos || !table->forks)
		return (error("allocation failed"));
}

int	lock_setup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (error("mutex init failed"));
		i++;
	}
	if (pthread_mutex_init(&table->print_lock, NULL))
		return (error("mutex init failed"));
	if (pthread_mutex_init(&table->meal_lock, NULL))
		return (error("mutex init failed"));
	if (pthread_mutex_init(&table->stop_lock, NULL))
		return (error("mutex init failed"));
	return (1);
}

int	philo_setup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		table->philos[i].philo_id = i + 1;
		table->philos[i].num_meals = 0;
		table->philos[i].last_meal = table->start_time;
		table->philos[i].table = table;
		table->philos[i].leftfork = &table->forks[i];
		table->philos[i].rightfork = &table->forks[(i + 1) % table->n_philo];
		i++;
	}
	return (1);
}

