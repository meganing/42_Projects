/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 07:48:10 by tthwe             #+#    #+#             */
/*   Updated: 2026/07/24 21:26:57 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_table
{
	int				n_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	long			start_time;
	int				stopped;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	stop_lock;
	struct s_philo	*philos;
}	t_table;

typedef struct s_philo
{
	pthread_t		thread;
	t_table			*table;
	int				philo_id;
	long			num_meals;
	long			last_meal;
	pthread_mutex_t	*leftfork;
	pthread_mutex_t	*rightfork;
}					t_philo;

int		error(const char *s);
long	ft_atoi(const char *s);
int		parse(t_table *table, int argc, char **argv);
long	get_time(void);
void	ft_usleep(long ms);

#endif
