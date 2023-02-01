/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:39:50 by tumolabs          #+#    #+#             */
/*   Updated: 2023/02/01 16:08:11 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, long time)
{
	pthread_mutex_lock(philo->left_fork);
	printf("[%ld]: philo %d has taken the left fork🍴\n", get_time() - time, philo->philo_id);
	pthread_mutex_lock(philo->right_fork);
	printf("[%ld]: philo %d has taken the right fork🍴\n", get_time() - time, philo->philo_id);
	philo->last_eat = get_time();
	philo->eat_count += 1;
	printf("[%ld]: philo %d is eating🍝\n", get_time() - time, philo->philo_id);
	ft_usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	printf("[%ld]: philo %d is sleeping😴\n", get_time() - time, philo->philo_id);
	ft_usleep(philo->time_to_sleep * 1000);
	printf("[%ld]: philo %d is thinking🤔\n", get_time() - time, philo->philo_id);
}

int	check_death(t_philo *philo)
{
	if (philo->last_eat - philo->start_time >= philo->time_to_die)
		printf("philo %d is dead😵\n");
	return ;
}

void	*routine(t_philo *philo)
{
	long	time;

	time = get_time();
	if (philo->philo_id % 2 == 0)
		ft_usleep(100);
	while (1)
	{
		eat(philo, time);
	}
	return (NULL);
}
