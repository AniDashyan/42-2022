/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:48:18 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/13 18:19:44 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				i;

	if ((argc == 5 || argc == 6) && check_arg(argv, argc) == 1)
	{
		philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
		if (!philo || !forks)
			error("Error: Can't allocate memory!\n");
		init_fork(forks, argv);
		init_philo(philo, forks, argv, argc);
		while (1)
		{
			i = -1;
			while (++i < philo->number_of_philos)
			{
				if (is_dead(&philo[i]) == 1)
					return (1);
			}
		}
	}
	else
		error("Not enough arguments!\n");
	return (0);
}

/* 
typedef	struct s_mut
{
	pthread_mutex_t	*mutex;
	int	*cnt;
}	t_mut;

void *f(void *p)
{
	t_mut *t;
	t = p;

	for (int i = 0; i < 10000; ++i)
	{
		pthread_mutex_lock(t->mutex);
		++*t->cnt;
		pthread_mutex_unlock(t->mutex);
	}
	return (NULL);
}

int main()
{
	int cnt = 0;
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);

	t_mut t;
	t.mutex = &mutex;
	t.cnt = &cnt;

	pthread_create(&thread1, NULL, &f, &t);
	pthread_create(&thread2, NULL, &f, &t);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("*t.cnt: %d\n", *t.cnt);
}
*/