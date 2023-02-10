/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:47:41 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/10 20:47:51 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, long *tm)
{
	if (pthread_mutex_lock(philo->left_fork) != 0)
		error("Error: locking left fork mutex\n");
	printf("[%ld]: philo %d has taken the left fork🍴\n",
		get_time() - *tm, philo->index);
	if (pthread_mutex_lock(philo->right_fork) != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		error("Error locking right fork mutex\n");
	}
	printf("[%ld]: philo %d has taken the right fork🍴\n",
		get_time() - *tm, philo->index);
	printf("[%ld]: philo %d is eating🍝\n", get_time() - *tm, philo->index);
	philo->last_eat = get_time();
	usleep(philo->time_to_eat * 1000);
	if (pthread_mutex_unlock(philo->left_fork) != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		error("Error unlocking left fork mutex\n");
	}
	printf("[%ld]: philo %d has dropped the left fork🍴\n",
		get_time() - *tm, philo->index);
	if (pthread_mutex_unlock(philo->right_fork) != 0)
		error("Error unlocking right fork mutex\n");
	printf("[%ld]: philo %d has dropped the right fork🍴\n",
		get_time() - *tm, philo->index);
	printf("[%ld]: philo %d is sleeping😴\n",
		get_time() - *tm, philo->index);
	usleep(philo->time_to_sleep * 1000);
	printf("[%ld]: philo %d is thinking\n", get_time() - *tm, philo->index);
}

int	check_death(t_philo *philo)
{
	long	time;

	time = get_time();
	if (time - philo->last_eat >= philo->time_to_die)
	{
		printf("[%ld]: philo %d is dead😵\n",
			time - philo->last_eat, philo->index);
		return (1);
	}
	return (0);
}

void	*routine(t_philo *philo)
{
	long	time;

	time = get_time();
	if (philo->index % 2 == 0)
		usleep(philo->time_to_eat * 1000);
	while (1)
	{
		eat(philo, &time);
	}
	return (NULL);
}
