/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:08:47 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 20:48:59 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vect	new_vect(const double x, const double y, const double z)
{
	t_vect	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vect	set_vect(const char *x, const char *y, const char *z)
{
	t_vect	vect;

	vect.x = ft_atof(x);
	vect.y = ft_atof(y);
	vect.z = ft_atof(z);
	return (vect);
}

t_vect	rot_vect(const t_vect vect, const double radian, const char axe)
{
	double	alpha;

	alpha = radian;
	if (axe == 'x')
		return (mult_mat((double [3][3]){{1, 0, 0}, {0, cos(alpha),
				-sin(alpha)}, {0, sin(alpha), cos(alpha)}}, vect));
	else if (axe == 'y')
		return (mult_mat((double [3][3]){{cos(alpha), 0, sin(alpha)}, {0, 1, 0},
			{-sin(alpha), 0, cos(alpha)}}, vect));
	else if (axe == 'z')
		return (mult_mat((double [3][3]){{cos(alpha), -sin(alpha), 0},
			{sin(alpha), cos(alpha), 0}, {0, 0, 1}}, vect));
	return (new_vect(0, 0, 0));
}

t_vect	set_vect_dir_cam(const t_camera camera, const t_couple resolution,
	const int i, const int j)
{
	t_vect	vect_dir;
	double	a;
	double	b;
	double	c;
	int		max;

	a = j + 0.5 - (resolution.w) * 0.5;
	b = i + 0.5 - (resolution.h) * 0.5;
	if (resolution.w > resolution.h)
		max = resolution.w;
	else
		max = resolution.h;
	c = max / (2 * tan((to_rad(camera.fov * 0.5))));
	vect_dir = multi_vect(normalize(camera.orientation), c);
	vect_dir = add_vect(vect_dir, multi_vect(camera.up, b));
	vect_dir = add_vect(vect_dir, multi_vect(camera.b, a));
	return (normalize(vect_dir));
}

t_vect	get_closest_point_from_line(t_vect a, t_vect b, t_vect p)
{
	t_vect	ap;
	t_vect	ab;
	double	ab2;
	double	ap_ab;
	double	t;

	ap = sub_vect(p, a);
	ab = sub_vect(b, a);
	ab2 = dot_product(ab, ab);
	ap_ab = dot_product(ap, ab);
	t = ap_ab / ab2;
	if (t < 0.0)
		t = 0.0;
	else if (t > 1.0)
		t = 1.0;
	return (add_vect(a, multi_vect(ab, t)));
}
