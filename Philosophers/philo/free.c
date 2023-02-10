/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:53:19 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/10 16:01:45 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(philo);
	free(forks);
	printf("I'm free!!!\n");
}
