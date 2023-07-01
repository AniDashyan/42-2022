/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:48:53 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 13:22:26 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	intersect_plane(const t_ray ray, const t_plane plane, t_impact *impact)
{
	double	denom;
	double	x;

	denom = dot_product(plane.normal, ray.dir);
	if (fabs(denom) > 0)
	{
		x = dot_product(sub_vect(plane.pos, ray.pos), plane.normal) / denom;
		if (x > EPSILON && x < impact->dist)
		{
			impact->normal = normalize(plane.normal);
			impact->pos = add_vect(ray.pos, multi_vect(ray.dir, x));
			impact->pos = add_vect(impact->pos,
					multi_vect(impact->normal, EPSILON));
			impact->dist = x;
			return (1);
		}
	}
	return (0);
}

void	ray_planes(const t_ray ray, const t_scene *scene,
	t_impact *impact, void **object)
{
	t_list		*planes;
	t_plane		*plane;

	planes = scene->planes;
	while (planes->next)
	{
		plane = (t_plane *)(planes->content);
		if (intersect_plane(ray, *plane, impact))
		{
			*object = plane;
			ft_memcpy(impact->type, "pl", 2);
		}
		planes = planes->next;
	}
}
