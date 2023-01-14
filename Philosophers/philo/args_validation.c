/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:41:01 by adashyan          #+#    #+#             */
/*   Updated: 2023/01/14 18:01:00 by tumolabs         ###   ########.fr       */
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
