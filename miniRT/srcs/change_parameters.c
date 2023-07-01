/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:12:45 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 16:02:12 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	change_sphere_radius(int key_code, t_window *window)
{
	t_sphere	*sphere;

	if (!window->object || ft_strncmp(window->type, "sp", 3))
		return (0);
	sphere = (t_sphere *)window->object;
	if (key_code == KEY_D)
		sphere->radius2 = sphere->radius2 + 1.0;
	else if (key_code == KEY_S && sphere->radius2 > 2.0)
		sphere->radius2 = sphere->radius2 - 1.0;
	return (1);
}

int	change_cylinder_radius(int key_code, t_window *window)
{
	t_cylinder	*cylinder;

	if (!window->object || ft_strncmp(window->type, "cy", 3))
		return (0);
	if (key_code != KEY_D && key_code != KEY_S)
		return (0);
	cylinder = (t_cylinder *)window->object;
	if (key_code == KEY_D)
		cylinder->radius2 = cylinder->radius2 + 1.0;
	else if (key_code == KEY_S && cylinder->radius2 > 2.0)
		cylinder->radius2 = cylinder->radius2 - 1.0;
	return (1);
}

int	change_cylinder_height(int key_code, t_window *window)
{
	t_cylinder	*cylinder;

	if (!window->object || ft_strncmp(window->type, "cy", 3))
		return (0);
	if (key_code != KEY_E && key_code != KEY_W)
		return (0);
	cylinder = (t_cylinder *)window->object;
	if (key_code == KEY_E)
		cylinder->height = cylinder->height + 1.0;
	else if (key_code == KEY_W && cylinder->height > 2.0)
		cylinder->height = cylinder->height - 1.0;
	return (1);
}
