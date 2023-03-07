/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:27:59 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/27 16:33:15 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *p)
{
	pthread_mutex_lock(&p->data->death_lock);
	if (get_time() - p->last_eat >= p->data->time_to_die)
	{
		print(p, DEATH, RED);
		pthread_mutex_unlock(&p->data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&p->data->death_lock);
	if (p->last == 0)
		return (2);
	return (0);
}

int	death_cond(t_main *main)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < main->data.num_philo)
	{
		if (check_death(&main->p[i]) == 2)
			count++;
		if (check_death(&main->p[i]) == 1)
			return (1);
		if (count == main->data.num_philo)
			return (1);
		i++;
	}
	return (0);
}
