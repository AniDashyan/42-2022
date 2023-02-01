/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:22 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/01 14:49:06 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_philo *philo, char **argv, int argc, int *i)
{
	philo[*i].number_of_philos = ft_atoi(argv[1]);
	philo[*i].time_to_die = ft_atoi(argv[2]);
	philo[*i].time_to_eat = ft_atoi(argv[3]);
	philo[*i].time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo[*i].number_of_times_each_philo_must_eat = ft_atoi(argv[5]);
}

void	init_philo(t_philo *philo, pthread_mutex_t *forks,
	char **argv, int argc)
{
	int				i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		init_data(philo, argv, argc, &i);
		philo[i].philo_id = i + 1;
		philo[i].eat_count = 0;
		philo[i].right_fork = &forks[i];
		philo[i].left_fork = &(forks[(i + 1) % philo[i].number_of_philos]);
		philo[i].start_time = get_time();
		pthread_create(&philo[i].id, NULL, (void *)routine, &philo[i]);
		pthread_detach(philo[i].id);
	}
}

void	init_fork(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			error("Error: Can't create mutex");
		i++;
	}
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
