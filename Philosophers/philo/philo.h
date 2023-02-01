/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:46:50 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/01 14:45:37 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

/* typedef struct s_data
{
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philo_must_eat;
}	t_data; */

typedef struct s_philo
{
	pthread_t			id;
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philo_must_eat;
	int					philo_id;
	int					eat_count;
	long long			last_eat;
	long long			start_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	// t_data				data;
}	t_philo;

void	error(char *msg);
int		check_arg(char **argv, int argc);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	print_philo(t_philo *philo, int argc);
void	init_data(t_philo *philo, char **argv, int argc, int *i);
void	init_philo(t_philo *philo, pthread_mutex_t *forks,
			char **argv, int argc);
void	*routine(t_philo *philo);
long	get_time(void);
void 	ft_usleep(int useconds);
void	init_fork(t_philo *philo, pthread_mutex_t *forks);

#endif