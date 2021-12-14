/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:02:42 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/25 16:08:25 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
/*
Writes the status of the filosofers
*/
void	write_status(char *str, t_philo *philo)
{
	long int	time;

	time = -1;
	time = get_time() - philo->pa->start_time;
	if (time > 0 && time < 2147483647 && !check_death(philo, 0))
	{
		printf("%ld", time);
		printf("Philo %d %s", philo->id, str);
	}
}
/*
Writes and manages when sleeping and when thinkin
*/

void	sleeping_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->pa->write_mutex);
	ft_usleep(philo->pa->sleep);
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("is thinking\n", philo);
	pthread_mutex_unlock(&philo->pa->write_mutex);
}
/*
Taake the fork display whhen taking and when eating
unlock the mutexes then he sleeps and thinks
*/

void	routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->pa->write_mutex);
	if (!philo->right_fork)
	{
		ft_usleep(philo->pa->die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->pa->write_mutex);
	pthread_mutex_lock(&philo->pa->write_mutex);
	write_status("is eating\n", philo);
	pthread_mutex_lock(&philo->pa->time_eat);
	philo->ms_eat = get_time();
	pthread_mutex_unlock(&philo->pa->time_eat);
	pthread_mutex_unlock(&philo->pa->write_mutex);
	ft_usleep(philo->pa->eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	sleeping_thinking(philo);
}
