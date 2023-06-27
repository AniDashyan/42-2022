/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:12:03 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 17:12:05 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_min_float(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_max_float(const float a, const float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_swap(void *a, void *b)
{
	void	*c;

	c = a;
	a = b;
	b = c;
}
