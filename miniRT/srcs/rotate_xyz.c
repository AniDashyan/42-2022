/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:35 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/28 12:32:39 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	rot_x(const int keycode, t_window *w)
{
	t_plane		*pl;
	t_cylinder	*cy;

	if (keycode != KEY_X)
		return (0);
	if (!w->type)
		return (0);
	if (!ft_strncmp(w->type, "cy", 3))
	{
		cy = (t_cylinder *)w->object;
		cy->dir = rot_vect(cy->dir, M_PI / 180 * 15, 'x');
	}
	if (!ft_strncmp(w->type, "pl", 3))
	{
		pl = (t_plane *)w->object;
		pl->normal = rot_vect(pl->normal, M_PI / 180 * 15, 'x');
	}
	return (1);
}

int	rot_y(const int keycode, t_window *w)
{
	t_plane		*pl;
	t_cylinder	*cy;

	if (keycode != KEY_Y)
		return (0);
	if (!w->type)
		return (0);
	if (!ft_strncmp(w->type, "cy", 3))
	{
		cy = (t_cylinder *)w->object;
		cy->dir = rot_vect(cy->dir, M_PI / 180 * 15, 'y');
	}
	if (!ft_strncmp(w->type, "pl", 3))
	{
		pl = (t_plane *)w->object;
		pl->normal = rot_vect(pl->normal, M_PI / 180 * 15, 'y');
	}
	return (1);
}

int	rot_z(const int keycode, t_window *w)
{
	t_plane		*pl;
	t_cylinder	*cy;

	if (keycode != KEY_Z)
		return (0);
	if (!w->type)
		return (0);
	if (!ft_strncmp(w->type, "cy", 3))
	{
		cy = (t_cylinder *)w->object;
		cy->dir = rot_vect(cy->dir, M_PI / 180 * 15, 'z');
	}
	if (!ft_strncmp(w->type, "pl", 3))
	{
		pl = (t_plane *)w->object;
		pl->normal = rot_vect(pl->normal, M_PI / 180 * 15, 'z');
	}
	return (1);
}
