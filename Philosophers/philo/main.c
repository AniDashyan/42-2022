/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:48:18 by adashyan          #+#    #+#             */
/*   Updated: 2023/01/14 17:59:14 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;

	if ((argc == 5 || argc == 6) && check_arg(argv, argc) == 1)
	{
		i = 1;
		philo = malloc(sizeof(t_philo));
		if (!philo)
			error("Error: Can't allocate memory!\n");
		fill_args(philo, argv, argc);
		print_philo(philo, argc);
	}
	else
		error("Not enough arguments!\n");
	return (0);
}
