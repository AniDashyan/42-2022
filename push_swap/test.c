/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:39:12 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/27 17:54:10 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int	number1;
	int	number2;
	int	sum;
	int	input_fds;

	input_fds = open("a.txt", O_RDONLY);
	if (dup2(input_fds, STDIN_FILENO) < 0)
	{
		printf("Unable to duplicate file descriptor.");
		exit(EXIT_FAILURE);
	}
	scanf("%d %d", &number1, &number2);
	sum = number1 + number2;
	printf("%d + %d = %d\n", number1, number2, sum);
	return (EXIT_SUCCESS);
}
