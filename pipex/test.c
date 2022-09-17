/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:05:35 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/17 14:39:23 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int idata = 111;

int	main()
{
	int istack = 222;
	pid_t parent;

	parent = fork();
	if (parent == -1)
		perror ("fork has failed");
	if (!parent) /* On creation of successful child */
	{
		idata *= 3;
		istack *= 2;
	}
	else /* Parent process */
		sleep(3);
	ft_printf("PID=%d %s idata=%d istack=%d\n", (long) getpid(),
	(parent == 0) ? "(child) " : "(parent)", idata, istack);
	return (0);
}
