/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:02:55 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/29 15:00:07 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	thr_in(t_thread thread[], t_window *window, t_couple res)
{
	int	i;
	int	j;

	i = 1;
	while (i < N_THREADS)
	{
		j = 1;
		while (j <= sqrt(N_THREADS))
		{
			thread[i + j - 2].window = window;
			thread[i + j - 2].resolution.w = res.w;
			thread[i + j - 2].resolution.h = res.h;
			if (j == 1)
				thread[i + j - 2].start.w = 0;
			else
				thread[i + j - 2].start.w = thread[i + j - 3].start.w + res.w;
			if (i == 1)
				thread[i + j - 2].start.h = 0;
			else
				thread[i + j - 2].start.h = ((int)(i / sqrt(N_THREADS)))
					* res.h;
			j++;
		}
		i += sqrt(N_THREADS);
	}
}

void	thread_init(t_thread thread[], t_window *window)
{
	t_couple	new_res;

	if (N_THREADS != (int)sqrt(N_THREADS) * (int)sqrt(N_THREADS))
		print_err_and_exit("Incorrect `N_THREADS' value", THREAD_ERROR);
	new_res.w = window->scene->resolution.w / sqrt(N_THREADS);
	new_res.h = window->scene->resolution.h / sqrt(N_THREADS);
	thr_in(thread, window, new_res);
}

void	make_img(t_window *w)
{
	t_thread	thread[N_THREADS];
	int			i;

	i = -1;
	thread_init(thread, w);
	while (++i < N_THREADS)
		if (pthread_create(&thread[i].thread, 0, &routine, (void *)&thread[i]))
			print_err_and_exit("Thread create failed", THREAD_ERROR);
	i = -1;
	while (++i < N_THREADS)
		pthread_join(thread[i].thread, 0);
}
