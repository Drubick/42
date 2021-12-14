/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:21:56 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/25 16:21:56 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg
{
	int					total_philosophers;
	int					die;
	int					eat;
	int					sleep;
	int					amount_eatn;
	long int			start_time;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		dead;
	pthread_mutex_t		time_eat;
	pthread_mutex_t		finish;
	int					nb_philo_finish;
	int					stop;
}						t_arg;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	pthread_t			thread_death_id;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		left_fork;
	t_arg				*pa;
	long int			ms_eat;
	unsigned int		nb_eat;
	int					finish;
}						t_philo;

typedef struct s_p
{
	t_philo				*philo;
	t_arg				arg;
}						t_p;

int				check_arg(int argc, char **argv, t_p *philos);
int				initialize(t_p *philos);
int				ft_exit(char *str);
void			write_status(char *str, t_philo *ph);
long int		get_time(void);
void			ft_putstr_fd(char *s, int fd);
void			ft_usleep(long int time_in_ms);
int				threading(t_p *philos);
void			routine(t_philo *ph);
int				check_death(t_philo *ph, int i);
int				ft_strlen(char *str);

#endif
