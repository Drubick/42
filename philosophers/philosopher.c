/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:14:54 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/19 14:05:17 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>	// gettimeofday()
#include <stdio.h>		// printf()
#include <unistd.h>		// usleep()
#include "philosophers.h"

static void	asign_forks(int id, pthread_mutex_t	*philo_forks[2]);
static void	philo_eat(int id, pthread_mutex_t *philo_forks[2]);
static void	philo_sleep(int id, pthread_mutex_t *philo_forks[2]);

void	*philosopher_routine(void *param)
{
	const int			id = *(int*)param;
	pthread_mutex_t		*philo_forks[2];

	g_time_last_meal[id] = get_current_timestamp();
	if (g_info.philo_size == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(g_info.time_to_die * 1000);
		return (NULL);
	}
	asign_forks(id, philo_forks);
	while (true)
	{
		philo_eat(id, philo_forks);
		philo_sleep(id, philo_forks);
		print_status_message(id + 1, thinking);
		if (g_end)
			return (NULL);
	}
	return (NULL);
}

static void	asign_forks(int id, pthread_mutex_t	*philo_forks[2])
{
	if (id == 0)
	{
		philo_forks[0] = &g_forks[g_info.philo_size - 1];
		philo_forks[1] = &g_forks[0];
	}
	else if (id == g_info.philo_size - 1)
	{
		philo_forks[0] = &g_forks[id - 1];
		philo_forks[1] = &g_forks[id];
	}
	else
	{
		philo_forks[0] = &g_forks[id - 1];
		philo_forks[1] = &g_forks[id];
	}
}

static void	philo_eat(int id, pthread_mutex_t *philo_forks[2])
{
	pthread_mutex_lock(philo_forks[0]);
	print_status_message(id + 1, fork_taken);
	pthread_mutex_lock(philo_forks[1]);
	print_status_message(id + 1, fork_taken);
	g_time_last_meal[id] = get_current_timestamp();
	print_status_message(id + 1, eating);
	safe_sleep(g_info.time_to_eat);
	g_meals[id]++;
}

static void	philo_sleep(int id, pthread_mutex_t *philo_forks[2])
{
	print_status_message(id + 1, sleeping);
	pthread_mutex_unlock(philo_forks[0]);
	pthread_mutex_unlock(philo_forks[1]);
	safe_sleep(g_info.time_to_sleep);
}
