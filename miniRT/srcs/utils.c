/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:04:07 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 12:21:53 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	clear_matrix(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}

double	to_rad(const double angle)
{
	return (angle * M_PI / 180);
}

void	ft_put_pixel(unsigned char *data, const t_couple pixel, \
		const int color)
{
	int	(*tab)[RES_W][1];

	tab = (void *)data;
	*tab[pixel.h][pixel.w] = color;
}

int	ft_tab_size(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	print_err_and_exit(char *str, const int err)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(" (exit code: ", STDERR_FILENO);
	ft_putnbr_fd(err, STDERR_FILENO);
	ft_putstr_fd(")\n", STDERR_FILENO);
	exit(err);
}
