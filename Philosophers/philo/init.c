/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:46:04 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/27 16:35:48 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	print(p, LEFT, WHITE);
	pthread_mutex_lock(p->right_fork);
	print(p, RIGHT, WHITE);
	print(p, EAT, ORANGE);
	ft_usleep((long)p->data->time_to_eat);
	pthread_mutex_lock(&p->data->l_eat_lock);
	p->last_eat = get_time();
	pthread_mutex_unlock(&p->data->l_eat_lock);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void	*philo(void *arg)
{
	t_philo	*p;

	p = arg;
	if (p->index % 2 != 0)
		usleep(15000);
	while (1)
	{
		eating(p);
		if (p->last != -1)
			p->last--;
		if (p->last == 0)
			break ;
		print(p, SLEEP, BLUE);
		ft_usleep((long)p->data->time_to_sleep);
		print(p, THINK, GREEN);
	}
	return (0);
}

int	init(t_main *main, int argc, char **argv)
{
	main->data.num_philo = ft_atoi(argv[1]);
	if (main->data.num_philo > 0)
	{
		main->p = (t_philo *)malloc(sizeof(t_philo) * main->data.num_philo);
		main->forks = (t_mutex *)malloc(sizeof(t_mutex)
				* main->data.num_philo);
	}
	if (!main->p || !main->forks)
	{
		error(ERR_MALLOC);
		return (1);
	}
	init_mutexes(main);
	main->data.time_to_die = ft_atoi(argv[2]);
	main->data.time_to_eat = ft_atoi(argv[3]);
	main->data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		main->data.num_must_eat = ft_atoi(argv[5]);
	else
		main->data.num_must_eat = -1;
	return (0);
}

void	create_thread(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->data.num_philo)
	{
		main->p[i].data = &main->data;
		pthread_mutex_lock(&main->p->data->l_eat_lock);
		main->p[i].last_eat = get_time();
		pthread_mutex_unlock(&main->p->data->l_eat_lock);
		main->p[i].index = i + 1;
		main->p[i].last = main->data.num_must_eat;
		main->p[i].right_fork = &main->forks[i];
		main->p[i].left_fork = &main->forks[i - 1];
		main->p[0].left_fork = &main->forks[main->data.num_philo - 1];
	}
	main->p->data->start_time = get_time();
	main->p->data->cur_time = main->p->data->start_time;
	i = -1;
	while (++i < main->data.num_philo)
	{
		pthread_create(&main->p[i].pid, NULL, &philo, &main->p[i]);
	}
}
