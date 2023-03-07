/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:45:35 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/27 16:36:00 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long ms)
{
	long	start;

	start = get_time();
	while (get_time() < (start + ms))
		usleep(200);
}

void	print(t_philo *p, char *str, char *col)
{
	pthread_mutex_lock(&p->data->print_lock);
	printf("%s%d philo %d %s\033[0m\n",
		col, (int)(get_time() - p->data->start_time), p->index, str);
	pthread_mutex_unlock(&p->data->print_lock);
}
