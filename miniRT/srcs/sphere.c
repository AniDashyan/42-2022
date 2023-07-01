/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:45:42 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 13:22:46 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	solve_quadratic(const t_vect point, double *x0, double *x1)
{
	double	discr;
	double	q;

	discr = point.y * point.y - 4 * point.x * point.z;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * point.y / point.x;
		*x1 = -0.5 * point.y / point.x;
	}
	else
	{
		if (point.y > 0)
			q = -0.5 * (point.y + sqrt(discr));
		else
			q = -0.5 * (point.y - sqrt(discr));
		*x0 = q / point.x;
		*x1 = point.z / q;
	}
	if (*x0 > *x1)
		ft_swap(x0, x1);
	return (1);
}

int	intersect_sphere(const t_ray ray, const t_sphere sphere, t_impact *impact)
{
	double	x0;
	double	x1;
	t_vect	vect;

	vect = new_vect(ray.pos.x - sphere.pos.x, ray.pos.y - sphere.pos.y,
			ray.pos.z - sphere.pos.z);
	if (!solve_quadratic(new_vect(dot_product(ray.dir, ray.dir),
				2 * dot_product(ray.dir, vect),
				dot_product(vect, vect) - sphere.radius2), &x0, &x1))
		return (0);
	if ((x0 < 0 && x1 < 0) || (x0 > impact->dist && x1 > impact->dist))
		return (0);
	else if (x0 <= 0.)
		x0 = x1;
	else if (x1 <= 0.)
		x1 = x0;
	impact->dist = ft_min_float(x0, x1);
	impact->pos = add_vect(ray.pos, multi_vect(ray.dir, x1));
	impact->normal = normalize(sub_vect(impact->pos, sphere.pos));
	impact->pos = add_vect(impact->pos, multi_vect(impact->normal, EPSILON));
	return (1);
}

void	ray_spheres(const t_ray ray, const t_scene *scene, \
	t_impact *impact, void **object)
{
	t_list		*spheres;
	t_sphere	*sphere;

	spheres = scene->spheres;
	while (spheres->next)
	{
		sphere = (t_sphere *)(spheres->content);
		if (intersect_sphere(ray, *sphere, impact))
		{
			*object = sphere;
			ft_memcpy(impact->type, "sp", 2);
		}
		spheres = spheres->next;
	}
}
