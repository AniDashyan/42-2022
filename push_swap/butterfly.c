/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:44:52 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:44:53 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	max;

	while (*b)
	{
		size = ft_lstsize(*b);
		max = place_in_stack(b, largest_element(*b));
		if (max <= (size - 1) / 2)
		{
			max = largest_element(*b);
			while ((*b)->data != max)
				rb(b);
		}
		else
		{
			max = largest_element(*b);
			while ((*b)->data != max)
				rrb(b);
		}
		pa(b, a);
	}
}

int	generate_n(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 15;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}

void	a_to_b(t_stack **a, t_stack **b, int n)
{
	int	counter;

	counter = 0;
	while (*a)
	{
		if ((*a)->pos <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
		}
		else if ((*a)->pos <= counter + n)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
}

void	butterfly(t_stack **a, t_stack **b)
{
	int	size;
	int	n;

	size = ft_lstsize(*a);
	n = generate_n(size);
	a_to_b(a, b, generate_n(size));
	b_to_a(a, b);
}
