/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:46:22 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/29 13:49:48 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	distance(const t_vect p, const t_vect q)
{
	return (sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2) + pow(q.z - p.z, 2)));
}

t_vect	normalize(const t_vect vect)
{
	double	length;

	length = distance(new_vect(0, 0, 0), vect);
	return (new_vect(vect.x / length, vect.y / length, vect.z / length));
}

t_vect	str_to_vect(const char *str)
{
	char	**tab;
	t_vect	vect;

	tab = ft_split(str, ',');
	if (!tab || !tab[0] || !tab[1] || !tab[2])
		print_err_and_exit("Bad arguments. Can't convert to vector\n",
			VECTOR_ERROR);
	vect = set_vect(tab[0], tab[1], tab[2]);
	clear_matrix(tab);
	return (vect);
}

t_vect	mult_mat(const double mat[3][3], const t_vect vect)
{
	double	x;
	double	y;
	double	z;
	t_vect	res;

	x = mat[0][0] * vect.x + mat[0][1] * vect.y + mat[0][2] * vect.z;
	y = mat[1][0] * vect.x + mat[1][1] * vect.y + mat[1][2] * vect.z;
	z = mat[2][0] * vect.x + mat[2][1] * vect.y + mat[2][2] * vect.z;
	res = new_vect(x, y, z);
	return (res);
}

t_vect	cross_product(const t_vect v1, const t_vect v2)
{
	t_vect	origin;
	t_vect	normal;
	double	denom;
	double	cross;

	origin = new_vect(0, 0, 0);
	denom = distance(origin, v1) * distance(origin, v2);
	cross = denom * sinf(acos(dot_product(v1, v2) / denom));
	normal = new_vect(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, \
		v1.x * v2.y - v1.y * v2.x);
	return (multi_vect(normal, cross));
}
