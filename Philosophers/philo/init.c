/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:22 by adashyan          #+#    #+#             */
/*   Updated: 2023/01/30 21:25:33 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_philo *philo, char **argv, int argc)
{
	philo->number_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philo_must_eat = ft_atoi(argv[5]);
}

void	*routine(t_philo *philo)
{
	(void)philo;
	printf("Hello from the thread\n");
	return (NULL);
}

void	init_philo(t_philo *philo, pthread_mutex_t *forks, char **argv, int argc)
{
	int				i;
	struct timeval 	tv;

	i = 1;
	gettimeofday(&tv, NULL);
	init_data(philo, argv, argc);
	while (i < philo->number_of_philos)
	{
		philo[i].philo_id = i;
		philo[i].last_eat = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		philo[i].right_fork = &forks[i]; 
		philo[i + 1].left_fork = &forks[i];
		philo[0].left_fork = &forks[philo->number_of_philos - 1];
		pthread_create(&philo[i].id, NULL, (void *)routine, &philo[i]);
		i++;
	}
	printf("left fork: %p\n", philo[1].left_fork);
	printf("right fork: %p\n", philo[i].right_fork);
}

void	print_philo(t_philo *philo, int argc)
{
	printf("number_of_philos-> %d\n", philo->number_of_philos);
	printf("time_to_die-> %d\n", philo->time_to_die);
	printf("time_to_eat-> %d\n", philo->time_to_eat);
	printf("time_to_sleep-> %d\n", philo->time_to_sleep);
	if (argc == 6)
		printf("number_of_times_each_philo_must_eat-> %d\n",
			philo->number_of_times_each_philo_must_eat);
}
