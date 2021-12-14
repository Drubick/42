/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:02:38 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/25 16:02:38 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	check_death2(t_p *philo)
{
	pthread_mutex_lock(&philo->arg.dead);
	if (philo->arg.stop)
	{
		pthread_mutex_unlock(&philo->arg.dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->arg.dead);
	return (0);
}

void leaks()
{
	system("leaks philo");
}

void	stop(t_p *philos)
{
	int	i;

	i = -1;
	while (!check_death2(philos))
		ft_usleep(1);
	while (++i < philos->arg.total_philosophers)
		pthread_join(philos->philo[i].thread_id, NULL);
	pthread_mutex_destroy(&philos->arg.write_mutex);
	i = -1;
	while (++i < philos->arg.total_philosophers)
		pthread_mutex_destroy(&philos->philo[i].left_fork);
	if (philos->arg.stop == 2)
		printf("Each philosopher ate %d time(s)\n", philos->arg.amount_eatn);
	free(philos->philo);
}

int	main(int argc, char **argv)
{
	
	t_p	philo;
	atexit(	);
	if (!(check_arg(argc, argv, &philo)))
		return (ft_exit("Invalid arguments\n"));
	philo.philo = malloc(sizeof(t_philo) * philo.arg.total_philosophers);
	if (!philo.philo)
		return (ft_exit("Unable to allocate memory\n"));
	if (!initialize(&philo) || !threading(&philo))
	{
		free(philo.philo);
		return (0);
	}
	stop(&philo);
}
