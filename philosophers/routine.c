#include "philosophers.h"

void *routine(void *param)
{
	const int			id = *(int*)param;
	pthread_mutex_t 	philo_forks[2];

	g_time_last_meal = get_time();
	if (g_info.philo_nbr == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(1000);
		return(NULL);
	}
	fork_assignation(id, philo_forks);
	while(1)
	{
		philo_eat
	}

}


void	fork_assignation(const int id, pthread_mutex_t *philo_forks)
{
	if (id == 0)
	{
		philo_forks[0] = &g_forks[g_info.philo_nbr - 1];
		philo_forks[1] = &g_forks[0];
	}
	else if (id == g_info.philo_nbr - 1)
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