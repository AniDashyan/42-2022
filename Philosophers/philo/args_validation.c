/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:48:27 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/27 16:48:35 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{	
			if (ft_atoi(argv[i]) <= 0)
				return (0);
			if (argv[i][j] < '0' && argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	init_mutexes(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->data.num_philo)
	{
		pthread_mutex_init(&main->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&main->data.print_lock, NULL);
	pthread_mutex_init(&main->data.l_eat_lock, NULL);
	pthread_mutex_init(&main->data.death_lock, NULL);
	return (0);
}
