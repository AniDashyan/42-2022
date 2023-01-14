/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:22 by adashyan          #+#    #+#             */
/*   Updated: 2023/01/14 18:00:49 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_args(t_philo *philo, char **argv, int argc)
{
	philo->number_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philo_must_eat = ft_atoi(argv[5]);
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
