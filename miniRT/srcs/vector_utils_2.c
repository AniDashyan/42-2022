/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:47:38 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 20:47:58 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	sign(double a)
{
	if (a < EPSILON && a > -EPSILON)
		return (1);
	return (fabs(a) / a);
}

t_vect	find_b(t_vect orient)
{
	if (orient.x < EPSILON && orient.x > -EPSILON)
	{
		if (orient.z < EPSILON && orient.z > -EPSILON)
			return (new_vect(1, 0, 0));
		return (new_vect(sign(orient.z), 0, 0));
	}
	else if (orient.z < EPSILON && orient.z > -EPSILON)
		return (new_vect(0, 0, -sign(orient.x)));
	return (new_vect(-sign(orient.z) * orient.z / orient.x, 0, sign(orient.z)));
}
