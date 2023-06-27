/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:19:31 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 17:28:26 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	rgb_to_int(const t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb	int_to_rgb(const int r, const int g, const int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb	char_to_rgb(const char *r, const char *g, const char *b)
{
	t_rgb	rgb;

	rgb.r = ft_atoi(r);
	rgb.g = ft_atoi(g);
	rgb.b = ft_atoi(b);
	return (rgb);
}

t_rgb	str_to_rgb(const char *str)
{
	t_rgb	rgb;
	char	**tab;

	tab = ft_split(str, ',');
	rgb = char_to_rgb(tab[0], tab[1], tab[2]);
	clear_matrix(tab);
	return (rgb);
}

t_rgb	dev_rgb_double(const t_rgb rgb, const double dev)
{
	return (int_to_rgb(rgb.r / dev, rgb.g / dev, rgb.b / dev));
}
