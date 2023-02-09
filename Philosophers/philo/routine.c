/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:50 by tumolabs          #+#    #+#             */
/*   Updated: 2023/02/09 20:37:17 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, long *time)
{
	pthread_mutex_lock(philo->left_fork);
	printf("[%ld]: philo %d has taken the left fork🍴\n",
		get_time() - *time, philo->philo_id);
	pthread_mutex_lock(philo->right_fork);
	printf("[%ld]: philo %d has taken the right fork🍴\n",
		get_time() - *time, philo->philo_id);
	printf("[%ld]: philo %d is eating🍝\n", get_time() - *time, philo->philo_id);
	philo->last_eat = get_time();
	philo->eat_count += 1;
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	printf("[%ld]: philo %d is sleeping😴\n",
		get_time() - *time, philo->philo_id);
	usleep(philo->time_to_sleep * 1000);
	printf("[%ld]: philo %d is thinking🤔\n",
		get_time() - *time, philo->philo_id);
}

int	check_death(t_philo *philo)
{
	long	time;

	time = get_time();
	if (time - philo->last_eat >= philo->time_to_die)
	{
		printf("philo %d is dead😵\n", philo->philo_id);
		return (1);
	}
	return (0);
}

void	*routine(t_philo *philo)
{
	long	time;

	time = get_time();
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (1)
	{
		eat(philo, &time);
	}
	return (NULL);
}
