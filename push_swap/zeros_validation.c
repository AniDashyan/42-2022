/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeros_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:44:22 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:44:23 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_len(int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

void	zeros_validation(char **str, int len)
{
	int	i;
	int	*num;

	i = 0;
	num = malloc(sizeof(int) * len);
	if (!num)
		return ;
	while (i < len)
	{
		if (num_len(ft_atoi(str[i])) > 16)
			print_error();
		i++;
	}
	free(num);
}
