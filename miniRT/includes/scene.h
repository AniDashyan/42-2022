/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:04:10 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 12:02:43 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct s_scene
{
	t_couple		resolution;
	t_ambient_light	*al;
	t_camera		*camera;
	t_list			*lights;
	t_list			*spheres;
	t_list			*planes;
	t_list			*cylinders;
}					t_scene;

#endif
