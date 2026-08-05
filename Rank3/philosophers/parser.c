/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:30:02 by tthwe             #+#    #+#             */
/*   Updated: 2026/07/24 22:04:30 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_all_digits(const char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(const char *s)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		if (n > INT_MAX)
			return (-1);
		i++;
	}
	return (n);
}

int	parse(t_table *table, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		return (error("usage: number_of_philosophers time_to_die "
				"time_to_eat time_to_sleep"));
	}
	if (!is_all_digits(argv[1]) || !is_all_digits(argv[2])
		|| !is_all_digits(argv[3]) || !is_all_digits(argv[4]))
		return (error("arguments must be positive numbers"));
	table->n_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat = -1;
	if (argc == 6)
	{
		if (!is_all_digits(argv[5]))
			return (error("meal count must be a positive number"));
		table->must_eat = ft_atoi(argv[5]);
	}
	if (table->n_philo < 1 || table->time_to_die < 1 || table->time_to_eat < 1
		|| table->time_to_sleep < 1 || table->must_eat == 0)
		return (error("arguments out of range"));
	return (0);
}
