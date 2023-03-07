/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:45:54 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/27 16:28:20 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if ((argc == 5 || argc == 6) && check_arg(argv, argc))
	{
		if (init(&main, argc, argv) == 1)
			return (1);
		create_thread(&main);
		while (1)
		{
			if (death_cond(&main) == 1)
				return (1);
		}
	}
	else
		error(ERR_ARG);
	return (0);
}
