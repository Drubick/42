#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "philosophers.h"

int ft_unsigned_atoi(const char *str)
{
	int		i;
	int		number;

	i = 0;
	number = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number == 0)
			number = str[i] - 48;
		else
			number = number * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '\0')
		return (number);
	else
		return (-1);
}

t_bool reading_parameters(const int argc, const char **argv)
{
	if (argc < 5 || argc > 6)
		printf("Invalid number of arguments");
		return(false);
	g_info.philo_nbr = ft_unsigned_atoi(argv[1]);
	g_info.time_to_die = ft_unsigned_atoi(argv[2]);
	g_info.time_to_eat = ft_unsigned_atoi(argv[3]);
	g_info.time_to_sleep = ft_unsigned_atoi(argv[4]);
	if (argc == 6)
		g_info.min_eating_times = ft_unsigned_atoi(argv[5]);
	else
		g_info.min_eating_times = -1;
	if (g_info.philo_nbr == -1 || g_info.time_to_die == -1
		|| g_info.time_to_eat == -1 || g_info.time_to_sleep == -1
		|| (argc == 6 && g_info.min_eating_times == -1))
		return(false);
	return(true);
}

t_bool initialize_variables(int *ids, pthread_t **philosophers_threads)
{
	int	i;

	i = 0;
	g_end = false;
	
	*philosophers_threads =(pthread_t *)malloc(sizeof(pthread_t) * g_info.philo_nbr);
	g_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * g_info.philo_nbr);
	*ids = (int *) malloc(sizeof(int) * g_info.philo_nbr);
	g_time_last_meal = get_time();
	g_meals = (int *) malloc(sizeof(int) * g_info.philo_nbr);
	if(!*philosophers_threads || !g_forks || !g_time_last_meal || !g_meals)
		return(false);
	memset(g_meals, 0, sizeof(int) * g_info.philo_nbr);
	if(pthreads_mutex_init(&g_print_mutex, NULL))
		return(false);
	while(i < g_info.philo_nbr)
	{
		g_time_last_meal[i] = get_time();
		if (pthread_mutex_init(&g_forks[i++], NULL))
			return (false);
	}
	g_info.starting_time = get_time();
	return(true);
}

t_bool	create_philosophers(int *ids, pthread_t *philosophers_treads)
{
	int	i;

	i = 0;
	while(i < g_info.philo_nbr)
	{
		ids[i] = 1;
		//LA FUNCION pthead crea un thread con una rutin auqe le pasas llamada routine
		if (pthread_create(&philosophers_treads[i], NULL, routine, &ids[i]))
			return(false);
		usleep(1000);
		i++;
	}
	return (true);
}

int	main(const int argc, const char **argv)
{
	int			ids;
	pthread_t	philosophers_threads;

	if(reading_parameters(argc, *argv))
		return(0);
	if (initialize_variables(&ids, &philosophers_threads)
		&& g_info.min_eating_times != 0 && g_info.philo_nbr > 0
		&& create_philosophers(ids, philosophers_threads))
		manage_philosophers_lifes();
	return (0);
}