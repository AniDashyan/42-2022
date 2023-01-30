/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:48:18 by adashyan          #+#    #+#             */
/*   Updated: 2023/01/30 21:25:12 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	        *philo;
    pthread_mutex_t *forks;

	if ((argc == 5 || argc == 6) && check_arg(argv, argc) == 1)
	{
		// philo->number_of_philos = ft_atoi(argv[1]);
		philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
        forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
		if (!philo || !forks)
			error("Error: Can't allocate memory!\n");
		init_philo(philo, forks, argv, argc);
		// print_philo(philo, argc);
	}
	else
		error("Not enough arguments!\n");
	return (0);
}
