/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:44:29 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:44:30 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_pos(t_stack *a)
{
	int	max;
	int	index;

	max = a->data;
	index = a->pos;
	while (a)
	{
		if (a->data > max)
		{
			max = a->data;
			index = a->pos;
		}
		a = a->next;
	}
	return (index);
}

int	largest_element(t_stack *head)
{
	int	max;

	max = INT_MIN;
	while (head != NULL)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);
}

int	min_pos(t_stack *a)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = a->data;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			index = i;
		}
		i++;
		a = a->next;
	}
	return (index);
}
