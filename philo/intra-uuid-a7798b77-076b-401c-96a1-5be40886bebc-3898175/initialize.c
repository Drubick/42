/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:02:35 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/25 16:17:14 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sum;

	sum = 0;
	i = -1;
	while (str[++i])
		sum = (sum * 10) + (str[i] - 48);
	return (sum);
}

int	is_nbr(char **argv, int i, int j)
{
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_arg(int argc, char **argv, t_p *philos)
{
	if ((argc == 5 || argc == 6) && is_nbr(argv, 0, 1))
	{
		philos->arg.total_philosophers = ft_atoi(argv[1]);
		philos->arg.die = ft_atoi(argv[2]);
		philos->arg.eat = ft_atoi(argv[3]);
		philos->arg.sleep = ft_atoi(argv[4]);
		philos->arg.amount_eatn = -1;
		if (argc == 6)
			philos->arg.amount_eatn = ft_atoi(argv[5]);
		if (philos->arg.total_philosophers <= 0 || philos->arg.die <= 0
			||philos->arg.eat <= 0 || philos->arg.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_mutex(t_p *philo)
{
	pthread_mutex_init(&philo->arg.write_mutex, NULL);
	pthread_mutex_init(&philo->arg.dead, NULL);
	pthread_mutex_init(&philo->arg.time_eat, NULL);
	pthread_mutex_init(&philo->arg.finish, NULL);
}

int	initialize(t_p *philos)
{
	int	i;

	i = 0;
	philos->arg.start_time = get_time();
	philos->arg.stop = 0;
	philos->arg.nb_philo_finish = 0;
	init_mutex(philos);
	while (i < philos->arg.total_philosophers)
	{
		philos->philo[i].id = i + 1;
		philos->philo[i].ms_eat = philos->arg.start_time;
		philos->philo[i].nb_eat = 0;
		philos->philo[i].finish = 0;
		philos->philo[i].right_fork = NULL;
		pthread_mutex_init(&philos->philo[i].left_fork, NULL);
		if (philos->arg.total_philosophers == 1)
			return (1);
		if (i == philos->arg.total_philosophers - 1)
			philos->philo[i].right_fork = &philos->philo[0].left_fork;
		else
			philos->philo[i].right_fork = &philos->philo[i + 1].left_fork;
		i++;
	}
	return (1);
}
