/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:02:48 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/25 16:10:39 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
/*
Checks with the i variable if, if its true the philo is dead so we should stop
and change the death parameter,
*/

int	check_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->pa->dead);
	if (i)
		philo->pa->stop = i;
	if (philo->pa->stop)
	{
		pthread_mutex_unlock(&philo->pa->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->pa->dead);
	return (0);
}

/*
gets actual time in MS
*/
long int	get_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

/*
sleeps a thread for x ms
*/
void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
