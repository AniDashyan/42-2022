/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:43:41 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/28 13:51:10 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	calc(double *dist, double *x, double dist1, double x2)
{
	*dist = dist1;
	*x = x2;
}

static void	calc_cy_normal(double x2[2], const t_cylinder cylinder, \
	double dist1, double dist2)
{
	double	dist;
	double	x;

	if ((dist1 >= 0 && dist1 <= cylinder.height && x2[0] > EPSILON)
		&& (dist2 >= 0 && dist2 <= cylinder.height && x2[1] > EPSILON))
	{
		if (x2[0] < x2[1])
			calc(&dist, &x, dist1, x2[0]);
		else
		{
			dist = dist2;
			x = x2[1];
		}
	}
	else if (dist1 >= 0 && dist1 <= cylinder.height && x2[0] > EPSILON)
		calc(&dist, &x, dist1, x2[0]);
	else
	{
		dist = dist2;
		x = x2[1];
	}
	x2[0] = x;
}

static int	solve_cylinder(double x[2], t_ray ray, const t_cylinder cylinder)
{
	t_vect	v;
	t_vect	u;
	double	a;
	double	b;
	double	c;

	v = multi_vect(cylinder.dir, dot_product(ray.dir, cylinder.dir));
	v = sub_vect(ray.dir, v);
	u = multi_vect(cylinder.dir, dot_product(sub_vect(ray.pos, \
		cylinder.pos), cylinder.dir));
	u = sub_vect(sub_vect(ray.pos, cylinder.pos), u);
	a = dot_product(v, v);
	b = 2 * dot_product(v, u);
	c = dot_product(u, u) - pow(cylinder.radius2, 2);
	x[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (x[0] < EPSILON && x[1] < EPSILON)
		return (0);
	return (1);
}

double	cy_intersection(t_ray ray, const t_cylinder cylinder)
{
	double	x2[2];
	double	dist1;
	double	dist2;

	if (!solve_cylinder(x2, ray, cylinder))
		return (INFINITY);
	dist1 = dot_product(cylinder.dir, sub_vect(multi_vect(ray.dir, x2[0]),
				sub_vect(cylinder.pos, ray.pos)));
	dist2 = dot_product(cylinder.dir, sub_vect(multi_vect(ray.dir, x2[1]),
				sub_vect(cylinder.pos, ray.pos)));
	if (!((dist1 >= 0 && dist1 <= cylinder.height && x2[0] > EPSILON)
			|| (dist2 >= 0 && dist2 <= cylinder.height && x2[0] > EPSILON)))
		return (INFINITY);
	calc_cy_normal(x2, cylinder, dist1, dist2);
	return (x2[0]);
}
