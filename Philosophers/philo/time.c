/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:46:43 by tumolabs          #+#    #+#             */
/*   Updated: 2023/02/01 13:27:54 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
	return (time);
}

void ft_usleep(int useconds) 
{
    struct timespec req = {0};
    
    req.tv_sec = (time_t)(useconds / 1000000);
    req.tv_nsec = (long)(useconds % 1000000) * 1000;
    nanosleep(&req, (struct timespec *)NULL);
}