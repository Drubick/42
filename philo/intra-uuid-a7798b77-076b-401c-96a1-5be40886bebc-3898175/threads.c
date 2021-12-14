/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:02:45 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/25 16:17:25 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
/*
checks the times status of a philosofer and kills it if needed
*/
void	*is_dead(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	ft_usleep(philo->pa->die + 1);
	pthread_mutex_lock(&philo->pa->time_eat);
	pthread_mutex_lock(&philo->pa->finish);
	if (!check_death(philo, 0) && !philo->finish
		&& ((get_time() - philo->ms_eat) >= (long)(philo->pa->die)))
	{
		pthread_mutex_unlock(&philo->pa->time_eat);
		pthread_mutex_unlock(&philo->pa->finish);
		pthread_mutex_lock(&philo->pa->write_mutex);
		write_status("died\n", philo);
		pthread_mutex_unlock(&philo->pa->write_mutex);
		check_death(philo, 1);
	}
	pthread_mutex_unlock(&philo->pa->time_eat);
	pthread_mutex_unlock(&philo->pa->finish);
	return (NULL);
}

/*
Manage philosophers dead and routines
and if the philosopphers have finished eating
*/
void	*threads(void *data)
{
	t_philo					*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->eat / 10);
	while (!check_death(ph, 0))
	{
		pthread_create(&ph->thread_death_id, NULL, is_dead, data);
		routine(ph);
		pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_eat == ph->pa->amount_eatn)
		{
			pthread_mutex_lock(&ph->pa->finish);
			ph->finish = 1;
			ph->pa->nb_philo_finish++;
			if (ph->pa->nb_philo_finish == ph->pa->total_philosophers)
			{
				pthread_mutex_unlock(&ph->pa->finish);
				check_death(ph, 2);
			}
			pthread_mutex_unlock(&ph->pa->finish);
			return (NULL);
		}
	}
	return (NULL);
}

/*
We create a thread for each philosofer to manage theyr lives and deaths
*/
int	threading(t_p *philos)
{
	int	i;

	i = 0;
	while (i < philos->arg.total_philosophers)
	{
		philos->philo[i].pa = &philos->arg;
		if (pthread_create(&philos->philo[i].thread_id, NULL, threads,
				&philos->philo[i]) != 0)
			return (ft_exit("Pthread did not return 0\n"));
		i++;
	}
	return (1);
}
